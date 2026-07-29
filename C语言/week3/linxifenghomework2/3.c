#include <stdio.h>
int main()
{
    int a = 10;
    int *a;
    int **a;
    int a[10];
    int *a[10];
    int (*a)[10];
    int (*a)(int);
    int (*a[10])(int);
}