#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int val1, val2;

    scanf("%d%d", &val1, &val2);
  
    if(val1 > val2)
       exit(0);

    size_t size = (val2 - val1) + 1;

    int arr[size];
    int j = 0;

    for(int i = val1; i <= val2; i++)
    {
        arr[j] = i;
        j++;
    }

    int extract[size];
    int temp, r;
    j = 0;
    int m = 0;

    for(int i = 0; i < size; i++) // take element from arr[] and split into single digit
    {
        temp = arr[i];
        while(temp)
        {
            r = temp % 10;
            extract[j] = r; //copy single digit from arr[]
            temp = temp / 10;
            j++;
        }

        swap(&extract[m], &extract[m++]); // swap all element and rearrange increasing order
        m++;
    }

    int swaped[j];

    for(int i = 0; i < j; i++)
      swaped[i] = extract[i];

    int k;

    scanf("%d", &k);

    printf("%d", swaped[k]);

    return 0;
}

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
