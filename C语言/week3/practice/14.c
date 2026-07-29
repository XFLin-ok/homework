#include <stdio.h>
void my_strcpy(char *dest, char *src)
{
    while (*dest != '\0')
    {
        dest++;
    }
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
}
int main()
{
    char str1[100] = {"hello"};
    char str2[100] = {"world"};
    my_strcpy(str1, str2);
    printf("%s\n", str1);
}