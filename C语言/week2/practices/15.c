#include <stdio.h>
void str_print(char *addr, int size)
{
    printf("%s\n", (char *)addr);
}
void int_print(void *addr, int size)
{
    int *p = addr;
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", p[i]);
    }
}
void print_arry(void *addr, int size, void (*p)(void *addr, int size))
{
    p(addr, size);
}
int main()
{
    char str[100] = {"asdsaf"};
    print_arry(str, 100, str_print);
    int arry[5] = {1, 2, 3, 4, 5};
    print_arry(arry, 5, int_print);
}