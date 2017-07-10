/* linklist ���Խṹ�е�˳��ṹ �Ļ�����������
	12�ֲ���	
*/

/* 	1.��ʼ�� InitList(&List L)
	2.����һ�����Խṹ DelectList(List L)
	3.�ѽṹ�е�������� ClearList(List L)
	4.�Ƿ�Ϊ�� ListIsEmpty(List L)
	5.�ṹ���� ListLength(List L)]
	6.ȡ����i��Ԫ�أ�ȡ����Ԫ�ط���e�� GetElem(const List L,int i,&Elem e)
	7.��һ��Ԫ�ص�ǰ�� (�õĲ���) 
	8.��һ��Ԫ�صĺ�� (�õĲ���) 
	9.��һ��Ԫ�� ����λ��i�� ListInsert(&List L,int i,Elem e)
	10.��ָ��λ�õ�һ��Ԫ��ɾ��ListDelect(&List L,int i,&Elem e)
	11.���Խṹ�ı��� ListTraversal(List L)
	12.�����Խṹ�в�����û�����Ԫ�� FindElem(List l,Elem e)
*/
	#define MAXSIZE 20
	typedef struct elem{
		int i;
	}Elem;
	
	typedef struct {
		Elem a [MAXSIZE];
		int ListSize;
		int FactSize;           //ʵ�ʴ洢 
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
		//�ж�i�Ƿ������޻�����
		//�жϱ��Ƿ�Ϊ��
		
		for(j=length(L);j>i;j++)
		{
			L.a[j+1] = L.a[j];
		} 
		
		L.a[i] = *e;
	}	
