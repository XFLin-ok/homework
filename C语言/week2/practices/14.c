#include <stdio.h>
void change(int *, int *);
int main()
{
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    printf("交换前%d %d\n", a, b);
    change(&a, &b);
    printf("交换后%d %d\n", a, b);
}
inline void change(int *x, int *y)
{
    int tmp = 0;
    tmp = *x;
    *x = *y;
    *y = tmp;
}