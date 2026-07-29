#include <stdio.h>
int main()
{
    int num = 0;
    int a = 0, b = 0, c = 0, d = 0;
    printf("请输入一个三位数：");
    scanf("%d", &num);
    a = num / 100;
    b = num / 10;
    c = b % 10;
    d = num % 10;
    printf("三位数%d,百位为：%d,十位为:%d,个位为：%d\n", num, a, c, d);
}