#include<stdio.h>

int main()
{
	struct node{
		int a;
		int b;
	}Node;
	

	printf("%d ",sizeof(struct node));
	printf("%d",sizeof(Node));
}
