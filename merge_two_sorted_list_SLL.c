struct node
{
  int d;
  struct node * next;
};
void mergelist(struct node* list1,struct node* list2,struct node* list3)
{
  	struct node *t;
    t = list3 = list1;

    while(1)
    {
        while(t)
        {
            if(t->d == list2->d)
                list2 = list2->next;
            t = t->next;
        }
        if(t == NULL)
            break;
    }

    t = list1;

    while(t->next != NULL)
        t = t->next;

    t->next = list2;
  
  printlist(list3); //this call prints the list3 elements so do not remove it. 
}

void printlist(struct node *s)
{
    while(s)
    {
        printf("%d ", s->d);
        s = s->next;
    }
}