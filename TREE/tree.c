#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "tree.h" 
void Initialize(Tree* ptree)
{
	ptree->root =NULL;
	ptree->size =0;
}

void TreeIsEmpty(const Tree* ptree)
{
	if(pree->root == NULL)
		return true;
	else
		return false;
}

void TreeIsFull(const Tree*ptree)
{
	if(ptree->size == MAXSIZE)
		return true;
	else
		return false;
}

int TreeItemCount(const Tree*ptree)
{
	return ptree->size;	
} 

bool AddItem(const Item *pi,Tree *ptree)
{
	Tnode *newNode;
	
	if(TreeIsFULL(ptree))
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

static Tnode *MakeNode(Item *pi)
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
