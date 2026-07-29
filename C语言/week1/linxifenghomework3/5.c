#include <stdio.h>

int main()
{
    char c;

    c = '\r';
    printf("12345%c6789\n", c);
    c = 13;
    printf("12345%c6789\n", c);
    c = '\015';
    printf("12345%c6789\n", c);
    c = '\x0D';
    printf("12345%c6789\n", c);
    return 0;
}