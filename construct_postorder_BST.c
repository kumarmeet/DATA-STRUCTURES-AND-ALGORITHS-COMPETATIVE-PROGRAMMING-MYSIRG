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
struct node* createTree(int *inorder, int *preorder,int n);

struct node *root = NULL;

int main()
{
    int inorder[] = {22,30,34,38,50,55,60};
    int preorder[] = {50,30,22,38,34,60,55};
    int n = 7;

    postorder(createTree(inorder, preorder,n));
    return 0;
}

struct node* createTree(int *inorder, int *preorder,int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            if(preorder[i] == inorder[j])
                break;

        insertNode(&root, preorder[i]);
        preorder[i] = inorder[j] = 0;
    }

    return root;
}

void postorder(struct node *t)
{
    if(t)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%d ",t->info);
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