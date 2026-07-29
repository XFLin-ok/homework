#include <stdio.h>

int main()
{
    int num, i;
    int a = 1;

    printf("请输入一个整数：");
    scanf("%d", &num);

    if (num <= 1)
    {
        a = 0;
    }

    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            a = 0;
            break;
        }
    }

    if (a)
    {
        printf("%d 是素数\n", num);
    }
    else
    {
        printf("%d 不是素数\n", num);
    }

    return 0;
}