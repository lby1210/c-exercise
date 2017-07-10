#ifndef LIST_H_
#define LIST_H_
		
	
	typedef int ElemType;
	//建立通用数据类型ElemType 

    typedef struct node{
		ElemType data;
		Node*Next;
	}Node;
	//建立node结构

	typedef struct Node* ToNode;   //建立指向node的指针 代表链表的头节点
	typedef ToNode List;
	List CreateList();   //创建链表 创建头结点

    Node* CreateNode();  //创建节点

	int IsEmpty(List L); //判断链表是否为空链表

	int Length(List L); //链表的长度

	List Insert_Item(ElemType x,int i,List L);  //插入一个数据

	void Delete_Item(int i, List L);  //删除一个数据

	Node *Find_Item(ElemType x, List L); //根据数据查找所在的位置  返回所对应结点的指针

	Node *Find_kth(int i,List L); //根据第几个查找数据，返回当前结点.


#endif


	




