#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
// 棋盘二维数组
// 空位随机生成数字两个2
// 四个方向的数组元素相加
// 二维数组遍历
// 实现操作
bool print_arr(int arr[3][3]);

// 向上操作

bool go_up(int arr[3][3])
{
    int num5 = 0;
    int num6 = 0;
    // 移动格子
    for (int k = 0, i = 0; k < 3; k++)
    {
        if ((arr[i][k] == 0) && (arr[i + 1][k] == 0))
        {
            arr[i][k] = arr[i + 2][k];
            arr[i + 2][k] = 0;
        }
        if (arr[i][k] == 0)
        {
            arr[i][k] = arr[i + 1][k];
            arr[i + 1][k] = 0;
        }
        if (arr[i + 1][k] == 0)
        {
            arr[i + 1][k] = arr[i + 2][k];
            arr[i + 2][k] = 0;
        }
        if (arr[i][k] == arr[i + 1][k])
        {
            arr[i][k] += arr[i + 1][k];
            arr[i + 1][k] = 0;
        }
        if (arr[i + 1][k] == arr[i + 2][k])
        {
            arr[i + 1][k] += arr[i + 2][k];
            arr[i + 2][k] = 0;
        }
    }
    // 移动完时判断游戏是否结束
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (arr[i][k] == 0)
            {
                num6++;
            }
            if (arr[i][k] == 2048)
            {
                printf("游戏胜利！\n");
                print_arr(arr);
                return false;
            }
        }
    }
    if (num6 == 0)
    {
        printf("游戏结束！\n");
        return false;
    }
    // 产生新的随机数
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (arr[i][k] == 0)
            {
                int m = rand() % 2;
                if (m)
                {
                    arr[i][k] = 2;
                    num5++;
                }
            }
            if (num5 == 2)
            {
                break;
            }
        }
        if (num5 == 2)
        {
            break;
        }
    }
    // 遍历
    print_arr(arr);

    return true;
}

// 向下操作

bool go_down(int arr[3][3])
{
    int num7 = 0;
    int num8 = 0;
    for (int k = 0, i = 2; k < 3; k++)
    {
        if ((arr[i][k] == 0) && (arr[i - 1][k] == 0))
        {
            arr[i][k] = arr[i - 2][k];
            arr[i - 2][k] = 0;
        }
        if (arr[i][k] == 0)
        {
            arr[i][k] = arr[i - 1][k];
            arr[i - 1][k] = 0;
        }

        if (arr[i - 1][k] == 0)
        {
            arr[i - 1][k] = arr[i - 2][k];
            arr[i - 2][k] = 0;
        }
        if (arr[i][k] == arr[i - 1][k])
        {
            arr[i][k] += arr[i - 1][k];
            arr[i - 1][k] = 0;
        }
        if (arr[i - 1][k] == arr[i - 2][k])
        {
            arr[i - 1][k] += arr[i - 2][k];
            arr[i - 2][k] = 0;
        }
    }
    // 移动完时判断游戏是否结束
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (arr[i][k] == 0)
            {
                num8++;
            }
            if (arr[i][k] == 2048)
            {
                printf("游戏胜利！\n");
                print_arr(arr);
                return false;
            }
        }
    }
    if (num8 == 0)
    {
        printf("无法移动，游戏结束！\n");
        return false;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (arr[i][k] == 0)
            {
                int m = rand() % 2;
                if (m)
                {
                    arr[i][k] = 2;
                    num7++;
                }
            }
            if (num7 == 2)
            {
                break;
            }
        }
        if (num7 == 2)
        {
            break;
        }
    }
    // 遍历
    print_arr(arr);

    return true;
}

// 向左操作

