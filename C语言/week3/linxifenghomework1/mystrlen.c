#include <stdio.h>
int mystrlen(char *);
int main()
{
    char str[100] = {0};
    printf("输入字符串：\n");
    scanf("%s", str);
    int len = mystrlen(str);
    printf("%d\n", len);
}
int mystrlen(char *p)
{
    int i = 0, n = 0;
    while (p[i] != '\0')
    {
        ++n;
        i++;
    }
    return n;
}