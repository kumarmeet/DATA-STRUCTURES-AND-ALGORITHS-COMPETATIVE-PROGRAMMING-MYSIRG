#include <stdlib.h>
#include <stdio.h>

struct node
{
    int d;
    struct node *next;
};

struct node *start = '\0';

void reverseNumber(struct node *list, int n)
{
    struct node *pre, *cur;
    int num = 0;

    //start reverse node
    pre = list;
    cur = list->next;
    list = list->next;
    pre->next = NULL;

    while (list != NULL)
    {
        list = list->next;
        cur->next = pre;
        pre = cur;
        cur = list;
    }

    list = pre;

    //logic of reverse traversal of singly linked list node
    //    pre = NULL;

    // while (list != NULL)
    // {
    //     cur = list->next;
    //     list->next = pre;
    //     pre = list;
    //     list = cur;
    // }

    // list = pre;
    //reverse node end

    start = list;
    while (start)
    {
        num = num * 10 + start->d;
        start = start->next;
    }

    printf("%d", num);
}
