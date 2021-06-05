#include<stdlib.h>
#include<stdio.h>

void selectionSort(int *arr, int n) // arr is a pointer to array and n is size of the array
{
   int i = 0, t, min_index;

    for (i = 0; i <= n - 2; i++)
    {
        min_index = find_min_index(arr, n, i);
        t = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = t;
    }
}

int find_min_index(int arr[], int n, int i)
{
    int min, index;
    min = arr[i];
    index = i;

    for (i = i + 1; i <= n - 1; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            index = i;
        }
    }

    return index;
}
