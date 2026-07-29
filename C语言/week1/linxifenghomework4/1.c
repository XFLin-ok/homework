#include <stdio.h>
int main()
{
    int num = 0;
    int sum = 0;
    printf("请输入一个整数：");
    scanf("%d", &num);
    sum = num + 10;
    for (num; num <= sum; num++)
    {
        printf("输入值（含）到比输入值大10（含）的所有整数值为%d\n", num);
    }
}