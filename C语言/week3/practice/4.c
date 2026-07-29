#include <stdio.h>
void change(int *, int *);
int main()
{
    int a = 0, b = 0;
    printf("输入两个数\n");
    scanf("%d %d", &a, &b);
    printf("交换前%d %d\n", a, b);
    change(&a, &b);
    printf("交换后%d %d\n", a, b);
}
void change(int *p1, int *p2)
{
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}