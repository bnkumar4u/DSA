#include<stdio.h>
int steps=0;
void move(int n,char a,char b,char c)
{
	if (n==1)
	{
		steps++;
		printf("Move one disk from %c to %c\n",a,c);
	}
	else
	{
		move(n-1,a,c,b);
		move(1,a,b,c);
		move(n-1,b,a,c);
	}
}
int main()
{
	int n;
	printf("Enter no of disks\n");
	scanf("%d",&n);
	move(n,'A','B','C');
	printf("No of steps required will be %d\n",steps );
	return 0;
}