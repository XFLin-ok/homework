#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {

        for (int j = 0; j <= n - i; j++)
        {
            printf(" ");
        }
        int k;
        for (k = 1; k <= i; k++)
        {
            printf("%d", k);
        }
        for (k -= 2; k >= 1; k--)
        {
            printf("%d", k);
        }
        printf("\n");
    }
}