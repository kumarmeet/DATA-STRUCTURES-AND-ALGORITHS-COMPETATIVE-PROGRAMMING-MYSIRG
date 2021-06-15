#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, i, k = 0, l, flag = 0;
    scanf("%d", &n);
    int arr[n];

    for(i = 0; i < n; ++i)
        scanf("%d",&arr[i]);

    int search, interval;

    scanf("%d%d", &search, &interval);

    for(i = 0; i < n; i++)
    {
        k = arr[i] + interval;

        if(arr[k] > search)
        {
            interval = interval / 2;

            for(l = interval; l > 0; l--)
                if(arr[l] == search)
                {
                    flag = l;
                    break;
                }
        }
        if(flag)
        {
            printf("%d", flag);
            break;
        }

        if(search == arr[k])
        {
            printf("%d", k);
            break;
        }
    }
    return 0;
}

