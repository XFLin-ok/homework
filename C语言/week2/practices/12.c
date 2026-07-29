#include <stdio.h>
void print(int);
int sum = 0;
int sum1 = 1;
int main()
{
    int num = 0;
    scanf("%d", &num); // 123455
    print(num);
}
void print(int x)
{

    if (x == 0)
    {
        return;
    }
    sum = x % 10;
    sum1 = x / 10;
    printf("%d", sum);
    print(sum1);
}
