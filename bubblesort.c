//Bubble Sort
#include<stdio.h>
void bsort(int *a,int n)
{
	int i,j,flag,temp;
	j=1;
	flag=0;
	while(flag==0)
	{
		flag=1;
		for(i=0;i<n-j;i++)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				flag=0;
			}
		}
		j++;
	}
}
int main()
{
	int n,a[10],i;
	printf("enter no of elements in the array\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for (i = 0; i < n; i++)
		scanf("%d",&a[i]);
	bsort(a,n);
	printf("the sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i] );

	printf("\n");
	return 0;
}