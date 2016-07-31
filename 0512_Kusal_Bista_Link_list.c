/*  
* C program to implement link list  
* Author : Kusal Bista 
* Date : 07/28/2016  
* Ref : Data Structure using C and C++, chapter 4, page no: 191  
*/  
	
#include<stdio.h>
#include<stdlib.h>

//Creating structure for link list
struct node{
	int info;
	struct node *next;
};

typedef struct node *nodeptr;

nodeptr getnode();
void freenode(nodeptr);
void insertatfirst(nodeptr*, int);
void displaylist(nodeptr);
int deletefromfront(nodeptr*);
//Main Function
int main()
{
	nodeptr list;
	list= NULL;
	insertatfirst(&list, 6);
	insertatfirst(&list, 5);
	insertatfirst(&list, 4);
	printf("The linked list is:\n");
	displaylist(list);
	printf("The deleted item is:\n %d", deletefromfront(&list));
	printf("\nThe linked list is:\n");
	displaylist(list);
}
//Getting node
nodeptr getnode()
{
	return (nodeptr)malloc(sizeof(struct node));
}
//Makes node free
void freenode(nodeptr p)
{
	free(p);
}
//Allows to insert
void insertatfirst(nodeptr *p, int x)
{
	nodeptr q;
	q=getnode();
	q->info=x;
	q->next=*p;
	*p=q;
}

void displaylist(nodeptr p)
{
	nodeptr ptr=p;
	while(ptr!=NULL)
	{
		printf("%d\n", ptr->info);
		ptr=ptr->next;
	}
}
//Delete front node from linked list
int deletefromfront(nodeptr*p)
{
	if (*p==NULL)
	{
		printf("\nUNDERFLOW\n");
		exit(0);
	}
	else
	{
	nodeptr q;
	int x;
	q=*p;
	*p=q->next;
	x=q->info;
	return x;
	freenode(q);
	}
}





