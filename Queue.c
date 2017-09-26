#include <stdio.h>
#define MAXSIZE 10
void initq(int *f,int *r)
{
	*f=0;
	*r=0;
}
int emptyq(int f ,int r)
{
	if (f==r)
		return 1;
	else return 0;
}
int fullq(int f, int r)
{
	if((r+1)%MAXSIZE==f)
		return 1;
	else return 0;
}
void enterq(int *x,int *r,int p)
{
	x[*r]=p;
	*r=(*r+1)%MAXSIZE;
}
void deleteq(int *x,int *f,int *p)
{
	*p=x[*f];
	*f=(*f+1)%MAXSIZE;
}

int main()
{
	int x[MAXSIZE],f,r,p,choice;

	initq(&f,&r);
	printf("The opertions on the queue are\n");

	do
	{
		printf("1.enterq\n2.deleteq\n3.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			if(!fullq(f,r))
			{
				printf("\nEnter a number to enter into queue\n");
				scanf("%d",&p);
				enterq(x,&r,p);
			}
			else
				printf("\nQueue is full\n\n");
			break;

			case 2:
			if(!emptyq(f,r))
			{
				deleteq(x,&f,&p);
				printf("\n%d is deleted\n\n",p );
			}
			else
				printf("\nqueue is empty!\n\n");
			break;

			case 3:
			printf("\n");
			break;

			default:
			printf("\nInvalid choice entered!\n");
		}
	}while(choice!=3);

	return 0;
}