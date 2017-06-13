#include <stdio.h>
#include "queue.h"

int main(void)
{
	Queue line;
	Item temp;
	char ch;
	
	InitializeQueue(&line);
	puts("Testing the Queue interface.Type a to add a value");
	puts("Type d delete the value");
	while((ch=getchar())!='q')
	{
		if(ch!='a' && ch!='d')
			continue;
		if(ch=='a')
		{
			printf("Inter number to add");
			scanf_s("%d",&temp);
			if(QueueIsFull(&line))
			{
				printf("Queue is full");
			}
			else{
				printf("putting %d into queue\n",temp);
				EnQueue(temp,&line);		
			}				
		}
		else
		{
			if(QueueIsEmpty(&line))        //原来忘记写函数后面的括号 
			{
				printf("nothing to delete");
			}
			else
			{
				DeQueue(&temp,&line);
				printf("romving %d from queue\n",temp);
			}
		} 
		printf("%d items in queue",QueueItemCount(&line));
		puts("type a to add,type d to delete,q to quit");			
	} 
	EmptyTheQueue(&line); 
	puts("done"); 
	return 0;
} 
