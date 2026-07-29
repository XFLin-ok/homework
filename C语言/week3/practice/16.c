#include <stdio.h>
#include <stdlib.h>
char *change(char *p)
{
    for (int i = 0; p[i] != '\0'; i++)
    {
        if (p[i] >= 'a' && p[i] <= 'z')
        {
            p[i] = p[i] - 'a' + 'A';
        }
    }
    return p;
}
int main()
{
    printf("输入整数：\n");
    int n = 0;
    scanf("%d", &n);
    char *p = malloc(sizeof(char) * n);
    printf("输入字符串：\n");
    scanf("%s", p);
    char *p1 = change(p);
    for (int i = 0; p[i] != '\0'; i++)
    {
        printf("%c", p1[i]);
    }
}