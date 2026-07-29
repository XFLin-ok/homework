#include <stdio.h>
void input_arry(int (*)[3]);
void show_arry(int (*)[3]);
int main()
{
    int arry[3][3] = {0};
    input_arry(arry);
    show_arry(arry);
}
void input_arry(int (*arry)[3])
{
    printf("输入九个数组元素：\n");
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            scanf("%d", &arry[j][i]);
        }
    }
}
void show_arry(int (*arry)[3])
{
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            printf("%d", arry[j][i]);
        }
    }
    printf("\n");
}
