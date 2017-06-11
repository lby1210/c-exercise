#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/* ����ʵ��*/

/* �����ļ�����ADD�������ݴ����½ڵ�*/
static void CopyToNode(Item item,Node *pnode)
{
	pnode->item = item;
}

/* ��ʼ������ */
void InitList(List *plist)
{
	*plist = NULL;
}
 
/* �����Ƿ�Ϊ�� */
bool ListIsEmpty(const List *plist)
{
	if(*plist==NULL)
		return true;
	else
		return false;
}

/* �����Ƿ�Ϊ��*/
bool ListIsFull(const List* plist)
{
	Node *pnew;
	pnew = (Node*)malloc(sizeof(Node));
	if(pnew==NULL)
		return true;
	else
		return false; 
}

/* �������*/
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

/* ��ӽڵ�*/
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

/* ÿ���ڵ����к���*/

void Traverse(void(*pfun)(Item item),const List* plist)
{
	Node *pt = *plist;
	while(pt!=NULL)
	{
		(*pfun)(pt->item);
		pt =pt->next;
	}
}

/* �ͷ�����*/
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
//static void CopyToNode(Item item, Node * pnode) // ��������
//{
//    pnode->item = item;
//}
//void InitList(List * plist) // ��ʼ������Ϊ��
//{
//    *plist = NULL;
//}
//
//bool ListisEmpty(const List * plist)  // ��������Ƿ�Ϊ��
//{
//    return *plist == NULL ? true : false;
//}
//bool ListisFull(const List * plist)  // ��������Ƿ�����
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
//bool AddItem(Item item, List * plist) // �������β����µ���
//{
//    Node * pnew; // ����һ���µĽڵ�
//    Node * scan = *plist; 
//    pnew = (Node *)malloc(sizeof(Node)); // ���½ڵ�����ռ� 
//    if (pnew == NULL) return false; // ����ʧ�ܣ�����false
//    CopyToNode(item, pnew); // ��item�����ݸ��Ƶ��½ڵ���
//    pnew->next = NULL; // ���½ڵ��nextָ������ΪNULL����ʾ��һ�ڵ�Ϊ��ǰ��ĩβ��
//    if (scan == NULL) // �����ǰ�ǿձ����½ڵ�����Ϊ�������
//        *plist = pnew;
//    else
//    {
//        while (scan->next != NULL) //�ҵ���ǰ���е�ĩβ�ڵ�
//            scan = scan->next;
//        scan->next = pnew; //���½ڵ�ĵ�ַ������ĩβ�ڵ��next��Ա��������������һ���µ��
//    }
//    return true;
//}
//void Traverse(const List * plist, void(*pfun)(Item item)) // ��ĳ���������������ÿһ�ڵ�
//{
//    Node * pnode = *plist; // ���ڵ�ָ��ͷ
//    while (pnode != NULL) 
//    {
//        (*pfun)(pnode->item); 
//        pnode = pnode->next;
//    }
//}
//void EmptyTheList(List * plist) // �������
//{
//    Node * psave; // �������浱ǰ��������һ�ڵ�ĵ�ַ
//    while (*plist != NULL)
//    {
//        psave = (*plist)->next;
//        free(*plist);
//        *plist = psave;
//    }
//}
