#include<stdio.h>
#include<stdlib.h>
#include"link.h"

int main()
{
	List phead;
	Node *p;
	int a,i=0;
	phead =CreateList();

	while (scanf("%d",&a)!=EOF)
	{
		Insert_Item(a,i,phead);
		i++;
	}
	p = phead->Next;
	while (p != NULL)
	{
		printf("%d ",p->data);
	}
	return 0;
}