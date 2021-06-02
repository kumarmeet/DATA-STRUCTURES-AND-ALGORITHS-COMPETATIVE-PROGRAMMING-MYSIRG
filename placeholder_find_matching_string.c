#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * rev(char *, int);

int main(void)
{
    char str[200] = "";
    char f[20] = "";
    char wildcard[40] = "";
    char temp[20] = "";
    char symbol = '%', reverse;
    int i = 0, j = 0, k = 0, l = 0, m = 0;
    int len;

    gets(str);
    gets(f);

    if(symbol == f[0])
    {
        for(j = 0; j < strlen(f); j++)
            f[j] = f[j + 1];

        while(1)
        {
            if(str[i] != ' ' && str[i] != '\0')
            {
                temp[m] = str[i];
                i++;
                m++;
                continue;
            }

            if(strncmp(temp, f, strlen(f)) == 0)
            {
                for(k = 0; k < strlen(temp); k++)
                {
                    if(temp[k] != '0')
                    {
                        wildcard[l] = temp[k];
                        l++;
                    }
                }
                wildcard[l++] = ' ';
            }

            m = 0 ;
            i++;

            for(k = 0; k < strlen(temp); k++)
                temp[k] = '0';

            if(str[i] == '\0')
            {
                wildcard[l] = '\0';
                break;
            }
        }
    }
    else if(symbol == f[strlen(f) - 1])
    {
        len = strlen(str) - 1;
        str[0] = rev(str, len);

        len = strlen(f) - 1;
        f[0] = rev(f, len);

        puts(str);

        for(j = 0; j < strlen(f); j++)
            f[j] = f[j + 1];

        while(1)
        {
            if(str[i] != ' ' && str[i] != '\0')
            {
                temp[m] = str[i];
                i++;
                m++;
                continue;
            }

            if(strncmp(temp, f, strlen(f)) == 0)
            {
                for(k = 0; k < strlen(temp); k++)
                {
                    if(temp[k] != '0')
                    {
                        wildcard[l] = temp[k];
                        l++;
                    }
                }
                wildcard[l++] = ' ';
            }

            m = 0 ;
            i++;

            for(k = 0; k < strlen(temp); k++)
                temp[k] = '0';

            if(str[i] == '\0')
            {
                wildcard[l] = '\0';
                break;
            }
        }

        len = strlen(wildcard) - 2;
        wildcard[0] = rev(wildcard, len);
    }

    for(i = 0; wildcard[i]; i++)
    {
        if(wildcard[i] == ' ')
            printf("\n");
        else
            printf("%c", wildcard[i]);
    }

    return 0;
}