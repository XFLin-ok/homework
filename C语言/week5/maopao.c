#include <stdio.h>
void maopao(int *arry[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arry[i] > arry[i + 1])
            arry[i - 1] = arry[i];
    }
    for (int i = 1; i <= n; i++)
    {
        printf("");
    }
}
int main()
{
    int arry[] = {1, 4, 3, 6, 9};
}