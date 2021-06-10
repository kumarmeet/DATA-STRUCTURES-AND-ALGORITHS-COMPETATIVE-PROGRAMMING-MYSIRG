struct node
{
  int d;
  struct node * next;
};

void sort(struct node * list)
{
  int temp;
    struct node *l1, *i1 = NULL;
    l1 = list;

    while(l1)
    {
        i1 = l1->next;

        while(i1)
        {
            if(l1->d > i1->d)
            {
                temp = l1->d;
                l1->d = i1->d;
                i1->d = temp;
            }
            i1 = i1->next;
        }
        l1 = l1->next;
    }
}  