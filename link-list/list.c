#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/* 函数实现*/

/* 用于文件函数ADD，将数据存入新节点*/
static void CopyToNode(Item item,Node *pnode)
{
	pnode->item = item;
}

/* 初始化链表 */
void InitList(List *plist)
{
	*plist = NULL;
}
 
/* 链表是否为空 */
bool ListIsEmpty(const List *plist)
{
	if(*plist==NULL)
		return true;
	else
		return false;
}

/* 链表是否为满*/
bool ListIsFull(const List* plist)
{
	Node *pnew;
	pnew = (Node*)malloc(sizeof(Node));
	if(pnew==NULL)
		return true;
	else
		return false; 
}

/* 链表计数*/
unsigned int ListCount(const List* plist)
{
	unsigned int count=0;
	Node *temp = *plist;
	while(temp!= NULL)
	{
		++count;
		temp = temp->next; 
	}
	return count;
}

/* 添加节点*/
bool AddItem(Item item,List *plist)
{	
	Node *temp;
	Node *pt = *plist;
	temp =(Node*)malloc(sizeof(Node)); 
	if(temp==NULL)
		return false;
	CopyToNode(item,temp);
	temp->next=NULL;
	if(pt==NULL)
	{
		*plist = temp;
	}	
	else
	{
		while(pt->next!=NULL)
		{
			pt=pt->next;
		}
		pt->next =temp;
	}
	return true;	 	
}

/* 每个节点运行函数*/

void Traverse(void(*pfun)(Item item),const List* plist)
{
	Node *pt = *plist;
	while(pt!=NULL)
	{
		(*pfun)(pt->item);
		pt =pt->next;
	}
}

/* 释放链表*/
void EmptyTheList(List* plist)
{
	Node *psave;
	while(*plist!=NULL)
	{
		psave =(*plist)->next;
		free(*plist);
		*plist =psave;
	}
}


