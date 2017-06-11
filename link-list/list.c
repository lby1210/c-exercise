#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/* 函数实现*/

/* 用于文件函数ADD，将数据存入新节点*/
static void CopyToNode(Item item,Node *pnode)
{
	pnode->item = item;
}

/* 初始化链表 */
void InitList(List *plist)
{
	*plist = NULL;
}
 
/* 链表是否为空 */
bool ListIsEmpty(const List *plist)
{
	if(*plist==NULL)
		return true;
	else
		return false;
}

/* 链表是否为满*/
bool ListIsFull(const List* plist)
{
	Node *pnew;
	pnew = (Node*)malloc(sizeof(Node));
	if(pnew==NULL)
		return true;
	else
		return false; 
}

/* 链表计数*/
unsigned int ListCount(const List* plist)
{
	unsigned int count=0;
	Node *temp = *plist;
	while(temp!= NULL)
	{
		++count;
		temp = temp->next; 
	}
	return count;
}

/* 添加节点*/
bool AddItem(Item item,List *plist)
{	
	Node *temp;
	Node *pt = *plist;
	temp =(Node*)malloc(sizeof(Node)); 
	if(temp==NULL)
		return false;
	CopyToNode(item,temp);
	temp->next=NULL;
	if(pt==NULL)
	{
		*plist = temp;
	}	
	else
	{
		while(pt->next!=NULL)
		{
			pt=pt->next;
		}
		pt->next =temp;
	}
	return true;	 	
}

/* 每个节点运行函数*/

void Traverse(void(*pfun)(Item item),const List* plist)
{
	Node *pt = *plist;
	while(pt!=NULL)
	{
		(*pfun)(pt->item);
		pt =pt->next;
	}
}

/* 释放链表*/
void EmptyTheList(List* plist)
{
	Node *psave;
	while(*plist!=NULL)
	{
		psave =(*plist)->next;
		free(*plist);
		*plist =psave;
	}
}


//#include <stdio.h>
//#include <stdlib.h>
//#include "list.h"
//static void CopyToNode(Item item, Node * pnode) // 拷贝数据
//{
//    pnode->item = item;
//}
//void InitList(List * plist) // 初始化链表为空
//{
//    *plist = NULL;
//}
//
//bool ListisEmpty(const List * plist)  // 检查链表是否为空
//{
//    return *plist == NULL ? true : false;
//}
//bool ListisFull(const List * plist)  // 检查链表是否已满
//{
//    Node * pt;
//    pt = (Node *)malloc(sizeof(Node));
//    return pt == NULL ? true : false;
//}
//unsigned int ListItemCount(const List * plist)
//{
//    unsigned int count = 0;
//    Node * pnode = *plist;
//    while (pnode != NULL)
//    {
//        ++count;
//        pnode = pnode->next;
//    }
//    return count;
//}
//bool AddItem(Item item, List * plist) // 在链表结尾添加新的项
//{
//    Node * pnew; // 申请一个新的节点
//    Node * scan = *plist; 
//    pnew = (Node *)malloc(sizeof(Node)); // 给新节点申请空间 
//    if (pnew == NULL) return false; // 申请失败，返回false
//    CopyToNode(item, pnew); // 把item的内容复制到新节点中
//    pnew->next = NULL; // 将新节点的next指针设置为NULL，表示这一节点为当前的末尾项
//    if (scan == NULL) // 如果当前是空表，则将新节点设置为表的首项
//        *plist = pnew;
//    else
//    {
//        while (scan->next != NULL) //找到当前表中的末尾节点
//            scan = scan->next;
//        scan->next = pnew; //将新节点的地址保存在末尾节点的next成员里（即给链表添加了一个新的项）
//    }
//    return true;
//}
//void Traverse(const List * plist, void(*pfun)(Item item)) // 将某函数作用于链表的每一节点
//{
//    Node * pnode = *plist; // 将节点指向开头
//    while (pnode != NULL) 
//    {
//        (*pfun)(pnode->item); 
//        pnode = pnode->next;
//    }
//}
//void EmptyTheList(List * plist) // 清空链表
//{
//    Node * psave; // 用来保存当前清除项的下一节点的地址
//    while (*plist != NULL)
//    {
//        psave = (*plist)->next;
//        free(*plist);
//        *plist = psave;
//    }
//}
