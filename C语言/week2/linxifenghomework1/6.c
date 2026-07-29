#include <stdio.h>
int main()
{

    int a = 100;
    int b = 0;
    int c = 0;
    int d = 0;
    for (a; a <= 999; a++)
    {
        b = a / 100;

        d = a % 10;
        if (b == d)
        {
            printf("%d为对称数\n", a);
        }
    }
    return 0;
}