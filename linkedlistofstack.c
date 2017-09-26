#include <stdio.h>
struct node
{
	int info;
	int *next;
};
typedef struct node node1;
void initlist(int *avail,int *list,node1 *a,int n)
{
	int i;
	*list =-1;
	*avail=0;
	for(i=0;i<n-1;i++)
	{
		a[i].next=i+1;
	}
	a[n-1].next=-1;
}
int emptystack(int list)
{
	if(list==-1)
		return 1 ;
	else
		return 0 ;
}
int fullstack(int avail)
{
	if(avail==-1)
		return 1;
	else 
		return 0 ;
}
void push(int *list,int *avail,node1 *a,int x)
{
	int p;
	p=*avail;
	*avail=a[*avail].next;
	a[p].info=x;
	a[p].next=*list;
	*list=p;
}
void pop(int *list,int *avail,node1 *a,int *x)
{
	int p;
	p=*list;
	*list=a[*list].next;
	*x=a[p].info;
	a[p].next=*avail;
	*avail=p;
}
int main()
{
	node1 a[10];
	int avail,list,n=10,x,p,choice;
	initlist(&avail,&list,a,n);
	printf("linked list implementing stack\n");
	do
	{

		printf("The stack operations are :\n1)push\n2)pop\n3)exit");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{case 1:
			if(!fullstack(avail))
			{
				printf("\nenter a number to push in stack\n");
				scanf("%d",&x);
				push(&list,&avail,a,x);
			}
			else
				printf("\nstack is full\n");
			break;

			case 2:
			if (!emptystack(list))
			{
				pop(&list,&avail,a,&p);
				printf("\n%d is poped \n",p );
			}
			else printf("\nstack is empty\n");
			break;
			case 3:
			printf("\n");
			break;

			default:
			printf("\nenter a valid choice!\n");
			break;
		}


	}while(choice!=3);

	return 0;
}