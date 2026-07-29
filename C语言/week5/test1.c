#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// 判断一个数是否为素数的函数
bool is_prime(int num)
{
    // 1及以下的数不是素数
    if (num <= 1)
    {
        return false;
    }
    // 2是唯一的偶素数
    if (num == 2)
    {
        return true;
    }
    // 排除所有大于2的偶数，提高效率
    if (num % 2 == 0)
    {
        return false;
    }

    // 试除法：只需判断到sqrt(num)即可
    int limit = (int)sqrt(num);
    for (int i = 3; i <= limit; i += 2)
    {
        if (num % i == 0)
        {
            return false; // 找到因数，不是素数
        }
    }

    return true; // 没有找到因数，是素数
}

// 筛选数组中素数的函数
void filter_primes(int arr[], int size)
{
    printf("数组中的素数有: ");
    for (int i = 0; i < size; i++)
    {
        if (is_prime(arr[i]))
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    // 初始化数组
    int arr[] = {7, 15, 23, 4, 9, 17, 2, 30, 11, 1};
    // 计算数组大小
    int size = sizeof(arr) / sizeof(arr[0]);

    // 调用筛选函数
    filter_primes(arr, size);

    return 0;
}
