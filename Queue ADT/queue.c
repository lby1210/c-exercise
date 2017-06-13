#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

	static void CopyToNode(Item item,Node*pnew);
	static void CopyToItem(Node *pn,Item*pitem);
	
	void InitializeQueue(Queue *pq)
	{
		pq->front = pq->rear =NULL;
		pq->items=0;   //忘记写了 
	} 
	
	bool QueueIsEmpty(const Queue *pq)
	{
		return pq->items==0;
	}
	
	bool QueueIsFull(const Queue*pq)
	{	
		return pq->items==MAXQUEUE;		
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
			fprintf(stderr,"momery is full\n");
			exit(EXIT_FAILURE); 
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
		pq->rear = pnew;
		pq->items++;
		
		return true;
		
	}
	
	bool DeQueue(Item *pitem,Queue*pq)
	{
		Node *pt;
		if(QueueIsEmpty(pq))
			return false;
		
		
		CopyToItem(pq->front,pitem);           //原来 这行与下行相反 
		pt = pq->front;
		pq->front = pq->front->next;
		free(pt);
		pq->items--;
		if(pq->items==0)
			pq->rear =NULL;
		return true;
		
	}
	
	void EmptyTheQueue(Queue *pq)
	{
		Item dummy;
		while(!QueueIsEmpty(pq))
			DeQueue(&dummy,pq);
	}
	
	
	static void CopyToNode(Item item,Node*pn)
	{
		pn->item=item;
	}
	
	static void CopyToItem(Node *pn,Item*pi)
	{
		*pi = pn->item;
	}
