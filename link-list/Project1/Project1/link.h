#ifndef LIST_H_
#define LIST_H_
		
	
	typedef int ElemType;
	//����ͨ����������ElemType 

    typedef struct node{
		ElemType data;
		Node*Next;
	}Node;
	//����node�ṹ

	typedef struct Node* ToNode;   //����ָ��node��ָ�� ���������ͷ�ڵ�
	typedef ToNode List;
	List CreateList();   //�������� ����ͷ���

    Node* CreateNode();  //�����ڵ�

	int IsEmpty(List L); //�ж������Ƿ�Ϊ������

	int Length(List L); //����ĳ���

	List Insert_Item(ElemType x,int i,List L);  //����һ������

	void Delete_Item(int i, List L);  //ɾ��һ������

	Node *Find_Item(ElemType x, List L); //�������ݲ������ڵ�λ��  ��������Ӧ����ָ��

	Node *Find_kth(int i,List L); //���ݵڼ����������ݣ����ص�ǰ���.


#endif


	




