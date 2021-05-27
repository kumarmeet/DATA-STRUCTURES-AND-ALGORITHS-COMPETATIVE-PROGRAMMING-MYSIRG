#include <stdio.h>
#include <stdlib.h>

void count_apples(int *V, int *A, int v_diameter, int a_diameter)
{
    int i, k = 0, l = 0, m = 0;
    size_t size = 1;
    int *apple_count = (int*)malloc(sizeof(int));

    for(i = 0; i < v_diameter; i++)
    {
        while(l < a_diameter)
        {
            if(*(V + i) >= *(A + l))
            {
                k++;
                l++;
                if(k == 3)
                {
                    break;
                }
                continue;
            }
            else
            {
                apple_count = (int*)realloc(apple_count,size * sizeof(int));
                *(apple_count + m) = l;
                m++;
                size++;
                l++;
            }

        }
        k = 0;
    }

    for(i = 0; i < size - 1; i++)
        printf("%d ",*(apple_count + i));

    free(apple_count);
    return;
}

//void count_apples(int *V, int *A, int v_diameter, int a_diameter)
//{
//    int i, k = 0, l = 0, m = 0;
//    int v_diameter, a_diameter;
//
//    size_t size = 1;
//
//    scanf("%d %d",&v_diameter, &a_diameter);
//
//    int *V = (int*)malloc(v_diameter * sizeof(int));
//    int *A = (int*)malloc(a_diameter * sizeof(int));
//    int *apple_count = (int*)malloc(sizeof(int));
//
//    for(i = 0; i < v_diameter; i++)
//        scanf("%d",(V + i));
//
//    for(i = 0; i < a_diameter; i++)
//        scanf("%d",(A + i));
//
//    for(i = 0; i < v_diameter; i++)
//    {
//        while(l < a_diameter)
//        {
//            if(*(V + i) >= *(A + l))
//            {
//                k++;
//                l++;
//                if(k == 3)
//                {
//                    break;
//                }
//                continue;
//            }
//            else
//            {
//                apple_count = (int*)realloc(apple_count,size * sizeof(int));
//                *(apple_count + m) = l;
//                m++;
//                size++;
//                l++;
//            }
//
//        }
//        k = 0;
//    }
//
//    for(i = 0; i < size - 1; i++)
//        printf("%d ",*(apple_count + i));
//
//    free(V);
//    free(A);
//    free(apple_count);
//
//}
