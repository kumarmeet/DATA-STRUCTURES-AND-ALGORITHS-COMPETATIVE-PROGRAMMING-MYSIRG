#include <stdlib.h>
#include <stdio.h>

struct node
{
    char d;
    struct node *next;
};

void find(struct node *list,int k)
{
    int temp, i = 0, j = 0, count = 0;
    struct node *t, *r;
    t = r = list;

    while(t)
    {
        ++count;
        t = t->next;
    }

    t = r;

    int arr[count];

    while(t)
    {
        arr[i] = t->d;
        t = t->next;
        i++;
    }

    free(r);
    free(t);
    free(list);

    for(i = 0; i < count; i++)
    {
        for(j = i + 1; j < count; j++)
        {
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(i = 1; i <= count; i++)
    {
        if(i == k)
        {
            printf("%d ", arr[i - 1]);
            break;
        }
    }
}