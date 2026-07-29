// 输入某年某月某日，判断这一天是这一年的第几天？
#include <stdio.h>
int main()
{
    int year = 0, month = 0, day = 0, days = 0;
    printf("输入某年某月某日:");
    scanf("%d %d %d", &year, &month, &day);
    int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        mon[1] = 29;
    for (int i = 0; i < month - 1; i++)
        days += mon[i];
    days += day;
    printf("%d年%d月%d日是当年的第%d天\n", year, month, day, days);
}