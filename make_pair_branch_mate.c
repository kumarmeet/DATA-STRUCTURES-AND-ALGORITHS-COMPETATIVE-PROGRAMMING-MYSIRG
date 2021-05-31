#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void makepair(char *p)
{
    char *str2 = (char*)malloc(sizeof(char));
    int i, j = 0, k = 0, count = 2, flag = 0;
    size_t size = 0;

    for(i = 0; i < strlen(p); i++)
    {
        if(p[i] == p[i + 1])
        {
            for(j = 0; j < count; j++)
            {
                str2[k] = p[i];
                size++;
                str2 = (char*)realloc(str2, size * sizeof(char));
                k++;
                flag = 1;
            }
            i++;
        }
    }

    str2[size] = '\0';

    if(flag)
        puts(str2);
    else
        printf("0");
}

