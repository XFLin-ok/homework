// 2、编写一个程序，用户输入某个大写字母，产生一个金字塔图案。例如用户输入字母E,则产生如下图案：
//     A
//    ABA
//   ABCBA
//  ABCDCBA
// ABCDEDCBA
#include <stdio.h>
int main()
{
    char ch;
    int i, j, k;
    printf("请输入一个大写字母：");
    scanf("%c", &ch);
    for (i = 1; i <= ch - 'A' + 1; i++)
    {

        for (j = 1; j <= ch - 'A' + 1 - i; j++)
        {
            printf(" ");
        }
        for (k = 1; k <= i; k++)
        {
            printf("%c", 'A' + k - 1);
        }
        for (k = i - 1; k >= 1; k--)
        {
            printf("%c", 'A' + k - 1);
        }
        printf("\n");
    }
    return 0;
}