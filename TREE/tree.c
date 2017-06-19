#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "tree.h" 
/* 函数定义部分*/



/* 函数实现*/

   /* 初始化树*/
void Initialize(Tree* ptree)
{
	ptree->root =NULL;
	ptree->size =0;
}
	
   /* 判断树是否是空的*/	
void TreeIsEmpty(const Tree* ptree)
{
	if(pree->root == NULL)
		return true;
	else
		return false;
}

	/* 判断树是否是满的*/
void TreeIsFull(const Tree*ptree)
{
	if(ptree->size == MAXSIZE)
		return true;
	else
		return false;
}

	/* 树有多少项*/
int TreeItemCount(const Tree*ptree)
{
	return ptree->size;	
} 

	/* 向树中添加项*/
bool AddItem(const Item *pi,Tree *ptree)
{
	Tnode *newNode;
	
	if(TreeIsFULL(ptree))        //判断树是够为满， 满返回错误 无法添加 
	{
		fprintf(stderr,"Tree is Full\n");
		return false;
	} 
	
	if(SeekItem(pi,ptree).child !=NULL)  //查找函数SeekItem   目的为了查重 
	{
		fprintf(stderr,"attempted to add duplicate item")
	}
	newNode = MakeNode(pi);
	
	ptree->size++;
	if(ptree->root ==NULL)
	{
		ptree = newNode;
	}
	else
	{
		AddNode(newNode,ptree->root);
	}
	return true;
}

/* 公共接口 查询是否有相同项*/
bool InTree(const Item* pi,const Tree* ptree)
{
	return (SeekItem(pi,ptree).child ==NULL) ? false : true;
}

/* 本文件私有函数*/

/*              制造节点*/
static Tnode *MakeNode(const Item *pi)    
{
	newNode = (Tnode)malloc(sizeof(Tnode));
	
	if(newNode !=NULL)
	{
		newNode->item = *pi;
		newNode->lift =NULL;
		newNode->right =NULL;
		
		return newNode; 
	}
} 
/*   添加节点*/
static void AddNode(Tnode *new_node,Tnode *root)
{
	if(ToLeft(&new_node->item,&root->item))
	{
		if(root->left==NULL)
			root->left =newnode;
		else
			AddNode(new_node,root->left);
	}
	else if(ToRight(&new_node->item,&root->item))
	{
		if(root->right==NULL)
			root->right = new_node;
		else
			AddNode(new_node,root->right); 
	}
	else 
	{
		fprintf(stderr,"error");
		exit(1);
	}
} 


/*  新加节点在左树找位置时*/
static void Toleft(Item *pi,Item *pr)
{
	int comp;
	if(comp = strcmp(pi->petname,pr->petname)<0)
		 return true;
	else if(comp==0 && strcmp(comp = strcmp(pi->petkind,pr->petkind))<0 )
		 return true;
	else 
		return false;
}

/* 在右树*/
static void Toright(Item *pi,Item *pr)
{
	int comp;
	if(comp = strcmp(pi->petname,pr->petname)>0)
		 return true;
	else if(comp==0 && strcmp(comp = strcmp(pi->petkind,pr->petkind))>0 )
		 return true;
	else 
		return false;
}

/* 查找是否有相同项*/
static Pair SeekItem(const Item*pi,const Tree* ptree)   
{
	Pair look;
	look.parents = NULL;              //根节点没有父节点  所以父节点为空 
	look.child = ptree->root;
	
	if(look.child = NULL)
	{
		return look;
	}
	
	while(look.child !=NULL)
	{
		if(Toleft(pi,&look.child->item))
		{
			look.parents = look.child;
			look.child = look.child->left;
		}
		else if(Toright(pi,&look.child->item))
		{
			look.parents = look.child;
			look.child = look.child->right;
		}
		else
		{
			break;
		}		
	}
	
	return look;
}
