#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h" 

void showmovies(Item item);
char* s_gets(char* st,int n);

int main(void)
{
	List book;
	Item temp;
	
 	InitList(&book);
	if(ListIsFull(&book))
	{
		fprintf(stderr,"No momery available\n");
		exit(EXIT_FAILURE); 
	}
	puts("put first book title");
	while(s_gets(temp.title,TSIZE)!=NULL && temp.title[0]!='\0')
	{
		puts("put rating<1-10>");
		scanf("%d",&temp.rating);
		while (getchar() != '\n')
            continue;
		if(AddItem(temp,&book)==false)
		{
			fprintf(stderr,"problem");
			break;
		}
		
		if(ListIsFull(&book))
		{
			puts("The list is full");
			break;
		}
		puts("Enter next book title");		
	}
	
	if(ListIsEmpty(&book))
	{
		puts("No DATA");
	}	
	else
	{
		printf("movies list:\n");
		Traverse(showmovies,&book);
	}
	
	printf("your entered %d movies\n",ListCount(&book));
	
	EmptyTheList(&book);
	printf("done\n"); 
	return 0;
} 

void showmovies(Item item)
{
	printf("movie:%s  rating:%d \n",item.title,item.rating);
}

char* s_gets(char *st,int n)
{
	char *ret_val;
	char *find;
	ret_val=fgets(st,n,stdin);
	if(ret_val)
	{
		find=strchr(st,'\n');
		if(find)
			*find='\0';
		else
		{
			while(getchar()!='\n')
				continue; 
			
		}
		
		return ret_val;
	} 
	
}


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "list.h"
//void showmovies(Item item);
//char * s_gets(char * st, int n);
//
//int main(void)
//{
//    List book;
//    Item temp;
//
//    InitList(&book);
//    if (ListisFull(&book))
//    {
//        fprintf(stderr, "No memory available\n");
//        exit(EXIT_FAILURE);
//    }
//
//    puts("Enter first book title:");
//    while (s_gets(temp.title, TSIZE) != NULL&&
//        temp.title[0] != '\0')
//    {
//        puts("Enter your rating<0-10>:");
//        scanf("%d", &temp.rating);
//        while (getchar() != '\n')
//            continue;
//        if (AddItem(temp, &book) == false)
//        {
//            fprintf(stderr, "Problem allocating memory\n");
//            break;
//        }
//        if (ListisFull(&book))
//        {
//            puts("The list is now full.\n");
//            break;
//        }
//        puts("Enter next book title(empty line to stop):");
//    }
//
//    if (ListisEmpty(&book))
//        printf("No data entered.\n");
//    else {
//        printf("Here is the movies list:\n");
//        Traverse(&book, showmovies);
//    }
//    printf("You entered %d movies.\n", ListItemCount(&book));
//
//    EmptyTheList(&book);
//    printf("Bye\n");
//
//    return 0;
//}
//void showmovies(Item item)
//{
//    printf("book: %s Rating:%d\n", item.title, item.rating);
//}
//char * s_gets(char * st, int n)
//{
//    char * ret_val;
//    char * find;
//    ret_val = fgets(st, n, stdin);
//    if (ret_val)
//    {
//        find = strchr(st, '\n');
//        if (find)
//            *find = '\0';
//        else
//            while (getchar() != '\n')
//                continue;
//    }
//    return ret_val;
//}
