#include <stdio.h>
int add(int, int);
int sub(int, int);
int chen(int, int);
float cu(float, float);
int main()
{
    int a = 0, b = 0;
    printf("输入两个数：");
    scanf("%d %d", &a, &b);
    int c1 = add(a, b);
    int c2 = sub(a, b);
    int c3 = chen(a, b);
    float c4 = cu(a, b);
    printf("加法%d 减法:%d 乘法:%d 除法%.2f\n", c1, c2, c3, c4);
}
int add(int x, int y)
{
    return x + y;
}
int sub(int x, int y)
{
    return x - y;
}
int chen(int x, int y)
{
    return x * y;
}
float cu(float x, float y)
{
    return x / y;
}