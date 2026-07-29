#include <stdio.h>

struct student
{
    char name[20];
    float chinese;
    float math;
    float english;
};
struct student stu[5] = {{"张三", 85.5, 92.0, 78.5}, {"李四", 87.5, 67.0, 78.5}, {"王五", 98.5, 66.0, 66.5}, {"赵六", 87.5, 78.0, 98.5}, {"钱七", 67.5, 87.0, 78.5}};

int main()
{
    struct student *p = stu;
    for (int i = 0; i < 5; i++)
    {
        printf("姓名：%s语文：%.1f 数学：%.1f 英语：%.1f\n", p->name, p->chinese, p->math, p->english);
        p++;
    }
}
