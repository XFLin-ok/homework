// 8. 打印九九乘法表
// 题目描述：
// 在屏幕上打印格式化的九九乘法表，要求对齐整齐。
// 考察点： 双重 for 循环（嵌套循环），printf 格式化输出。
#include <stdio.h>
int main()
{
    int a = 0, b = 0, i = 0;
    for (int j = 1; j <= 9; j++)
    {

        for (int i = 1; i <= j; i++)
        {
            printf("%d*%d=%d  ", i, j, i * j);
        }
        printf("\n");
    }
}