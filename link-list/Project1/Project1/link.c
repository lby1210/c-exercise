#include<stdio.h>
#include<stdlib.h>
#include "link.h"

List CreateList()
{
	List phead;
	phead = (List)malloc(sizeof(Node));
	phead->Next = NULL;
	return phead;
}

 Node* CreateNode()
{
	Node *p=NULL;
	p = (Node*)malloc(sizeof(Node));
	p->Next = NULL;
	return p;
}

Node* Find_Item(ElemType x, List L)
{
	List p = L;
	while (p != NULL || p->data != x)
	{
		p = p->Next;
	}
	return p;
}

Node* Find_kth(int i,List L)
{
	int count = 1;
	Node *p = L;
	while (p!=NULL && count<i)
	{
		p = p->Next;
		count++;
	}
	if (count == i)
		return p;
	else
		return NULL;
}

int IsEmpty(List L)
{
	if (L->Next == NULL)
		return 0;
	else
		return 1;
}

int Length(List L)
{
	int count = 0;
	List p = L;
	while (p->Next!= NULL)
	{
		p=p->Next;
		count++;
	}
	return count;
}

List Insert_Item(ElemType x, int i,List L)
{
	Node*p;
	Node *newNode;
	newNode = CreateNode();
	newNode->data = x;
	if (i == 1)
	{
		newNode->Next = L->Next;
		L->Next = newNode;
		return L;
	}

	p = Find_kth(i - 1, L);

	if (p==NULL)
	{
		printf("不存在");
		return L;
	}
	else
	{
		newNode->Next = p->Next;
		p->Next = newNode;
		return L;
	}


	

}

void Delete_Item(int i, List L)
{
	List p,s;
	if (i == 1)
	{
		s = L;
		if (s != NULL)
		{
			s = s->Next;
		}
		else
			return NULL;
		free(s);
	}

	p = Find_kth(i - 1, L);
	s = p->Next;
	if (p == NULL)
	{
		printf("第%d个结点不存在", i - 1);
	}
	else if (s == NULL)
	{
		printf("第%d个节点不存在");
	}
	else
	{
		 p->Next=s->Next;
		 free(s);
	}

}