#include <stdio.h>
int main()
{
    int a = 0, b = 0;
    float sum = 0;
    char c;
    printf("请输入两个整数和一个运算符(+,-,*,/)\n");
    scanf("%d %d %c", &a, &b, &c);
    if (c == '+')
    {
        printf("%d\n", a + b);
    }
    else if (c == '-')
    {
        printf("%d\n", a - b);
    }
    else if (c == '*')
    {
        printf("%d\n", a * b);
    }
    else if (c == '/')
    {
        if (b == 0)
        {

            printf("除数不能为零\n");
        }
        sum = (float)a / b;
        printf("%.2f\n", sum);
    }

    else
    {
        printf("输入有误\n");
    }

    return 0;
}