#include <stdio.h>
int main()
{
    int age = 0;
    float second = 0;
    printf("请输入你的年龄:");
    scanf("%d", &age);
    second = age * 3.1536e7;
    printf("你的年龄等于%f秒", second);
    return 0;
}