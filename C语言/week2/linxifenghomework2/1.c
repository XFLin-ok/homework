// 1. 三角形判断
// 题目描述：
// 输入三个整数作为三角形的三条边长，判断它们能否构成一个三角形。
// 如果能构成三角形，进一步判断它是等边三角形、等腰三角形还是普通三角形。
// 如果不能构成，输出“不是三角形”。
// 考察点： 逻辑与 &&，逻辑或 ||，if-else-if 多重嵌套结构。
#include <stdio.h>
int main()
{
    int a = 0, b = 0, c = 0;
    printf("输入三个整数作为三角形的变长：");
    scanf("%d %d %d", &a, &b, &c);
    if (a + b > c)
    {
        if (a == b && b == c)
        {
            printf("等边三角形\n");
        }
        else if (a == b || b == c || a == c)
        {
            printf("等腰三角形\n");
        }
        else
            printf("普通三角形\n");
    }
    else
        printf("不是三角形\n");

    return 0;
}