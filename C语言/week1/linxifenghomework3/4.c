#include <stdio.h>
int main()
{
    int k = 0;
    float sum = 0;
    printf("请输入水的夸脱数：");
    scanf("%d", &k);
    sum = 950 * k / 3.0e-23;
    printf("%d夸脱水中包含%f个水分子", k, sum);
    return 0;
}