//BUBBLE SORT
#include<stdio.h>
#include<conio.h>
void bsort(int [],int );
main()
{
      int a[10],n,i,j;
      printf("No. of elements in array : ");
      scanf("%d",&n);
      printf("Enter the elements in the array : \n");
      for(i=0;i<n;i++)
      { scanf("%d",&a[i]);
      }
      bsort(a,n);
      printf("The sorted array is : \n");
      for(j=0;j<n;j++)
      { printf("%d",a[j]);}
      getch();
}

void bsort(int a[],int n)
{ int i,j,t;
  for(i=0;i<n-1;i++)
  {  for(j=0;j<n-i-1;j++)
      { if(a[j]>a[j+1])
        {t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
        }
      }
   }
}
      
