/* linklist 线性结构中的顺序结构 的基本操作集合
	12种操作	
*/

/* 	1.初始化 InitList(&List L)
	2.销毁一个线性结构 DelectList(List L)
	3.把结构中的数据清空 ClearList(List L)
	4.是否为空 ListIsEmpty(List L)
	5.结构长度 ListLength(List L)]
	6.取出第i个元素，取出的元素放在e里 GetElem(const List L,int i,&Elem e)
	7.求一个元素的前驱 (用的不多) 
	8.求一个元素的后继 (用的不多) 
	9.将一个元素 插入位置i中 ListInsert(&List L,int i,Elem e)
	10.将指定位置的一个元素删除ListDelect(&List L,int i,&Elem e)
	11.线性结构的遍历 ListTraversal(List L)
	12.在线性结构中查找有没有这个元素 FindElem(List l,Elem e)
*/
	#define MAXSIZE 20
	typedef struct elem{
		int i;
	}Elem;
	
	typedef struct {
		Elem a [MAXSIZE];
		int ListSize;
		int FactSize;           //实际存储 
	}List;
	
	void InitList(&List L)
	{
		L.ListSize =MAXSIZE;
		L.FactSize =0;
	}
	
	void DeleteList(&List L)
	{
		L.ListSize = 0;
		L.FactSize = 0;
	}
	
	void ClearList(&List L)
	{
		L.FactSize = 0;
	} 
	
	bool ListIsEmpty(List L)
	{
		if(L.FactSize==0)
			return true;
		else
			return false;
	}
	
	Elem GetElem(List L,int i,Elem &e)
	{
		return e = a[i];
	}
	
	int ListLength(List L)
	{
		return L.FactSize;
	}
	
	bool FindElem(List L,Elem e)
	{
		for(i=0;i<ListLength(L);i++)
		{
			if(a[i]==e)
				return true;
		}
		
		return false;
	}
	
	void proElem(List &L,Elem now,Elem &pro)
	{
		temp =-2;
		for(i=0; i<ListLength(L),i++)
		{
			if(L.a[i]==now)
			{
				if(i==0)
					pro = NULL;
					temp = -1;
				else
					pro =a[i-1];
					temp = -1;
			} 
		}
			if(temp == -2)
			{
				pro =NULL;
			}
	}
	
	
	ListDelect(List &L,int i,Elem &e)
	{
		e =L.a[i];
		for(j=i;j<ListLength(L);j++)
		{
			a[j] = a[j+1];
		}
		a[ListLengtj(L)]=NULL; 
	} 
	
	ListInsert(List &L,int i,Elem &e)
	{
		//判断i是否在上限或下限
		//判断表是否为空
		
		for(j=length(L);j>i;j++)
		{
			L.a[j+1] = L.a[j];
		} 
		
		L.a[i] = *e;
	}	
