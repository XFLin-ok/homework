#include <stdio.h>
char *mybzero(char *);
int main()
{
    char str[10] = {"adad"};
    printf("清空前：%s\n", str);
    mybzero(str);
    printf("清空后：%s\n", str);
}
char *mybzero(char *p)
{
    while (*p != '\0')
    {
        *p = 0;
        p++;
    }
    return p;
}