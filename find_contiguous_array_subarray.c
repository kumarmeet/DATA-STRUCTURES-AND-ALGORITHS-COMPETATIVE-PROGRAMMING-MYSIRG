#include <stdio.h>
#include <stdlib.h>

void find_contigous_subarray(int a[], int t)
{
    int i, j, n = 0, l = -1, k = 0, m;
    int b[10] = {4};

    a[t];

    for(i = 0; i < t; i++)
    {
        for(j = i + 1; j < t; j++)
        {
            if(a[i] != a[j])
            {
                b[k] = a[i];
                b[++k] = a[j];
                n++;
                i++;
                j++;
                k++;
                break;
            }
            if(a[i] == a[j])
            {
                n = 0;
                i = l++;
                k = 0;
                for(m = 0; m < t; m++)
                    b[m] = 0;
                break;
            }
        }
    }

    int c[n * 2];

    for(i = 0; i < n * 2; i++)
        c[i] = b[i]; // contiguous sub array length 0's and 1's

    printf("Contiguous sub-array -> ");
    for(i = 0; i < (n * 2); i++)
        printf("%d ", c[i]);

    printf("\nContiguous sub-array length-> ");
    printf("%d", n * 2); // contiguous sub array length
}
