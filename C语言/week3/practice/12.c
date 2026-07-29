#include <stdio.h>
#include "student.h"
#include "teacher.h"
#include "teachers.h"
int main()
{
    struct student stu1 = {"小米", 22, "男"};
    struct teacher t1 = {"陈老师", 32, "男"};
    struct teachers ts1 = {100, "数学老师"};
    printf("%s\n", stu1.name);
    printf("%d\n", stu1.age);
    printf("%s\n", stu1.sex);
    printf("%s\n", t1.name);
    printf("%d\n", t1.age);
    printf("%s\n", t1.sex);
    printf("%d\n", ts1.num);
    printf("%s\n", ts1.type);
}