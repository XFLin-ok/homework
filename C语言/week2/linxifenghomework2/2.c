// 2. 月份天数查询
// 题目描述：
// 输入年份和月份，输出该月有多少天。
// 注意区分大小月（1,3,5,7,8,10,12月为31天；4,6,9,11月为30天）。
// 2月需要判断闰年（闰年规则：能被4整除但不能被100整除，或者能被400整除）。
// 考察点： switch-case 语句，特别是 case 穿透特性的运用。
#include <stdio.h>
int main()
{
    int year = 0;
    int month = 0;
    printf("请输入年份和月份：\n");
    scanf("%d %d", &year, &month);
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("%d月份有31天\n", month);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("%d月份有30天\n", month);
        break;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            printf("%d年为闰年,%d月为29天\n", year, month);
        else
            printf("%d年不是闰年,%d月为28天\n", year, month);
        break;
    default:
        printf("输入的年份月份有误\n");
        break;
    }
}