#include <stdio.h>
int main()
{
    int a = 0, b = 0, c = 0;
    printf("请输入三个数：");
    scanf("%d %d %d", &a, &b, &c);
    if (a > b)
    {

        printf("最大值为：%d\n", a);
    }
    else if (b > c)
    {
        printf("最大值为b:%d\n", b);
    }
    else
        printf("最大值为c:%d\n", c);
}