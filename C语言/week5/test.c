#include <stdio.h>
int main()
{
    int a[10] = {7, 15, 23, 4, 9, 17, 2, 30, 11, 1};
    int num[10] = {};
    int k;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 2; j < a[i]; j++)
        {
            if (a[i] / j == 0)
            {
                a[i] = -1;
            }
        }
    }
}
