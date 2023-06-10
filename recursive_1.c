//Maximum in a array//
#include <stdio.h>
int arr(int a[],int low,int u)
{
 int max;
 if (low==u)
    {
 return a[low];
    }
 else
    {
 max = arr(a, low + 1, u);
    }
 if (a[low]>=max)
  {
 return a[low];
  }
 else
    {
 return max;
    }
 }
 int main()
{
 int a[10] = { 23, 43, 35, 38, 67, 12, 76, 10, 34, 8 };
  printf("The largest in array is %d", arr(a, 0, 9));
   return 0;
}


