#include <stdio.h>
int main()
{
    int a = 100;
    int b = 0, c = 0, d = 0;

    while (a < 1000)
    {
        b = a / 100;       // 百位
        c = (a / 10) % 10; // 十位
        d = a % 10;        // 个位
        if ((b * b * b + c * c * c + d * d * d) == a)
        {
            printf("%d为水仙花数\n", a);
        }
        a++;
    }
}