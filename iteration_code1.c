#include <stdio.h>
int main() {
    int arr[] = {2,4,6,8,10};
    int n=5;
    int sum=0,i;

    for (i=0;i<n;i++)
        {
        sum=sum+arr[i];
    }

    printf("Sum of array elements: %d\n", sum);

    return 0;
}
