#ifndef LIST_H_ 
#define LIST_H_ 
#include <stdbool.h>
#define TSIZE 45 
/************** ���ݽṹ***********/
typedef struct film
{
	char title[TSIZE];
	int rating;
}Item;




/************* ���ṹ************/
typedef struct node
{
	Item item;
	struct node* next;
}Node;

typedef Node * List;

/************* ��������*********/

/* ��ʼ������*/
void InitList(List *plist);

/* �����Ƿ�Ϊ��*/
bool ListIsEmpty(const List* plist);

/* �����Ƿ��� */
bool ListIsFull(const List* plist);

/* ��ѯ��������*/ 
unsigned int ListCount(const List* plist);

/* ������ݵ�����*/

bool AddItem(Item item,List *plist);

/* Ϊ����ÿ���ڵ�ִ�к���*/
 
void Traverse(void(*pfun)(Item item),const List* plist);

/* �ͷ�����*/
void EmptyTheList(List* plist);

#endif


