#include<stdio.h>
#include<stdlib.h>
//结点结构体定义
typedef struct lnode{
	int data;
    struct LNode *next;
}LNode,LinkList;

void main()
{//函数声明
 void creat_list(LinkList &L,int n);
 void merge_list(LinkList &La,LinkList &Lb,LinkList &Lc);
 void print_list(LinkList L);
 //主函数开始
 int n1,n2;
 LinkList La,Lb,Lc;
 printf("建立La链表开始:请先输入要建立的结点个数\n");
 scanf("%d",&n1);
 creat_list(La,n1);
 printf("La链表信息如下:\n");
 print_list(La);
 printf("建立Lb链表开始:请先输入要建立的结点个数\n");
 scanf("%d",&n2);
 creat_list(Lb,n2);
 printf("Lb链表信息如下:\n");
 print_list(Lb);
 printf("合并完两链表后如下:\n");
 merge_list(La,Lb,Lc);
 print_list(Lc);
}
void creat_list(LinkList &L,int n)
{   int i;
	LinkList p,q;
	L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;//建立头结点
    q=L;
	for (i=1;i<=n;i++)
	{p=(LinkList)malloc(sizeof(LNode));
	printf("请输入第%d个节点的数据:",i);
	scanf("%d",&p->data);
	q->next=p;
	q=q->next;//q后移
	}
	p->next=NULL;//最后一个节点是尾结点
}
 void merge_list(LinkList &La,LinkList &Lb,LinkList &Lc)
 {LinkList pa,pb,pc;
  pa=La->next;pb=Lb->next;//a，b链表均指向自己的第一个结点
  pc=Lc=La;//Lc链表自始至终就没有建立过，实际上LC就是借助指针去连接la和lb中的结点
  while(pa&&pb)//不指向末尾
  {
	  if (pa->data<=pb->data)//插入La
	  {pc->next=pa;
	   pc=pa;//pc后移
	   pa=pa->next;//La后移
	  }
	  else
	  {
        pc->next=pb;
		pc=pb;
		pb=pb->next;
	  }
  }//结束该循环后应该会剩下一个链表没合并完(假设俩个链表长度不一样)
  pc->next=pa?pa:pb;//剩余

 }
void print_list(LinkList L)
{
  LinkList p=L->next;//指向第一个结点
  while(p)
  {
	  printf("%3d",p->data);
	  p=p->next;
  }
  printf("\n");
}
