#include <stdio.h>
#define WEEK 7
int main()
{
    int weeks = 0;
    int num = 0;
    int days = 0;
    printf("请输入天数：");
    scanf("%d", &num);
    weeks = num / WEEK;
    days = num % WEEK;
    printf("%ddays are %dweeks,%ddays", num, weeks, days);
}