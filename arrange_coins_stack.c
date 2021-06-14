#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, i, j, temp;
    scanf("%d",&n);
    int arr[n], stack[n];

    for(i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
        stack[i] = arr[i];

    for(i = 0; i < n; i++)
        printf("%d ",stack[i]);

    return 0;
}