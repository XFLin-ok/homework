#include <stdio.h>
struct month
{
    char name[10];
    char short_name[3];
    int days;
    int month_num;
};

int main()
{
    struct month mon = {"January", "Jan", 31, 1};
}
