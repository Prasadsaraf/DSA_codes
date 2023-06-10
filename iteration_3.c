#include <stdio.h>
int main()
{
    int i;
    int arr[10] = {5,9,10,3,7,1,8,6,2,4};
    int size = sizeof(arr) / sizeof(int);
    int max = arr[0];

    for (i=1;i<size;i++)
        {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }

    printf("The largest element in the array is: %d", max);
     return 0;
}
