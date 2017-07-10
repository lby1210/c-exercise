#include<stdio.h>
#include"list.h"

int main()
{
	List L;
	L = Init_List();
	addNode(1, L);
	addNode(2, L);
	addNode(3, L);
	Insert(4, FindPrevious(3, L), L);
	printfList(L);
	getchar();
	return 0;
}