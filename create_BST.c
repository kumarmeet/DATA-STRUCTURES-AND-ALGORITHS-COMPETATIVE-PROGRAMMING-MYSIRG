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
void inorder(struct node *);

struct node *root = NULL;

int main()
{
    int arr[] = {50,30,60,22,38,55,34};
    int n = 7;

    createBST(arr, n);

    inorder(root);
    return 0;
}

void createBST(int *arr,int n)
{
    int i;

    for(i = 0; i < n; i++)
        insertNode(&root, arr[i]);
}

void inorder(struct node *t)
{
    if(t)
    {
        inorder(t->lchild);
        printf("%d ",t->info);
        inorder(t->rchild);
    }
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
