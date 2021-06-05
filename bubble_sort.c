#include<stdlib.h>
#include<stdio.h>

int main()
{
    int arr[] = {1,58,96,32,4,5,6,21,30,41};
    bubble_sort(arr,10);

    return 0;
}

void bubble_sort(int arr[], int n)
{
    int i, j, temp, size, flag;
    size = n;

    for(i = 0; i < n; i++)
    {
        flag = 0; // check if round is already sorted
        for(j = 0; j < n - 1 - i ; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1; // if not sorted then we go inside the swapping condition and flag = 1 means array is not sorted
            }
        }
        if(flag == 0) // modified bubble sort
            break;
    }
}
