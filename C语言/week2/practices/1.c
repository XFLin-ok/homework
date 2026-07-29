// 程序内部生成一个 1 到 100 之间的随机整数（提示：可以使用 rand() % 100 + 1，并在 main 函数开头使用 srand(time(NULL)) 设置种子）。
// 让用户循环输入数字进行猜测。
// 如果用户猜大了，提示“太大了！”；猜小了，提示“太小了！”。
// 直到猜对为止，输出“恭喜你，猜对了！”，并统计用户猜了多少次。

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    srand(time(NULL)); // 设置随机因子

    int rand_data = rand() % 100 + 1; // 随机数

    int count = 0;
    int max, min;

    while (count < 10)
    {
        printf("请输入一个数值\n");
        int luckNumber = 0;

        scanf("%d", &luckNumber);

        if (luckNumber > rand_data)
        {
            printf("太大了!,范围在0-%d\n", luckNumber);
        }
        else if (luckNumber < rand_data)
        {
            printf("太小了!范围在%d-100\n", luckNumber);
        }
        else
        {
            printf("恭喜你🎉,猜对了中奖号码 %d ,猜奖次数 %d\n", rand_data, count);

            return 0; // 结束函数
        }

        count++; // 统计次数
    }
}