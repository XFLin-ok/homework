#include <stdio.h>

#define BUG 0

union test
{
    int a;
    char b;
};

int main()
{
    int arr[][10] = {0};
    int (*p)[10];
    p = arr;

    // #if BUG
    //     union test p;
    //     p.a = 0x12345678;
    //     printf("%#x\n", p.b);
    // #else
    //     int a = 0x12345678;
    //     char *p = (char *)&a;
    //     *p = a;
    //     printf("%#x\n", *p);
    //     if (*p == 0x78)
    //     {
    //         printf("小端存储\n");
    //     }

    // #endif
}
