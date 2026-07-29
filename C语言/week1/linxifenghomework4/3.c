#include <stdio.h>
int main()
{
    float num = 0;
    float num_3 = 0;
    printf("请输入一个float型数:");
    scanf("%f", &num);
    num_3 = num * num * num;
    printf("该数的立方值为:%f\n", num_3);
}