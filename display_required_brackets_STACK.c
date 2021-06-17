#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0, flag = 0, k = -1, j, count = 0;
    char arr[20];
    char stack[12] = "";
    char brackets[] = "(){}[]";

    gets(arr);

    //check pair of brackets and replace 0 char into arr string
    while(arr[i])
    {
        if(arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
        {
            for(j = i + 1; arr[j]; j++)
            {
                if(arr[i] == '(' && arr[j] == ')')
                {
                    arr[j] = '0';
                    arr[i] = '0';
                    break;
                }
                if(arr[i] == '{' && arr[j] == '}')
                {
                    arr[j] = '0';
                    arr[i] = '0';
                    break;
                }
                if(arr[i] == '[' && arr[j] == ']')
                {
                    arr[j] = '0';
                    arr[i] = '0';
                    break;
                }
            }
        }
        i++;
    }

    //insert opposite brackets from arr to stack
    for(i = 0; arr[i]; i++)
        if(arr[i] != '0')
        {
            if(arr[i] == '(')
                stack[++k] = ')';
            else if(arr[i] == ')')
                stack[++k] = '(';
            else if(arr[i] == '{')
                stack[++k] = '}';
            else if(arr[i] == '}')
                stack[++k] = '{';
            else if(arr[i] == '[')
                stack[++k] = ']';
            else if(arr[i] == ']')
                stack[++k] = '[';
        }

        //check brackets and stack element are equal or not
    for(i = 0; brackets[i]; i++)
    {
        for(j = 0; stack[j]; j++)
            if(brackets[i] == stack[j])
                count++;
        if(count > 0)
            printf("%c %d\n", brackets[i], count);
        else
            printf("%c %d\n",brackets[i], 0);
        count = 0;
    }

    return 0;
}
