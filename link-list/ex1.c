#include<stdio.h>
#include<stdlib.h> 
typedef int ElemType;
typedef struct node Node;
typedef Node* ptrToNode;
typedef ptrToNode List;
typedef ptrToNode Position;

List CreatList();
void addNode(ElemType x,List L);
void Printf_List(List L);

int main()
{
	List L;
	L =CreatList();
	addNode(2,L);
	addNode(3,L);
	
	Printf_List(L);
	return 0;
}

typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node *next;
}Node;

typedef Node* ptrToNode;

typedef ptrToNode List;
typedef ptrToNode Position;

List CreatList()
{
	List l;
	l =malloc(sizeof(struct node));
	l->next =NULL;
	return l;
}

void addNode(ElemType x,List L)
{
	
	Position p,q;
	p=L;
	while(p->next!=NULL)
	{
		p = p->next;
	}
	q =malloc(sizeof(struct node));
	q->data =x;
	q-> next =NULL;
	p->	next =q; 
}

void Printf_List(List L)
{
	Position p;
	p= L->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p =p->next;
	}
}
