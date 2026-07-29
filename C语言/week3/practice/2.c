#include <stdio.h>
#include <math.h>
int check1(int);
int main()
{
    int a;
    scanf("%d", &a);
    int b = check1(a);
    if (b == 1)
        printf("%dweisushu", a);
    if (b == 0)
        printf("%dnosushu", a);
}
int check1(int a)
{
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}