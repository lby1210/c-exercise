#include<stdio.h>
#include<stdlib.h>
//���ṹ�嶨��
typedef struct lnode{
	int data;
    struct LNode *next;
}LNode,LinkList;

void main()
{//��������
 void creat_list(LinkList &L,int n);
 void merge_list(LinkList &La,LinkList &Lb,LinkList &Lc);
 void print_list(LinkList L);
 //��������ʼ
 int n1,n2;
 LinkList La,Lb,Lc;
 printf("����La����ʼ:��������Ҫ�����Ľ�����\n");
 scanf("%d",&n1);
 creat_list(La,n1);
 printf("La������Ϣ����:\n");
 print_list(La);
 printf("����Lb����ʼ:��������Ҫ�����Ľ�����\n");
 scanf("%d",&n2);
 creat_list(Lb,n2);
 printf("Lb������Ϣ����:\n");
 print_list(Lb);
 printf("�ϲ��������������:\n");
 merge_list(La,Lb,Lc);
 print_list(Lc);
}
void creat_list(LinkList &L,int n)
{   int i;
	LinkList p,q;
	L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;//����ͷ���
    q=L;
	for (i=1;i<=n;i++)
	{p=(LinkList)malloc(sizeof(LNode));
	printf("�������%d���ڵ������:",i);
	scanf("%d",&p->data);
	q->next=p;
	q=q->next;//q����
	}
	p->next=NULL;//���һ���ڵ���β���
}
 void merge_list(LinkList &La,LinkList &Lb,LinkList &Lc)
 {LinkList pa,pb,pc;
  pa=La->next;pb=Lb->next;//a��b�����ָ���Լ��ĵ�һ�����
  pc=Lc=La;//Lc������ʼ���վ�û�н�������ʵ����LC���ǽ���ָ��ȥ����la��lb�еĽ��
  while(pa&&pb)//��ָ��ĩβ
  {
	  if (pa->data<=pb->data)//����La
	  {pc->next=pa;
	   pc=pa;//pc����
	   pa=pa->next;//La����
	  }
	  else
	  {
        pc->next=pb;
		pc=pb;
		pb=pb->next;
	  }
  }//������ѭ����Ӧ�û�ʣ��һ������û�ϲ���(�������������Ȳ�һ��)
  pc->next=pa?pa:pb;//ʣ��

 }
void print_list(LinkList L)
{
  LinkList p=L->next;//ָ���һ�����
  while(p)
  {
	  printf("%3d",p->data);
	  p=p->next;
  }
  printf("\n");
}
