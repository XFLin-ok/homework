#include <stdio.h>
int main()
{
    int num = 0;
    while (1)
    {
        printf("输入需要查找的信息：1.注册学生信息，2.查找学生信息，3.删除学生信息，4.修改学生信息，5.退出\n");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            printf("注册学生信息\n");
            break;
        case 2:
            printf("查找学生信息\n");

            break;
        case 3:
            printf("删除学生信息\n");

            break;
        case 4:
            printf("修改学生信息\n");
            break;
        case 5:
            printf("退出\n");
            break;

        default:
            printf("输入有误！\n");
            break;
        }
    }
}