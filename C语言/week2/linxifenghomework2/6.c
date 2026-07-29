// 6. 正整数累加求和 (循环与输入检查)
// 题目描述：
// 循环让用户输入整数。
// 如果输入的是正数，则将其累加到总和中。
// 如果输入的是负数或0，则忽略该输入，提示“输入无效，请输入正数”，并继续等待输入。
// 如果用户输入 -1，则结束程序，输出之前所有正数的总和。
// 考察点： while 或 for 死循环，if 判断，break 退出循环。
// #include <stdio.h>
int main()
{
    int num = 0;
    int sum = 0;
    while (1)
    {
        printf("输入整数：\n");
        scanf("%d", &num);
        if (num > 0)
            sum = sum + num;
        else if (num == -1)
            break;
        else
            printf("输入无效，请输入正数\n");
    }
    printf("总和=%d\n", sum);
    return 0;
}