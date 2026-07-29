#include <stdio.h>
int main()
{
    char str[3][10] = {0};
    printf("输入三个用户名：\n");
    scanf("%s", str[0]);
    scanf("%s", str[1]);
    scanf("%s", str[2]);
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", str[i]);
    }
    int arry[][5] = {1, 2, 3};
    printf("%ld", sizeof(arry));
}