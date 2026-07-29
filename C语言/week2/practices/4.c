#include <stdio.h>
int main()
{
    int arry[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 9; i >= 0; i--)
    {

        printf("arry[%d]=%d\n", i, arry[i]);
    }

    printf("------------------------------------------------------------------------------------\n");

    int arry2[10] = {11, 2, 34, 4, 51, 65, 762, 812, 9, 10};
    int max = arry2[0];
    int min = arry2[0];
    for (int j = 1; j < 10; j++)
    {
        if (arry2[j] > max)
        {
            max = arry2[j];
        }
        if (arry2[j] < min)
        {
            min = arry2[j];
        }
    }
    printf("max=%d,min=%d\n", max, min);

    printf("------------------------------------------------------------------------------------\n");
    int arry3[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tmp;
    int k;
    for (int k = 0; k < 10; k++)
    {

        printf("交换前arry3[%d]=%d\n", k, arry3[k]);
    }

    for (int k = 0; k < 5; k++)
    {
        tmp = arry3[k];
        arry3[k] = arry3[9 - k];
        arry3[9 - k] = tmp;
    }
    for (int k = 0; k < 10; k++)
    {

        printf("交换后arry3[%d]=%d\n", k, arry3[k]);
    }
}
