#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n], i;
    int r = sizeof(arr) / sizeof(arr[0]); //20 / 4 = 5

    for(i = 0; i < r; i++)
        scanf("%d",&arr[i]);

    // perform quicksort on data
    quickSort(arr, 0, r - 1);
    printArray(arr, n);

    return 0;
}

// function to print array elements
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// function to find the partition position
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
