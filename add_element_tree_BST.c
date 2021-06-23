#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *lchild;
    struct node *rchild;
}*root;

struct node * createNode(struct node*, int);
void insertNode(struct node**, int);

struct node *root = NULL;

void addelements(int *arr,int n)
{
    int i;

    for(i = 0; i < n; i++)
        if(arr[i] != root->info)
            insertNode(&root, arr[i]);
}

void insertNode(struct node **b, int item)
{
    struct node *n;

    if(!(*b))
        (*b) = createNode(&b, item);

    if(item < (*b)->info)
        insertNode(&(*b)->lchild, item);
    else if(item > (*b)->info)
        insertNode(&(*b)->rchild, item);
}

struct node * createNode(struct node *b, int item)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->lchild = n->rchild = NULL;
    n->info = item;
    return n;
}
