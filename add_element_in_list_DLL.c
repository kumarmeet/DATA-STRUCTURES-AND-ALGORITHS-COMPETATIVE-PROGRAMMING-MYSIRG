struct DLL
{
    struct DLL *pre;
    int data;
    struct DLL *next;
};

int main()
{
    struct DLL *start = NULL;
    int i;
    char str[100] = "";
    gets(str);

    for(i = 0; i < strlen(str); i++)
        insert_DLL(&start, str[i]);

    add_string_numbers_before_zero(start, str);

    return 0;
}

void add_string_numbers_before_zero(struct DLL *s, char *str)
{
    struct DLL *t;
    t = s;
    int sum = 0;

    while(t->next != NULL)
        t = t->next;

    while(t->data != '0')
        t = t->pre;

    while(s != t)
    {
        t = t->pre;

        if(t->data >= '1' && t->data <= '9')
        {
            printf("%c ", t->data);
            sum += (t->data - '0');
        }
    }

    printf("\n%d", sum);
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
