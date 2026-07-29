#include <stdio.h>
int mystrcmp(char *, char *);
int main()
{
    char str1[100] = {0};
    char str2[100] = {0};
    printf("输入两个对比字符串：\n");
    scanf("%s", str1);
    scanf("%s", str2);
    int a = mystrcmp(str1, str2);
    if (a == 0)
        printf("相同\n");
    if (a == -1)
        printf("不同\n");
}
int mystrcmp(char *p1, char *p2)
{
    while (*p1 != '\0')
    {
        if (*p1 != *p2)
        {
            return -1;
        }
        p1++;
        p2++;
    }
    return 0;
}