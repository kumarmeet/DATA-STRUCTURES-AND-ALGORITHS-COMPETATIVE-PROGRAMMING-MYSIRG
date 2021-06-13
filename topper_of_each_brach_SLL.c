#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    char *name;
    struct node *next;
};
struct node* create(int, char*);
struct node* find_max(struct node*);

int main()
{
    struct node *start = NULL;

    struct node *student1 = NULL;
    struct node *student2 = NULL;
    struct node *student3 = NULL;

    insert(&student1, 500, "amit");
    insert(&student1, 550, "sumit");
    insert(&student1, 530, "ram");

    insert(&student2, 480, "vijay");
    insert(&student2, 520, "raghav");
    insert(&student2, 500, "ajay");

    insert(&student3, 520, "rohit");
    insert(&student3, 510, "chetan");
    insert(&student3, 530, "shyam");

    searchToppers(student1, student2, student3, &start);

    viewList(student1, student2, student3, start);

    return 0;
}

void searchToppers(struct node *list1,struct node *list2,struct node *list3,struct node **list4)
{
    struct node *l1 = find_max(list1);
    struct node *l2 = find_max(list2);
    struct node *l3 = find_max(list3);

    *list4 = l1;
    l1->next = l2;
    l2->next = l3;
    l3->next = NULL;
}

struct node* find_max(struct node *list)
{
    struct node *temp, *t;

    temp = list;

    while(temp)
    {
        if(t->data  < temp->data)
            t = temp;
        temp = temp->next;
    }

    t->next = NULL;

    return t;
}

void insert(struct node **s, int item, char *name)
{
    struct node *t;
    if(*s == NULL)
        *s = create(item, name);
    else
    {
        t = *s;
        while(t->next != NULL)
            t = t->next;

        t->next = create(item, name);
    }
}

void viewList(struct node *s1, struct node *s2, struct node *s3, struct node *s)
{
    while(s1)
    {
        printf("%d %s\n",s1->data, s1->name);
        s1 = s1->next;
    }

    while(s2)
    {
        printf("%d %s\n",s2->data, s2->name);
        s2 = s2->next;
    }

    while(s3)
    {
        printf("%d %s\n",s3->data, s3->name);
        s3 = s3->next;
    }

    while(s)
    {
        printf("%d %s\n",s->data, s->name);
        s = s->next;
    }
}

struct node* create(int item, char *name)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = item;
    n->name = name;
    n->next = NULL;
    return n;
}
