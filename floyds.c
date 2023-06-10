#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void floyds(int a[50][50],int n)
{
    int i,j,k;
  for( k=0;k<n;k++)
  {
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]>(a[i][k]+a[k][j]))
            {
                a[i][j]=(a[i][k]+a[k][j]);
            }
        }
    }
  }
}
int main()
{
    int a[50][50],n,i,j;
    printf("enter n value:\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for( j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    floyds(a,n);
    printf("all pair shortest path:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
