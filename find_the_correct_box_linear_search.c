#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char boxes[200] = "";
    char medicines[20] = "";
    int i;

    gets(boxes);
    gets(medicines);

    for(i = 1; i <= strlen(boxes); i++)
        if(boxes[i - 1] == medicines[0])
            printf("%d ", i);

    return 0;
}