bool go_left(int arr[3][3])
{
    int num9 = 0;
    int num10 = 0;
    for (int k = 0, i = 0; i < 3; i++)
    {
        if ((arr[i][k] == 0) && (arr[i][k + 1] == 0))
        {
            arr[i][k] = arr[i][k + 2];
            arr[i][k + 2] = 0;
        }
        if (arr[i][k] == 0)
        {
            arr[i][k] = arr[i][k + 1];
            arr[i][k + 1] = 0;
        }
        if (arr[i][k + 1] == 0)
        {
            arr[i][k + 1] = arr[i][k + 2];
            arr[i][k + 2] = 0;
        }
        if (arr[i][k] == arr[i][k + 1])
        {
            arr[i][k] += arr[i][k + 1];
            arr[i][k + 1] = 0;
        }
        if (arr[i][k + 1] == arr[i][k + 2])
        {
            arr[i][k + 1] += arr[i][k + 2];
            arr[i][k + 2] = 0;
        }
    }
    // 移动完时判断游戏是否结束
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (arr[i][k] == 0)
            {
                num10++;
            }
            if (arr[i][k] == 2048)
            {
                printf("游戏胜利！\n");
                print_arr(arr);
                return false;
            }
        }
    }
    if (num10 == 0)
    {
        printf("游戏结束！\n");
        return false;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (arr[i][k] == 0)
            {
                int m = rand() % 2;
                if (m)
                {
                    arr[i][k] = 2;
                    num9++;
                }
            }
            if (num9 == 2)
            {
                break;
            }
        }
        if (num9 == 2)
        {
            break;
        }
    }
    // 遍历
    print_arr(arr);

    return true;
}
// 向右操作

bool go_right(int arr[3][3])
{
    int num11 = 0;
    int num12 = 0;
    for (int k = 2, i = 0; i < 3; i++)
    {
        if ((arr[i][k] == 0) && (arr[i][k - 1] == 0))
        {
            arr[i][k] = arr[i][k - 2];
            arr[i][k - 2] = 0;
        }
        if (arr[i][k] == 0)
        {
            arr[i][k] = arr[i][k - 1];
            arr[i][k - 1] = 0;
        }
        if (arr[i][k - 1] == 0)
        {
            arr[i][k - 1] = arr[i][k - 2];
            arr[i][k - 2] = 0;
        }
        if (arr[i][k] == arr[i][k - 1])
        {
            arr[i][k] += arr[i][k - 1];
            arr[i][k - 1] = 0;
        }
        if (arr[i][k - 1] == arr[i][k - 2])
        {
            arr[i][k - 1] += arr[i][k - 2];
            arr[i][k - 2] = 0;
        }
    }
    // 移动完时判断游戏是否结束
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (arr[i][k] == 0)
            {
                num12++;
            }
            if (arr[i][k] == 2048)
            {
                printf("游戏胜利！\n");
                print_arr(arr);
                return false;
            }
        }
    }
    if (num12 == 0)
    {
        printf("游戏结束！\n");
        return false;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (arr[i][k] == 0)
            {
                int m = rand() % 2;
                if (m)
                {
                    arr[i][k] = 2;
                    num11++;
                }
            }
            if (num11 == 2)
            {
                break;
            }
        }
        if (num11 == 2)
        {
            break;
        }
    }
    // 遍历
    print_arr(arr);

    return true;
}
// 遍历打印函数
bool print_arr(int arr[3][3])
{
    printf("------------------------------------\n");
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            printf("%d\t", arr[i][k]);
        }
        printf("\n");
    }
    return true;
}
int main()
{
    bool a1;
    bool a2;
    bool a3;
    bool a4;
    int arr[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    srand((unsigned int)time(NULL));
    int num1 = rand() % 3;
    int num2 = rand() % 3;
    arr[num1][num2] = 2;
    int num3 = rand() % 3;
    int num4 = rand() % 3;
    arr[num3][num4] = 2;
    // 遍历以及初始化
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            printf("%d\t", arr[i][k]);
        }
        printf("\n");
    }

    // 执行操作 上w，下s，左a，右d
    while (1)
    {
        int num = 0;
        char d = 0;
        scanf("%c", &d);
        switch (d)
        {
        case 'w':
            a1 = go_up(arr);
            if (a1 == false)
            {
                return 0;
            }
            break;
        case 's':
            a2 = go_down(arr);
            if (a2 == false)
            {
                return 0;
            }
            break;
        case 'a':
            a3 = go_left(arr);
            if (a3 == false)
            {
                return 0;
            }
            break;
        case 'd':
            a4 = go_right(arr);
            if (a4 == false)
            {
                return 0;
            }
            break;

        default:
            break;
        }
    }

    // 找出空位
    int num5 = rand() % 3;
    int num6 = rand() % 3;
    int num7 = rand() % 3;
    int num8 = rand() % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (arr[num5][num6] == 0)
            {
                arr[num5][num6] = 2;
            }
            if (arr[num7][num8] == 0)
            {
                arr[num7][num8] = 2;
            }
        }
        printf("\n");
    }
}