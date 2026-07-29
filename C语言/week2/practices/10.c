#include <stdio.h>
#include <string.h>
int main()
{
    char str[100] = {0};
    scanf("%s", str);
    int len = strlen(str);
    printf("%d\n", len);
    for (int i = 0; i < len; i++)
    {
        printf("%c ", str[i]);
    }
    printf("\n");
    for (int i = 0; i < len / 2; i++)
    {
        char tmp = 0;
        tmp = str[i];
        str[i] = str[len - 1];
        str[len - 1] = tmp;
        len--;
    }
    printf("%s\n", str);
}
