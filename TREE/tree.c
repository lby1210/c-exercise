#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "tree.h" 
/* �������岿��*/



/* ����ʵ��*/

   /* ��ʼ����*/
void Initialize(Tree* ptree)
{
	ptree->root =NULL;
	ptree->size =0;
}
	
   /* �ж����Ƿ��ǿյ�*/	
void TreeIsEmpty(const Tree* ptree)
{
	if(pree->root == NULL)
		return true;
	else
		return false;
}

	/* �ж����Ƿ�������*/
void TreeIsFull(const Tree*ptree)
{
	if(ptree->size == MAXSIZE)
		return true;
	else
		return false;
}

	/* ���ж�����*/
int TreeItemCount(const Tree*ptree)
{
	return ptree->size;	
} 

	/* �����������*/
bool AddItem(const Item *pi,Tree *ptree)
{
	Tnode *newNode;
	
	if(TreeIsFULL(ptree))        //�ж����ǹ�Ϊ���� �����ش��� �޷���� 
	{
		fprintf(stderr,"Tree is Full\n");
		return false;
	} 
	
	if(SeekItem(pi,ptree).child !=NULL)  //���Һ���SeekItem   Ŀ��Ϊ�˲��� 
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

/* �����ӿ� ��ѯ�Ƿ�����ͬ��*/
bool InTree(const Item* pi,const Tree* ptree)
{
	return (SeekItem(pi,ptree).child ==NULL) ? false : true;
}

/* ���ļ�˽�к���*/

/*              ����ڵ�*/
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
/*   ��ӽڵ�*/
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


/*  �¼ӽڵ���������λ��ʱ*/
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

/* ������*/
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

/* �����Ƿ�����ͬ��*/
static Pair SeekItem(const Item*pi,const Tree* ptree)   
{
	Pair look;
	look.parents = NULL;              //���ڵ�û�и��ڵ�  ���Ը��ڵ�Ϊ�� 
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
