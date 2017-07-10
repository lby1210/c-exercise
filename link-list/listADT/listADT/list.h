#ifndef LIST_H_
#define LIST_H_
#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node *ptrNode;

typedef ptrNode List;
typedef ptrNode Position;
typedef int ElemType;

List Init_List(void);

void Insert(ElemType x, Position p, List L);

void Delete(ElemType x, Position p, List L);

Position Find(ElemType x, List L);

Position FindPrevious(ElemType x, List L);

void addNode(ElemType x, List L);

int IsEmpty(List L);

//int IsLast(List L);

void printfList(List L);

void DestoryList(List L);


struct Node {
	ElemType data;
	struct Node *next;
	
};



#endif