#include <stdio.h>
int main()
{
    char ch = 0;
    int n = 0;
    printf("输入大写字母：");
    scanf("%c", &ch);
    char str[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    if (ch >= 'A' && ch <= 'Z')
    {
        n = (int)ch - 'A' + 1;
        printf("n=%d\n", n);
    }
    else
    {
        printf("输入错误！");
    }
    for (int i = 1; i <= n; i++)
    {
        for (char j = 0; j <= n - 1; j++)
        {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}