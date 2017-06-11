#ifndef LIST_H_ 
#define LIST_H_ 
#include <stdbool.h>
#define TSIZE 45 
/************** 数据结构***********/
typedef struct film
{
	char title[TSIZE];
	int rating;
}Item;




/************* 结点结构************/
typedef struct node
{
	Item item;
	struct node* next;
}Node;

typedef Node * List;

/************* 声明函数*********/

/* 初始化链表*/
void InitList(List *plist);

/* 链表是否为空*/
bool ListIsEmpty(const List* plist);

/* 链表是否满 */
bool ListIsFull(const List* plist);

/* 查询链表项数*/ 
unsigned int ListCount(const List* plist);

/* 添加数据到链表*/

bool AddItem(Item item,List *plist);

/* 为链表每个节点执行函数*/
 
void Traverse(void(*pfun)(Item item),const List* plist);

/* 释放链表*/
void EmptyTheList(List* plist);

#endif

//#ifndef LIST_H_
//#define LIST_H_
//#include <stdbool.h>
//#define TSIZE 45
//
//typedef struct book{ // 建立包含元素属性的item结构体
//    char title[TSIZE];
//    int rating;
//}Item;
//
//typedef struct node { // 链表的节点，包含item各项属性以及一个用来存放下一项地址的指针（链表链接的关键）
//    Item item;
//    struct node*next;
//}Node;
//typedef Node * List; 
//
//void InitList(List * plist);
//bool ListisEmpty(const List * plist);
//bool ListisFull(const List * plist);
//unsigned int ListItemCount(const List * plist);
//bool AddItem(Item item, List * plist);
//void Traverse(const List * plist, void(*pfun)(Item item));
//void EmptyTheList(List * plist);
//
//#endif 
