#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>
#define MAXSIZE 5
typedef int ElemType;

typedef struct arraylist
{
	ElemType data[MAXSIZE];
	int length;
}ArrayList;

ArrayList *InitArrayList();

void DeleteArrayList(ArrayList *list);

void ClearArrayList(ArrayList *list);

bool Is_Empty(ArrayList *list);

int ArrayLength(ArrayList *list);

bool GetElem(ArrayList *list, int index,ElemType *e);

int FindElem(ArrayList *list, ElemType e);

void Printf_Array(ArrayList *L);

void InsertElem(ElemType x, int index, ArrayList *L);

void DeleteElem(ArrayList *list,int index);




#endif