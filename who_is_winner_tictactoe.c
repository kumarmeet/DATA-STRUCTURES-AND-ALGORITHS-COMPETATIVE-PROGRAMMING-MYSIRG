#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[3][3];

    int i, j, winner = 3;

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        scanf("%d",&arr[i][j]);


    //rows
    for(i = 0; i < 3; i++)
    {
        if(arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2])
            {
                winner = arr[i][2];
                break;
            }
    }

    //colums
    for(i = 0; i < 3; i++)
    {
        if(arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])
            {
                winner = arr[2][i];
                break;
            }
    }

    //diagonals
    if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
        winner = arr[2][2];

    if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
        winner = arr[2][0];


    if(winner == 1)
        printf("%d", winner);
    else if(winner == 0)
        printf("%d", winner);
    else
        printf("%d", -1);

    return 0;
}