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
void addlist(int *list,int *avail,node1 *a,int x)
{
	int p,q,back;
	p=*avail;
	*avail=a[*avail].next;
	a[p].info=x;

	if(*list==-1)
	{
		a[p].next=*list;
		*list=p;
	}
	else if(x<a[*list].info)
	{
		a[p].next=*list;
		*list=p;
	}
	else
	{
		q=*list;
		back=*list;
		while(q!=-1&& a[q].info<x)
		{
			back=q;
			q=a[q].next;
		}
		a[p].next=a[back].next;
		a[back].next=p;
	}

}
void deletlist(int *list,int *avail,node1 *a,int x)
{
	int p,q,back;
	
	if(*list==-1)
	{
		printf("\nlist is empty\n");
	}
	else
	{
		p=*list;
		back=*list;
		while(p!=-1&&a[p].info!=x)
		{
			back=p;
			p=a[p].next;
		}
		if(p==-1)
			printf("\nValue is not found\n");
		else
		{
			printf("\n%d is deleted\n",x );
			a[back].next=a[p].next;
			a[p].next=*avail;
			*avail=p;
		}
	}
}
int searchlist(node1 *a,int list,int x)
{
	while(a[list].info!=x && list!=-1)
	{
		list=a[list].next;
	}
	if(list==-1)
		return 0;
	else
		return 1;
}

void traverselist(node1 *a,int list)
{
	while(list!=-1)
	{
		printf("%d\t",a[list].info);
		list=a[list].next;
	}
	printf("\n");
}
int main()
{
	node1 a[10];
	int avail,list,n=10,x,p,choice;
	initlist(&avail,&list,a,n);
	printf("linked list implementing stack\n");
	do
	{

		printf("The stack operations are :\n1)addlist\t2)deletlist\n3)searchlist\t4)traverselist\t5)exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{case 1:
			if(!fullstack(avail))
			{
				printf("\nenter a number to push in stack\n");
				scanf("%d",&x);
				addlist(&list,&avail,a,x);
			}
			else
				printf("\nstack is full\n");
			break;

			case 2:
				printf("enter a value to delete\n");
				scanf("%d",&x);
				deletlist(&list,&avail,a,x);
				break;

			case 3:
				printf("\nenter a value to search\n");
				scanf("%d",&x);
				if(searchlist(a,list,x))
					printf("\nValue found\n");
				else
					printf("\nValue not found\n");
				break;

			case 4:
				traverselist(a,list);
				break;

			case 5:
			printf("\n");
			break;

			default:
			printf("\nenter a valid choice!\n");
			break;
		}

	}while(choice!=5);

	return 0;
}