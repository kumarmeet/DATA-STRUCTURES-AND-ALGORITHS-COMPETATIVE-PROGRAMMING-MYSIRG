#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void expand_string_to_original(char *str)
{
    int i = 0, j = 0, k = 0, m;
    size_t size = 1;
    char ch;
    char str1[50];

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

//    1->g 2->o 1->d 0(spcae) 1->1 1->2 1->3
//    good 123

    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] == '0')
        {
            str1[k] = ' ';
            k++;
            continue;
        }

        if(str[i] >= '1' && str[i] <= '9')
        {
            m = str[i] - '0'; //this logic is for convert character to number
            for(j = 0; j < m; j++)
            {
                str1[k] = str[i + 1];
                k++;
            }
            i++;
        }

        str1[k + 1] = '\0';
    }

    free(str);
    puts(str1);
}
