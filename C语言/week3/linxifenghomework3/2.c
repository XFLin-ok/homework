#include <stdio.h>
struct time
{
    int year;
    int month;
    int day;
};

int main()
{
    struct time t1 = {2022, 10, 1};
    printf("%d年%d月%d日\n", t1.year, t1.month, t1.day);
    int days = 0;
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((t1.year % 4 == 0 && t1.year % 100 != 0) || t1.year % 400 == 0)
    {
        month_days[1] = 29;
    }
    for (int i = 0; i < t1.month - 1; i++)
    {
        days += month_days[i];
    }
    days += t1.day;
    printf("%d日是这一年的第%d天\n", t1.day, days);
}
