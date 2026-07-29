// 7. 寻找素数
// 题目描述：
// 输入一个整数 n，判断它是否为素数（质数）。素数是指只能被1和它本身整除的大于1的整数，并输出小于该数的所有素数。
// 考察点： for 循环，if 判断，标志位的使用，break 的优化。

#include <stdio.h>
int main()
{
    int n = 1;
    printf("输入一个整数：");
    scanf("%d", &n);
    for (int i; i < n; i++)
    {
        if (n % i != 0)
        {
            printf("%d为素数", n);
            for (int j = 0; j < i; j++)
            {
            }
        }
        else
        {
            printf("%d不为素数", n);
        }
    }
}