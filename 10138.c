#include<stdio.h>

	void main()
	{
		double a[7]={1,2,3,4,5,6,7};
		double b[3]={0};
		int i;
		copy_ptrs(b,a+2,a+4);		
		for(i=0;i<3;i++)
		{
			printf("%lf ",b[i]);
		}
		
		
	}
	
	copy_ptrs(double target[],double ar1[],double ar2[])
	{
		int i;
		for(i=0;ar1<=ar2;i++)
		{
			target[i] = *ar1;
			ar1++;
		}
	}
