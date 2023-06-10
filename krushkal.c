 #include<stdio.h>
#include<stdlib.h>
struct node
{
    int u;
    int v;
    int w;
};
typedef struct node NODE;
NODE a[14]={{0,1,8},{1,2,16},{2,3,14},{3,4,18},{4,5,20},{5,6,4},{6,7,2},{7,8,14},{7,0,16},{1,7,22},{2,8,4},{2,5,8},{6,8,12},{3,5,28}};
int b[9]={0,1,2,3,4,5,6,7,8},n=9,size=14;


int check(int b[],int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {
        if(b[i]!=b[i+1])
        {
            return 1;
        }
    }
    return 0;
}
void selection_sort(NODE a[],int size)
{
    int min,i,j;
    NODE temp;
    for(i=0;i<size-1;i++)
    {
        min=i;
        for(j=i+1;j<size;j++)
        {
            if(a[j].w<a[min].w)
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;

    }
}
int find(int b[],int n,int u,int v)
{
    if(b[u]==b[v])
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void union_k(int b[],int n,int u,int v)
{
    int temp,i;
    temp=b[u];
    for(i=0;i<n;i++)
    {
        if(b[i]==temp)
        {
            b[i]=b[v];
        }
    }
}
int kruskal()
{
    int i=0,k,j,sum=0;
    while(check(b,n))
    {
        k=find(b,n,a[i].u,a[i].v);
        if(k==1)
        {
            printf("%d\t%d\n",a[i].u,a[i].v);
            sum=sum+a[i].w;
            union_k(b,n,a[i].u,a[i].v);
        }
        i++;
    }
    return sum;
}
int main()
{
    int sum;
    selection_sort(a,size);
    sum=kruskal();
    printf("\ncost=%d",sum);
}
