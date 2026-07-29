#include <stdio.h>
int main()
{
    int big = 0, small = 0;
    char arry[100] = {0};
    printf("输入一个字符串\n");
    scanf("%s", arry);

    printf("%s\n", arry);

    for (int i = 0; i < 100; i++)
    {
        if (arry[i] >= 65 && arry[i] <= 90)
        {
            big++;
        }
        if (arry[i] >= 97 && arry[i] <= 122)
        {
            small++;
        }
    }
    printf("大写字母：%d个,小写字母：%d个\n", big, small);
}