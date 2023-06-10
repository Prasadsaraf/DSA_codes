 #include<stdio.h>
#include<stdlib.h>
void selection(int a[],int n)
{
    int min,i,j,temp;
    for(i=0;i<n-1;i++)
    {
     min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
}
}

int main()
{
    int a[20],n;
    printf("Enter the value of n");
    scanf("%d",&n);
    printf("Enter the elements to be sorted:");
    { int i;
      for(i=0;i<n;i++)
     {
        scanf("%d",&a[i]);
     }
    }
     selection(a,n);
      printf("The sorted elements are:");
    {
        int i;
       for(i=0;i<n;i++)
       {
          printf("%d",a[i]);
       }
    }
}
