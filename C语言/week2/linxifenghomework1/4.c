#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int target_num = rand() % 100 + 1;

    int guess_num;
    int count = 0;

    while (1)
    {
        printf("请输入你猜测的数字：");
        scanf("%d", &guess_num);
        count++;

        if (guess_num > target_num)
        {
            printf("太大了！\n");
        }
        else if (guess_num < target_num)
        {
            printf("太小了！\n");
        }
        else
        {
            printf("\n恭喜你，猜对了！\n");
            printf("你一共猜了 %d 次\n", count);
            break;
        }
    }

    return 0;
}