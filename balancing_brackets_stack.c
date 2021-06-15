#include <stdlib.h>
#include <stdio.h>
#include <string.h>

main()
{
    int n, i = 0, flag = 0, k = -1, j, temp;
    char arr[20] = "";
    gets(arr);  //instance of input like [[[{{()}}]}]
    char stack[10] = "";

    //this sorting for arranging brackets properly open brackets after closing brackets
    for(i = 0; i < strlen(arr); i++)
    {
        for(j = i + 1; j < strlen(arr); j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            }
        }
    }
    //after sorting brackets looks like ()[[[]]{{}}}

    i = 0;

    while(arr[i])
    {
        if(arr[i] == '[' || arr[i] == '{' || arr[i] == '(')
        {
            k++;
            stack[k] = arr[i]; // push
        }
        else if(arr[i] == ']' && stack[k] == '[')
        {
            stack[k] = '0'; //pop
            k--;
        }
        else if(arr[i] == '}' && stack[k] == '{')
        {
            stack[k] = '0'; //pop
            k--;
        }
        else if(arr[i] == ')' && stack[k] == '(')
        {
            stack[k] = '0'; //pop
            k--;
        }
        i++;
    }


    if(stack[0] == '0') // if stack last value is '0' that means stack is empty
        printf("%d",1);
    else
        printf("%d",-1);

    return 0;
}