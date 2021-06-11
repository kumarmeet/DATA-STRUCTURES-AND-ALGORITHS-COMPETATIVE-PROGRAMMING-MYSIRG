struct DLL
{
    struct DLL *pre;
    int data;
    struct DLL *next;
};

main()
{
    struct DLL *start = NULL;
    int i, n, undo;

    scanf("%d", &n);

    int item[n];

    for(i = 1; i <= n; i++)
        scanf("%d", &item[i]);

    for(i = 1; i <= n; i++)
        insert_DLL(&start, item[i]);

    scanf("%d", &undo);

    undo_operations(&start, undo);

    return 0;
}

void undo_operations(struct DLL **s, int undo)
{
    struct DLL *t, *r;
    int sum = 0;
    t = *s;

    while(t->next != NULL)
    {
        t = t->next;
    }

    while(undo)
    {
        r = t;
        t = r->pre;
        t->next = NULL;
        free(r);
        --undo;
    }

    while(*s)
    {
        sum += (*s)->data;
        (*s) = (*s)->next;
    }

    printf("%d",sum);
}

void insert_DLL(struct DLL **s, int item)
{
    struct DLL *t, *r;
    r = (struct DLL*)malloc(sizeof(struct DLL));
    r->data = item;
    r->next = NULL;

    if(*s == NULL)
    {
        r->pre = NULL;
        *s = r;
    }
    else
    {
        t = *s;
        while(t->next != NULL)
            t = t->next;

        r->pre = t;
        t->next = r;
    }
}