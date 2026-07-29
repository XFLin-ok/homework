#include <stdio.h>
#define MAX 1000
#define MIN 0
struct student
{
    int a;

} stu1;
typedef int z_x;
typedef struct student
{
    int a;

} stu;
typedef struct student
{
    int a;

} *stu2;

int main()
{
    z_x num = 0;
    printf("输入一个数字\n");
    scanf("%d", &num);
    if (num >= MIN && num <= MAX)
    {
        printf("在范围内\n");
    }
    else
    {
        printf("不在范围内\n");
    }

    stu stu1 = {10};
    stu2 p = stu1.a;
    printf("%d", p->a);
}