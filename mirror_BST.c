struct node 
{ 
    int data; 
    struct node  *lchild;
    struct node  *rchild; 
};
int mirror(struct node* first,struct node * second)
{
/* Base case : Both empty */
    if (first == NULL && second ==NULL)
        return 1;
 
    // If only one is empty
    if (first == NULL || second == NULL)
        return 0;
 
    /* Both non-empty, compare them recursively
     Note that in recursive calls, we pass left
     of one tree and right of other tree */
    return  first->data == second->data &&
            mirror(first->lchild, second->rchild) &&
            mirror(first->rchild, second->lchild);
}
