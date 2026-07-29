#include <stdio.h>
int main()
{
    int sizex = 0;
    int sizey = 0;
    printf("输入二维数组的大小：\n");
    scanf("%d", &sizex);
    char str[sizex][100];
    printf("输入%d个字符串：\n", sizex);
    for (int i = 0; i < sizex; i++)
    {
        scanf("%s", str[i]);
    }

    for (int j = 0; j < sizex; j++)
    {
        printf("%s\n", str[j]);
    }
}