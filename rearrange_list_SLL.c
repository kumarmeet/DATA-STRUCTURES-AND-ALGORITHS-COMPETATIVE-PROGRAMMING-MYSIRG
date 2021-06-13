#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node* create(int);

int main()
{
    struct node *start = NULL;
    int n, i;
    scanf("%d",&n);

    int arr[n];

    for(i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    for(i = 0; i < n; i++)
        insert(&start,arr[i]);

    for(i = 1; i <= n; i++)
        scanf("%d",&arr[i - 1]);

    rearranged(start, arr);

    viewList(start);

    return 0;
}

void rearranged(struct node *list,int *arr)
{
    struct node *t;
    int count = 0, i = 0, j = 0;
    t = list;

    while(t)
    {
        ++count;
        t = t->next;
    }

    int index[count];

    t = list;

    for(i = 0; i < count; i++)
    {
        index[i] = t->data;
        t = t->next;
    }

    //rearrange list logic
    for(i = 1; i <= count; i++)
        for(j = 1; j <= count; j++)
            if(j == arr[i - 1])
            {
                list->data = index[j - 1];
                list = list->next;
                break;
            }
}

void insert(struct node **s, int item)
{
    struct node *t;
    if(*s == NULL)
        *s = create(item);
    else
    {
        t = *s;
        while(t->next != NULL)
            t = t->next;

        t->next = create(item);
    }
}

void viewList(struct node *s)
{
    while(s)
    {
        printf("%d ",s->data);
        s = s->next;
    }
}

struct node* create(int item)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = item;
    n->next = NULL;
    return n;
}
