#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "tree.h"

char menu(void);
void addpet(Tree* pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printfitem(Item item);
void uppercase(char *str);
char *s_gets(char *st,int n);

int main(void)
{
	Tree pets;
	char choise;
	
	Initialize(&pets);
	
	
	while (choise =menu()) != 'q')
	{
		switch(choise)
		{
			case 'a': addpet(&pets);
				break;
			case 'l': showpets(&pets);
				break;
			case 'f': findpet(&pets);
				break;
			case 'n': printf("%d pets in club \n",TreeItenCount(&pets));
				break;
			case 'd' droppet(&pets);
				break;
			default: puts("Switching error");
		}
	}
	DeleteAll(&pets);
	puts("done");
		
	return 0;
}


		char menu(void)
		{
			int ch;
			
			puts("Nerfville Per Club");
			puts("Enter the letter corresponding to your choise:");
			puts("a)add a pet        l)show list of pets");
			puts("n)number of pets   f)find pet");
			puts("d)delete a pet     q)quit");
			while (getchar()!=EOF)     //EOF就是库函数中#define的，值是-1 
			{
				while(getchar()!='\n')
				{
					continue;
				}
				ch =tolower(ch);//把字符转换成小写字母,非字母字符不做出处理
				if(strchr("alrfndq",ch)==NULL)
					puts("Please enter an a,l,f,n,d,q");
				else
					break;
			}
			if(ch==EOF)
				ch='q''
			
			return ch;
		}
 
