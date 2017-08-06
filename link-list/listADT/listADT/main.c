#include<stdio.h>
#include"list.h"

void Print_Lots(List L, List M);
int main()
{
	List L,M;
	L = Init_List();
	M = Init_List();
	addNode(1, L);
	addNode(2, L);
	addNode(3, L);
	addNode(2, M);
	addNode(3, M);
	Print_Lots(L, M);
	getchar();
	return 0;
}

void Print_Lots(List L, List M)
{
	int count = 0;
	int i;
	Position p,q;
	q = M->next;
	p = L->next;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	p = L->next;
	while (q != NULL)
	{
		//if (q->data > count)
		//	printf("Ô½½ç");
		//else
		{
			for (i = 1; i < q->data; i++)
			{
				p = p->next;
			}
			printf("%d ", p->data);
		}
		p = L->next;
		q = q->next;
	}

}