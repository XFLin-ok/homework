#include <stdio.h>
int main()
{
    int a = 0;
    int b = 0;
    printf("请输入两个数据（a行b列）：");
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}