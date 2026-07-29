#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct contactList
{
    char stu_num[11];
    char name[10];
    int age;
    char phone_num[12];
};

int main()
{
    char select[11] = {0};
    char select1[11] = {0};

    struct contactList cont[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            printf("第一个同学的信息：\n");
            break;
        case 1:
            printf("第二个同学的信息：\n");
            break;
        case 2:
            printf("第三个同学的信息：\n");
            break;

        default:
            break;
        }
        printf("请输入学号：\n");
        scanf("%s", cont[i].stu_num);
        printf("请输入姓名：\n");
        scanf("%s", cont[i].name);
        printf("请输入年龄：\n");
        scanf("%d", &cont[i].age);
        printf("请输入电话号码：\n");
        scanf("%s", cont[i].phone_num);
    }
    printf("------------------------------------------------");
    printf("请输入需要寻找的同学的学号：\n");
    scanf("%s", select);
    for (int k = 0; k < 3; k++)
    {
        if (strcmp(cont[k].stu_num, select) == 0)
        {
            printf("学号为%s的同学信息:\n", cont[k].stu_num);
            printf("学号：%s\n", cont[k].stu_num);
            printf("姓名：%s\n", cont[k].name);
            printf("年龄：%d\n", cont[k].age);
            printf("电话号码：%s\n", cont[k].phone_num);
        }
    }
    printf("------------------------------------------------");
    printf("请输入需要寻找的同学的姓名：\n");
    scanf("%s", select);
    for (int k = 0; k < 3; k++)
    {
        if (strcmp(cont[k].name, select) == 0)
        {
            printf("姓名为%s的同学信息:\n", cont[k].name);
            printf("学号：%s\n", cont[k].stu_num);
            printf("姓名：%s\n", cont[k].name);
            printf("年龄：%d\n", cont[k].age);
            printf("电话号码：%s\n", cont[k].phone_num);
        }
    }
    printf("------------------------------------------------");
    printf("请输入需要更新信息的同学的学号\n");
    scanf("%s", select1);
    for (int z = 0; z < 3; z++)
    {
        if (strcmp(cont[z].stu_num, select1) == 0)
        {
            printf("请更新学号为%s,同学的信息\n", cont[z].stu_num);
            printf("学号更新为：\n");
            scanf("%s", cont[z].stu_num);
            printf("姓名更新为：\n");
            scanf("%s", cont[z].name);
            printf("年龄更新为：\n");
            scanf("%d", &cont[z].age);
            printf("电话更新为：\n");
            scanf("%s", cont[z].phone_num);
            break;
        }
    }

    for (int j = 0; j < 3; j++)
    {
        printf("第%d个同学的信息:\n", j + 1);
        printf("学号：%s\n", cont[j].stu_num);
        printf("姓名：%s\n", cont[j].name);
        printf("年龄：%d\n", cont[j].age);
        printf("电话：%s\n", cont[j].phone_num);
    }
    return 0;
}
