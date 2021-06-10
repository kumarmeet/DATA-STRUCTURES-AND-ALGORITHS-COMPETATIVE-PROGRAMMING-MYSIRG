#include <stdlib.h>
#include <stdio.h>

struct node
{
    char d;
    struct node *next;
};

void search(struct node * list1, struct node * list2)
{
    int flag = 0, i, j, count = 0, temp;
    struct node *l1, *l2;

    l1 = list1;
    l2 = list2;

    while(l1)
    {
        ++count;
        l1 = l1->next;
    }
    int arr1[count];

    count = 0;

    while(l2)
    {
        ++count;
        l2 = l2->next;
    }
    int arr2[count];

    for(i = 0; i < count; i++)
    {
        arr1[i] = list1->d;
        list1 = list1->next;
    }

    for(i = 0; i < count; i++)
    {
        arr2[i] = list2->d;
        list2 = list2->next;
    }


    for(i = 0; i < count; i++)
    {
        for(j = i + 1; j < count; j++)
        {
            if(arr1[i] > arr1[j])
            {
                temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }

            if(arr2[i] > arr2[j])
            {
                temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }
        }
    }

    for(i = 0; i < count; i++)
    {
        if(arr1[i] == arr2[i])
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("%d",1);
    else
        printf("%d",-1);
}

/*
second method
int flag = 1, temp;
    struct node *l1, *l2, *i1 = NULL, *i2 = NULL;

    l1 = list1;
    l2 = list2;

    while(l1)
    {
        i1 = l1->next;
        i2 = l2->next;

        while(i1)
        {
            if(l1->d > i1->d)
            {
                temp = l1->d;
                l1->d = i1->d;
                i1->d = temp;
            }
            i1 = i1->next;
        }

        while(i2)
        {
            if(l2->d > i2->d)
            {
                temp = l2->d;
                l2->d = i2->d;
                i2->d = temp;
            }
            i2 = i2->next;
        }

        l2 = l2->next;
        l1 = l1->next;
    }

    while(list1)
    {
        if(list1->d == list2->d)
            flag = 1;
        else if(list1->d != list2->d)
        {
            flag = 0;
            break;
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    if(flag)
        printf("%d",1);
    else
        printf("%d",-1);
*/
