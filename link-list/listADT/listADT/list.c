#include "list.h"

List Init_List(void)
{
	List head;
	head = (List)malloc(sizeof(struct Node));
	head->next = NULL;
	return head;
}

void Insert(ElemType x, Position p, List L)
{
	if (p != NULL)
	{
		Position tmp;
		tmp = malloc(sizeof(struct Node));
		tmp->data = x;
		tmp->next = p->next;
		p->next = tmp;
	}
	else
		printf("不存在结点");	
}

void Delete(ElemType x,Position p, List L)
{
	Position tmpCell;
	if (L->next == NULL) {
		printf("表为空");
		exit(1);
	}	

	tmpCell = p->next;
	p->next = tmpCell->next;
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
			return p;
	}
}

void addNode(ElemType x, List L)
{
	Position p,tmp;
	p = malloc(sizeof(struct Node));
	p->data = x;
	p->next = NULL;
	
	tmp = L;
	while (tmp ->next!= NULL)
		tmp= tmp->next;
	tmp->next = p;
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
	p = L;
	q = p->next;
	while (p != NULL)
	{
		p->next = q->next;
		free(q);
		q = p->next;
	}
}
