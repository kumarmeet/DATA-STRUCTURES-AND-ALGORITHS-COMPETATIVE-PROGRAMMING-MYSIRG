#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void required_Birds(char *str)
{
    char ch;
    int  i = 0, j, count = 0;
    size_t size = 1;

    //dynamically array of string created
    str = (char*)malloc(sizeof(char));
    while(ch != '\n')
    {
        ch = getc(stdin);
        str = (char*)realloc(str,size * sizeof(char));
        *(str + i) = ch;
        size++;
        i++;
    }

    *(str + i) = '\0'; //when string input is completed then assign NUL

    size = strlen(str);

    for(i = 0; str[i]; i++)
    {
        for(j = i + 1; j < size; j++)
        {   //if string has same character constant then assign '0'
            if(str[i] == str[j])
            {
                str[i] = '0';
                str[j] = '0';
            }
        }
    }

    i = 0;

    while(str[i])
    {   //avoid string if it has '0' in the string
        if(str[i] != '0' && str[i] != '\n')
            count++;
        i++;
    }

    printf("%d",count);
}
