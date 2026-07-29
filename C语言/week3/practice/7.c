#include <stdio.h>
int a = 100, b = 200;

int main()
{
    printf("交换前a=%d b=%d\n", a, b);
    int tmp = a;
    a = b;
    b = tmp;
    printf("交换后a=%d b=%d\n", a, b);
}