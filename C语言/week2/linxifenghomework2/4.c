// 4. 最大公约数与最小公倍数
// 题目描述：
// 输入两个正整数，求它们的最大公约数（GCD）和最小公倍数（LCM）。
// 提示：最小公倍数 = (两数乘积) / 最大公约数。
// 考察点： while 循环（推荐使用辗转相除法）或 for 循环。
#include <stdio.h>
int main()
{
    int a = 0, a1 = 0, b = 0, b1 = 0, i = 0;
    printf("输入两个整数\n");
    scanf("%d %d", &a1, &b1);
    a = a1;
    b = b1;
    if (a >= b)
    {
        for (i = b; a % i == 0 && b % i == 0 && i <= b; b--)
        {
            printf("最大公约数：%d\n", i);
        }
    }
    if (a < b)
    {
        for (i = a; a % i == 0 && b % i == 0 && i <= a; a--)
        {
            printf("最大公约数：%d\n", i);
        }
    }
    printf("最小公倍数：%d\n", (a1 * b1) / i);
}