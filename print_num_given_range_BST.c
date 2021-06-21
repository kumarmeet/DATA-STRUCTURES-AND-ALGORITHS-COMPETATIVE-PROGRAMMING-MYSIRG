#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *lchild;
    struct node *rchild;
}*root;

void search(int k1,int k2)
{
    int n = count(root);
    int arr[n];
    int j = 0;
    int i, temp;

    AddToArray(root, arr, 0);

    for(i = 0; i < n; i++) // sorting array
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
        if(arr[i] >= k1 && arr[i] <= k2)
            printf("%d ", arr[i]);

}

int AddToArray(struct node *r, int arr[], int i) // convert bst to array
{
    if(r == NULL)
        return i;

    arr[i] = r->info;
    i++;
    if(r->lchild != NULL)
        i = AddToArray(r->lchild, arr, i);
    if(r->rchild != NULL)
        i = AddToArray(r->rchild, arr, i);

    return i;
}

int count(struct node *tree) // count nodes
{
    int c = 1;             //Node itself should be counted
    if (!tree)
        return 0;
    else
    {
        c += count(tree->lchild);
        c += count(tree->rchild);
        return c;
    }
}
