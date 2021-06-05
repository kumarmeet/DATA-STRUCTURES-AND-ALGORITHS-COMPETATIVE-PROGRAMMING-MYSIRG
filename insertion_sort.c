#include<stdlib.h>
#include<stdio.h>

void insertion_sort(int arr[], int n)
{
    int temp, i, j;
    for(i = 0; i < n; i++)
    {
        temp = arr[i];
        for(j = i - 1; j >=0; j--)
        {
            if(arr[j] > temp)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = temp;
    }
}
