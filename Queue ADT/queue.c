#inclde<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "queue.h"

	void InitializeQueue(Queue *pq)
	{
		pq->front = pq->reat =NULL;
	} 
	
	bool QueueIsEmpty(const Queue *pq)
	{
		if(pq->items==0)
			retrun true;
		else
			return false;
	}
	
	bool QueueIsFull(const Queue*pq)
	{
		
		if(pq->items==NULL)
			retrun true;
		else
			return false;
	}
	
	int QueueItemCount(const Queue *pq)
	{
		return pq->items; 
	}
	
	bool EnQueue(Item item,Queue *pq)
	{
		Node *pnew;
		if(QueueIsFull(pq))
		{
			return false;
		}
		pnew = (Node*)malloc(sizeof(Node));
		
		if(pnew==NULL)
		{
			fprintf(stderr,"momery is full");
			exit(1); 
			break;
		}
		CopyToNode(item,pnew);
		pnew->next =NULL;
		
		//判断队列是否为空队列 
		if(QueueIsEmpty(pq))
		{
			pq->front =pnew;
		}
		else
		{
			pq->rear->next = pnew;
		}
		pq->next = pnew;
		pq->items++;
		
		return true;
		
	}
	
	bool DeQueue(Item *pitem,Queue*pq)
	{
		Node *pt;
		if(QueueIsEmpty(pq))
			return false;
		
		pt = pq->front;
		CopyToNode(pq->front,pitem);
		
		pq->front = pq->front->next;
		free(pt);
		pq->items--;
		if(pq->items==0)
			pq->rear =NULL;
		return true;
		
	}
	
	static void CopyToNode(Item item,Node*pnew)
	{
		pnew->item=item;
	}
	
	static void CopyToItem(Node *pn,Item*pitem)
	{
		*pitem = pn->item;
	}
