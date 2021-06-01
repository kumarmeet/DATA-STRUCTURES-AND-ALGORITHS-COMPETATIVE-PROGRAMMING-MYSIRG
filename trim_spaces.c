#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim(char *str)
{
    int i, j = 0;
    char space = ' ';
    char trim_str[100] = "";

    gets(str);

    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] != space)
        {
            trim_str[j] = str[i];
            j++;
            if(str[i+1] == space)
            {
                trim_str[j] = space;
                j++;
            }
        }
    }

    trim_str[j] = '\0';

    puts(trim_str);
}
