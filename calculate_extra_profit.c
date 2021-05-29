#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate_extra_profit(char *art_piece, int n, int price_of_pair)
{
    int i = 0, j = 0, k = 0, l = 0, pp = 1;
    int single = 0, profit, pair = 0;

    art_piece[n];
    char temp, str[n];

    pp = (n * price_of_pair) / 2;

    for(i = 0; art_piece[i]; i++)
    {
        for(j = i + 1; j < strlen(art_piece); j++)
        {
            if(art_piece[i] == art_piece[j])
            {
                temp = art_piece[j];
                //this is for right shift logic
                for(k = j; k > 0; k--)
                {
                    art_piece[k] = art_piece[k - 1];
                    if(art_piece[i] == art_piece[i + 1])
                        break;
                }
                i++;
                break;
            }
        }
    }
    //this is for copy of same pair from art_piece to str
    for(i = 0; i < strlen(art_piece); i++)
    {
        if(art_piece[i] == art_piece[i + 1])
        {
            str[l] = art_piece[i];
            str[l + 1] = art_piece[i + 1];
            l = l + 2;
            art_piece[i] = art_piece[i + 1] ='0';
            pair++;
        }
    }

    //this is for copy rest of the single character from art_piece to str
    for(i = 0; art_piece[i]; i++)
    {
        if(art_piece[i] != '0')
        {
            str[l] = art_piece[i];
            l++;
            art_piece[i] ='0';
            single++;
        }
    }

    str[n + 1] = '\0'; // insert nul in last index + 1

    puts(str);

    profit = (pair * price_of_pair) + ((single * price_of_pair) / 2) + (10 * single) - pp;

    printf("%d",profit);
}
