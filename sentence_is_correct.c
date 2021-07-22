int is_sentence_correct(char *str)
{
    str[100];

    int i = 0, flag = 0, single_quote = 0;
    size_t len = strlen(str) - 1;

    for(int k = 0; str[k]; k++)
        if(str[k] == 39)
            single_quote++;

    if(str[0] >= 'a' && str[0] <= 'z' || str[len] != '.' || single_quote % 2 != 0)
        return -1;
    else
    {
        while(str[i])
        {
            if(str[i] == '.')
                if(str[i + 2] >= 'a' && str[i + 2] <= 'z')
                    return -1;
                else
                    flag = 1;
            i++;
        }

        if(flag)
            return 1;
    }
}
