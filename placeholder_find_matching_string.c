#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
     char str[200];
    char f[20] ="";
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
        for(j = 0; j < strlen(str) / 2; j++)
        {
            reverse = str[len];
            str[len] = str[j];
            str[j] = reverse;
            len--;
        }

        len = strlen(f) - 1;
        for(j = 0; j < strlen(f) / 2; j++)
        {
            reverse = f[len];
            f[len] = f[j];
            f[j] = reverse;
            len--;
        }

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
        for(j = 0; j < strlen(wildcard) / 2; j++)
        {
            reverse = wildcard[len];
            wildcard[len] = wildcard[j];
            wildcard[j] = reverse;
            len--;
        }
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
