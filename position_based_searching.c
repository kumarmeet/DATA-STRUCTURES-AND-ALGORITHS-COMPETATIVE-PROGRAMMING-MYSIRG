#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[200] = "";
    char pos[5] ="";
    char temp[20] = "";
    char ch = '\0';
    size_t len;
    char final_string[40] = "";
    int i = 0, j = 0, k = 0, l = 0, count_ = 0, twoDarray_size = 1;

    gets(str);
    gets(pos);

    for(i = 0; str[i]; i++)
    {
        if(str[i] == ' ')
            twoDarray_size++;
    }

    char new_string[5][20] = {"\0"};

    if(pos[0] >= 'a' && pos[0] <= 'z') //check _(underscore) after character
    {
        for(i = 0; pos[i]; i++)
        {
            if(pos[i] == '_')
                count_++;

            if(pos[i] != '_')
                ch = pos[i];
        }

        char temp;

        for(i = 0; i < strlen(pos) / 2; i++)
        {
            temp = pos[i];
            pos[i] = pos[i + 1];
            pos[i] = temp;
        }

        len = strlen(str) - 1;

        for(j = 0; j < strlen(str) / 2; j++)
        {
            temp = str[len];
            str[len] = str[j];
            str[j] = temp;
            len--;
        }

        j = 0;
        for(i = 0; i < twoDarray_size; i++)
        {
            while(str[j] != ' ' && str[j] != '\0')
            {
                new_string[i][k] = str[j];
                j++;
                k++;
            }
            k = 0;
            if(len == j)
                break;
            j++;
        }

        k = 0;

        for(i = 0; i < twoDarray_size; i++)
        {
            while(new_string[i])
            {
                if(ch == new_string[i][count_])
                {
                    final_string[l] = new_string[i][k];
                    k++;
                    l++;
                }

                if(new_string[i][k] == '\0' || ch != new_string[i][count_])
                {
                    k = 0;
                    break;
                }
            }

            final_string[l++] = ' ';
        }

        len = strlen(final_string) - 1;

        for(j = 0; j < strlen(final_string) / 2; j++)
        {
            temp = final_string[len];
            final_string[len] = final_string[j];
            final_string[j] = temp;
            len--;
        }
    }
    else if(pos[strlen(pos) - 1] >= 'a' && pos[strlen(pos) - 1] <= 'z') //check _(underscore) before character
    {
        for(i = 0; i < strlen(pos); i++)
        {
            if(pos[i] == '_')
                count_++;

            if(pos[i] != '_')
                ch = pos[i];
        }

        for(i = 0; i < 5; i++)
        {
            while(str[j] != ' ' && str[j] != '\0')
            {
                new_string[i][k] = str[j];
                j++;
                k++;
            }
            k = 0;
            if(len == j)
                break;
            j++;
        }

        k = 0;

        for(i = 0; i < twoDarray_size; i++)
        {
            while(new_string[i])
            {
                if(ch == new_string[i][count_])
                {
                    final_string[l] = new_string[i][k];
                    k++;
                    l++;
                }

                if(new_string[i][k] == '\0' || ch != new_string[i][count_])
                {
                    k = 0;
                    break;
                }
            }
            final_string[l++] = ' ';
        }

    }

    trim(final_string);

    return 0;
}

void trim(char *str)
{
    int i, j = 0;
    char space = ' ';
    char trim_str[100] = "";

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

    for(i = 0; trim_str[i]; i++)
    {
        if(trim_str[i] == ' ')
            printf("\n");
        else
            printf("%c", trim_str[i]);
    }
}
