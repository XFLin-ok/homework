// 输入一个整数，倒序输出这个整数
#include <stdio.h>
void change(char *p)
{
    if (*p == '\0')
    {
        return;
    }
    change(p + 1);
    printf("%c", *p);
}
int main()
{
    char arr[100];
    scanf("%s", arr);
    change(arr);
    printf("\n");
}