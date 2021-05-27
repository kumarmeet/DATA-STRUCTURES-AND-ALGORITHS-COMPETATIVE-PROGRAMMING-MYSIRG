//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void decode(char *arr)
//{
//    char keypad[][5] = {"0 ", "1", "ABC2", "DEF3", "GHI4", "JKL5", "MNO6", "PQRS7", "TUV8", "WXYZ9", "*", "#"};
//    char ch, *str;
//    size_t size = 1;
//    int i, j = 0;
//
//    str = (char*)malloc(sizeof(char));
//
//    for(i = 0; i < strlen(arr); i++)
//    {
//        switch(arr[i])
//        {
//        case '0':
//            ch = keypad[0][1];
//            if (arr[i] == arr[i + 1])
//            {
//                ch = keypad[0][0];
//                i++;
//            }
//            break;
//        case '1':
//            ch = keypad[1][0];
//            i++;
//            break;
//        case '2':
//            ch = keypad[2][0];
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[2][1];
//                i++;
//            }
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[2][2];
//                i++;
//            }
//            if (arr[i] == arr[i + 1])
//            {
//                ch = keypad[2][3];
//                i++;
//            }
//            break;
//        case '3':
//            ch = keypad[3][0];
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[3][1];
//                i++;
//            }
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[3][2];
//                i++;
//            }
//            if (arr[i] == arr[i + 1])
//            {
//                ch = keypad[3][3];
//                i++;
//            }
//            break;
//        case '4':
//            ch = keypad[4][0];
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[4][1];
//                i++;
//            }
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[4][2];
//                i++;
//            }
//            if (arr[i] == arr[i + 1])
//            {
//                ch = keypad[4][3];
//                i++;
//            }
//            break;
//        case '5':
//            ch = keypad[5][0];
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[5][1];
//                i++;
//            }
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[5][2];
//                i++;
//            }
//            if (arr[i] == arr[i + 1])
//            {
//                ch = keypad[5][3];
//                i++;
//            }
//            break;
//        case '6':
//            ch = keypad[6][0];
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[6][1];
//                i++;
//            }
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[6][2];
//                i++;
//            }
//            if (arr[i] == arr[i + 1])
//            {
//                ch = keypad[6][3];
//                i++;
//            }
//            break;
//        case '7':
//            ch = keypad[7][0];
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[7][1];
//                i++;
//            }
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[7][2];
//                i++;
//            }
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[7][3];
//                i++;
//            }
//            if (arr[i] == arr[i + 1])
//            {
//                ch = keypad[7][4];
//                i++;
//            }
//            break;
//        case '8':
//            ch = keypad[8][0];
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[8][1];
//                i++;
//            }
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[8][2];
//                i++;
//            }
//            if (arr[i] == arr[i + 1])
//            {
//                ch = keypad[8][3];
//                i++;
//            }
//            break;
//        case '9':
//            ch = keypad[9][0];
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[9][1];
//                i++;
//            }
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[9][2];
//                i++;
//            }
//            if(arr[i] == arr[i + 1])
//            {
//                ch = keypad[9][3];
//                i++;
//            }
//            if (arr[i] == arr[i + 1])
//            {
//                ch = keypad[9][4];
//                i++;
//            }
//            break;
//        case '.':
//
//            continue;
//        }
//
//        *(str + j) = ch;
//        str = (char*)realloc(str,size * sizeof(char));
//        j++;
//    }
//
//    str[j] = '\0';
//
//    printf("%s",str);
//
//    free(str);
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decode(char *arr)
{
    char keypad[][5] = {"0 ", "1", "ABC2", "DEF3", "GHI4", "JKL5", "MNO6", "PQRS7", "TUV8", "WXYZ9", "*", "#"};
    char ch, *str;
    size_t size = 1;
    int i, j = 0,k;

    str = (char*)malloc(sizeof(char));

    for(i = 0; i < strlen(arr); i++)
    {   //if user can input only one character or string in that case we will check only one time
        //handle that kind of situation we using else break; in the loop
        switch(arr[i])
        {
        case '0':
            ch = keypad[0][1];
            if (arr[i] == arr[i + 1])
            {
                ch = keypad[0][0];
                i++;
            }
            break;
        case '1':
            ch = keypad[1][0];
            i++;
            break;
        case '2':
            ch = keypad[2][0];
            for(k = 1; k < strlen(keypad[2]); k++)
                if(arr[i] == arr[i + 1])
                {
                    ch = keypad[2][k];
                    i++;
                }
                else
                    break;
            break;
        case '3':
            ch = keypad[3][0];
            for(k = 1; k < strlen(keypad[3]); k++)
                if(arr[i] == arr[i + 1])
                {
                    ch = keypad[3][k];
                    i++;
                }
                else
                    break;
            break;
        case '4':
            ch = keypad[4][0];
            for(k = 1; k < strlen(keypad[4]); k++)
                if(arr[i] == arr[i + 1])
                {
                    ch = keypad[4][k];
                    i++;
                }
                else
                    break;
            break;
        case '5':
            ch = keypad[5][0];
            for(k = 1; k < strlen(keypad[5]); k++)
                if(arr[i] == arr[i + 1])
                {
                    ch = keypad[5][k];
                    i++;
                }
                else
                    break;
            break;
        case '6':
            ch = keypad[6][0];
            for(k = 1; k < strlen(keypad[6]); k++)
                if(arr[i] == arr[i + 1])
                {
                    ch = keypad[6][k];
                    i++;
                }
                else
                    break;
            break;
        case '7':
            ch = keypad[7][0];
            for(k = 1; k < strlen(keypad[7]); k++)
                if(arr[i] == arr[i + 1])
                {
                    ch = keypad[7][k];
                    i++;
                }
                else
                    break;
            break;
        case '8':
            ch = keypad[8][0];
            for(k = 1; k < strlen(keypad[8]); k++)
                if(arr[i] == arr[i + 1])
                {
                    ch = keypad[8][k];
                    i++;
                }
                else
                    break;
            break;
        case '9':
            ch = keypad[9][0];
            for(k = 1; k < strlen(keypad[9]); k++)
                if(arr[i] == arr[i + 1])
                {
                    ch = keypad[9][k];
                    i++;
                }
                else
                    break;
            break;
        case '.':

            continue;
        }

        *(str + j) = ch;
        str = (char*)realloc(str,size * sizeof(char));
        j++;
    }

    str[j] = '\0';
    printf("%s",str);
    free(str);
}

