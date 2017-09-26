#include<stdio.h>
void initstack(int *top)
{
	*top=-1;
}
int emptystack(int top)
{
	if (top==-1)
		return 1;
	else
		return 0;
}
int fullstack(int top)
{
	if(top==9)
		return 1;
	else return 0;
}
void push(int *a,int *top,int x)
{
	*top=*top+1;
	a[*top]=x;
}
void pop(int *a,int *top,int *p)
{
	*p=a[*top];
	*top=*top-1;
}

int main()
{
	int choice,x,p,top,a[10];
	initstack(&top);
	do
	{

		printf("The stack operations are :\n1)push\n2)pop\n3)exit");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{case 1: 
			if(!fullstack(top))
			{
				printf("\nenter a number to push in stack\n");
				scanf("%d",&x);
				push(a,&top,x);
			}
			else
				printf("\nstack is full\n");
			break;

			case 2:
			if (!emptystack(top))
			{
				pop(a,&top,&p);
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