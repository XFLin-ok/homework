#include <stdio.h>
#define MIN 60
int main()
{
    int hour = 0;
    int min = 0;
    int n = 0;
    printf("请输入一个分钟数：\n");
    scanf("%d", &n);
    hour = n / MIN;
    min = (n % MIN);
    printf("分钟数%d共有%d小时,%d分钟\n", n, hour, min);
    return 0;
}