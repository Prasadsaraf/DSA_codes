#include<stdio.h>
#include<stdlib.h>
void bubble_sort(int a[20],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
      for(j=0;j<n-1-i;j++)
      {
          if(a[j]>a[j+1])
           {
             temp=a[j];
             a[j]=a[j+1];
             a[j+1]=temp;
           }
      }
    }
}

int main()
{
    int n,a[20];
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("Enter the elements to be sorted:\n");
    {
        int i;
        for( i=0;i<n;i++)
        {
         scanf("%d",&a[i]);
        }
    }
    bubble_sort(a,n);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
