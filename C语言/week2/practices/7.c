#include <stdio.h>
int main()
{
    int arry[5][5] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 4, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}};
    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", arry[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == j)
            {
                sum1 += arry[i][j];
            }
        }
    }
    printf("主对角线和：%d\n", sum1);
    for (int k = 0; k < 5; k++)
    {
        for (int s = 0; s < 5; s++)
        {
            if (k + s == 4)
            {
                sum2 += arry[k][s];
            }
        }
    }
    printf("次对角线和：%d\n", sum2);
}