#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/* ����ʵ��*/

/* �����ļ�����ADD�������ݴ����½ڵ�*/
static void CopyToNode(Item item,Node *pnode)
{
	pnode->item = item;
}

/* ��ʼ������ */
void InitList(List *plist)
{
	*plist = NULL;
}
 
/* �����Ƿ�Ϊ�� */
bool ListIsEmpty(const List *plist)
{
	if(*plist==NULL)
		return true;
	else
		return false;
}

/* �����Ƿ�Ϊ��*/
bool ListIsFull(const List* plist)
{
	Node *pnew;
	pnew = (Node*)malloc(sizeof(Node));
	if(pnew==NULL)
		return true;
	else
		return false; 
}

/* �������*/
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

/* ��ӽڵ�*/
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

/* ÿ���ڵ����к���*/

void Traverse(void(*pfun)(Item item),const List* plist)
{
	Node *pt = *plist;
	while(pt!=NULL)
	{
		(*pfun)(pt->item);
		pt =pt->next;
	}
}

/* �ͷ�����*/
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


