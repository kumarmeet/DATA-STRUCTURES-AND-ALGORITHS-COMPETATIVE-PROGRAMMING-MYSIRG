#include <stdio.h>
#include <stdlib.h>

void reverse_number_using_stack(int *a)
{
    int i = 0, j = 0, n, temp;
    size_t size = 1;

    scanf("%d",&n); //1234

    while(n != 0)
    {
        temp = n % 10; //pop the number
        a = (int*)realloc(a, size * sizeof(int));
        *(a + i) = temp; // push the number
        size++;
        i++;
        n = n / 10;
    }

    for(i = 0; i < size - 1; i++)
        printf("%d",*(a + i));
}
