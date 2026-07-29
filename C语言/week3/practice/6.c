#include <stdio.h>
#include <string.h>
int main()
{
    char str[2][100] = {0};
    scanf("%s", str[0]);
    scanf("%s", str[1]);
    int a = strcmp(str[0], str[1]);
    if (a == 0)
        printf("相同");
    else
        printf("不相同");
}