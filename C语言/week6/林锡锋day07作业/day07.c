#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int login(char password[10])
{
    char num[10] = {0};
    for (int i = 0; i < 3; i++)
    {
        printf("请输入登录密码：\n");
        scanf("%s", num);
        if (strcmp(password, num) == 0)
        {
            int a;
            printf("登录成功！密码长度%ld\n", strlen(num));

            return 1;
        }
        else
        {
            if (i == 2)
            {
                printf("错误过多！！\n");
                return 0;
            }
            printf("密码错误，请重新输入密码!!!\n");
        }
    }
}
int modify(char password[10])
{
    char num1[10] = {0};
    char num2[10] = {0};
    printf("请输入新密码：\n");
    scanf("%s", num1);
    printf("请再次输入新密码：\n");
    scanf("%s", num2);
    if (strcmp(num1, num2) == 0)
    {
        strcpy(password, num2);
        printf("密码修改成功！新密码：%s\n", password);
    }
    else
    {
        printf("两次输入不一致，退出！\n");
        return 0;
    }
}

int main()
{
    int select = 0;
    char password[10] = {"gec123456"};
    printf("请选择办理业务：1.登录2.修改密码\n");
    scanf("%d", &select);
    switch (select)
    {
    case 1:
        login(password);
        break;
    case 2:
        if (login(password) == 1)
        {
            modify(password);
        }
        else
        {
            printf("登录不成功，无法修改密码\n");
        }
        break;

    default:
        break;
    }

    return 0;
}
