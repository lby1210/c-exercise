#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"arrayList.h"

int main()
{
	ArrayList *L;
	L =InitArrayList();
	L->data[0] = 1;
	L->length++;
	L->data[1] = 2;
	L->length++;
	InsertElem(3, 1, L);
	DeleteElem(L, 1);
	Printf_Array(L);
	getchar();
	return 0;
}