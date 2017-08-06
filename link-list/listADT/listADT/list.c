#include "list.h"

List Init_List(void)
{
	List head;
	head = (List)malloc(sizeof(struct Node));
	head->next = NULL;
	head->prior = NULL;
	return head;
}

void Insert(ElemType x, Position p, List L)
{
		Position tmp;
		tmp = malloc(sizeof(struct Node));
		tmp->data = x;
		tmp->next = p;
		tmp->prior = p->prior;
		p->prior->next = tmp;
		p->prior = tmp;	
}

void Delete(ElemType x,Position p, List L)
{
	Position tmpCell;
	tmpCell = p;
	if (L->next == NULL) {
		printf("表为空");
		exit(1);
	}	
	if (p->prior != NULL)
		p->prior->next = p->next;
	if(p->next!=NULL)
		p->next->prior = p;
	free(tmpCell);

}

Position Find(ElemType x, List L)
{
	Position tmp = L->next;
	while (tmp!=NULL && tmp->data !=x )
	{
		tmp = tmp->next;
	}

	return tmp;
}

Position FindPrevious(ElemType x, List L)
{
	Position p;
	if (L->next == NULL)
	{
		printf("表为空");
		exit(1);
	}
	else
	{
		p = L->next;
		while (p->next != NULL && p->next->data != x)
			p = p->next;
		
		if (p->next == NULL)
		{
			printf("没有找到前驱结点");
			return NULL;
		}
		else
			return p->prior;
	}
}

void addNode(ElemType x, List L)
{
	Position p,tmp;
	p = malloc(sizeof(struct Node));
	p->data = x;
	p->next = NULL;
	p->prior = NULL;
	
	tmp = L;
	while (tmp ->next!= NULL)
		tmp= tmp->next;
	tmp->next = p;
	p->prior = tmp;
}

int IsEmpty(List L)
{
	if (L->next == NULL)
		return 1;
	else
		return 0;
}

void printfList(List L)
{
	Position p;
	p = L->next;
	while (p != NULL)
	{
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("NULL");
}

void DestoryList(List L)
{
	Position p,q;
	p = L->next;
	while (p != NULL)
	{
		p->prior->next = p->next;
		p->next->prior = p->prior;
		q = p;
		p = p->next;
		free(q);
	}
}
