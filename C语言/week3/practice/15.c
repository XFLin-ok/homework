#include <stdio.h>
int *find_max(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i + 1] > arr[i])
            arr++;
    }
    return arr;
}
int main()
{
    int arry[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = find_max(arry, 10);
    printf("最大值：%d :", *p);
}