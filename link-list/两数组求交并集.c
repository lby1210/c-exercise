#include<stdio.h>


int main()
{
	int a[3];
	int b[2];
	
	int i;
	int j;
	printf("输入第一个数组：\n");
	for(i=0;i<3;i++)
	{
		scanf("%d",&a[i]);
	} 
	
	printf("输入第二个数组：\n");
	for(j=0;j<2;j++)
	{
		scanf("%d",&b[j]);
	}
	
	int m;
	for(i=0;i<3;i++)
	{
		
		for(j=0;j<2;j++)
		{
			if(a[i]==b[j])
			{
				a[i]=0;
			}
		}
	}
	for(i=0;i<3;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
