#include <stdlib.h>
#include <stdio.h>

struct node
{
    char d;
    struct node *next;
};

struct node *merge(struct node *name, struct node *middlename)
{
    struct node *t, *m, *r, *fullname;

    //created new node for adding space after middle name
    struct node *space = (struct node*) malloc(sizeof(struct node));
    space->d = ' ';
    space->next = NULL;

    int count = 0;
    fullname = t = name;
    m = middlename;

    while(m)
    {
        ++count;
        m = m->next;
    }

    while(t->d != ' ') //for finding space in first name
        t = t->next;

    r = t->next; //r containing space location address

    t->next = middlename; //add middle name after space


    while(count) //go to until middle name is not ending
    {
        t = t->next;
        --count;
    }

    t->next = space; //adding space in after middle name
    space->next = r; //add whole data after space

    return fullname;
}
