#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"arraylist.h"

ArrayList *InitArrayList()
{
	ArrayList *L;
	L = (ArrayList *)malloc(sizeof(struct arraylist));
	L->length = 0;

	return L;
}


void ClearArrayList(ArrayList *list)
{
	list->length = 0;
}

bool Is_Empty(ArrayList *list)
{
	if (list->length)
		return true;
	else
		return false;
}

int ArrayLength(ArrayList *list)
{
	return list->length;
}



void Printf_Array(ArrayList *L)
{
	int i;
	for (i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
}


void InsertElem(ElemType x, int index, ArrayList *L)
{
	if (L->length == MAXSIZE)
	{
		printf("表满");
		exit(-1);
	}

	if (index < 1 || index > MAXSIZE)
	{
		printf("位置不合法");
		exit(-1);
	}
	
	int i;
	for (i = L->length - 1; i > index - 2; i--)
	{
		L->data[i + 1] = L->data[i];
	}
	L->data[index-1] = x;
	L->length++;
}

void DeleteElem(ArrayList *list, int index)
{
	if (list->length == 0)
	{
		printf("表空");
		exit(-1);
	}
	
	if (index < 1 || index > MAXSIZE)
	{
		printf("位置不合法");
		exit(-1);
	}

	int i;
	for (i = index - 1; i < list->length; i++)
	{
		list->data[i] = list->data[i + 1];
	}
	list->length--;
}