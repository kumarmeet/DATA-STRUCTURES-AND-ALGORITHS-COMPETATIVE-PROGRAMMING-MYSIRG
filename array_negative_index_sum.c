#include <stdio.h>
#include <stdlib.h>

void negative_indexing_sum(int arr1[], int arr2[], int n1, int n2)
{
    //-1 = 50, -3 = 30, -1 = 10  -> 50 + 30 + 10 = 90
    int i, j, sum = 0, temp;

    arr1[n1];
    arr2[n2];
    int neg[n1], k = n1 - 1;

    //reverse the array
    for(i = 0; i < n1 / 2; i++)
    {
        temp = arr1[k];
        arr1[k] = arr1[i];
        arr1[i] = temp;
        k--;
    }

    k = 0;

    for(i = 0; i < n1; i++)
    {
        --k;
        neg[i] = k; // -1 -2 -3 -4 -5
    }

    for(i = 0; i < n1; i++)
        for(j = 0; j < n1; j++)
            if(arr2[i] == neg[j])
                sum += arr1[j];


    printf("%d",sum);

//    for(j = 0; j < n1; j++) //n1 - (n1 + 1) = -1 and (-n1) = -5
//        for(i = n1 - (n1 + 1); i >= (-n1); i--)
//            if(i == arr2[j]) //compare inputed negative number and neg[] array
//                sum += arr1[j];
}

