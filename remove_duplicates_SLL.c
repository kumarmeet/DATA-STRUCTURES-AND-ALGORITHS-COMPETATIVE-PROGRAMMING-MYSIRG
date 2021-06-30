#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void remove_duplicates(struct node *s)
{
    struct node *current = s, *i = NULL, *t = NULL;

    while(current)
    {
        t = current;
        i = current->next;

        while(i)
        {
            if(current->info == i->info)
                t->next = i->next;
            else
                t = i;
            i = i->next;
        }
        current = current->next;
    }
}