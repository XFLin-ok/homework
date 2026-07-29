#include "./include/mystring.h"
#include <stdio.h>
char str[100] = {0};
int main()
{
    char str1[10] = {"hello"};
    char str2[10] = {"world"};
    // mystring1(str1, str2);
    // printf("%s\n", str1);
    mystring2(str1, str2);
    printf("%s\n", str1);
}