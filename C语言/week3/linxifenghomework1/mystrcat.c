#include <stdio.h>
char *mystrcat(char *, char *);
int main()
{
    char str1[100] = {"1234"};
    char str2[100] = {"abcd"};
    mystrcat(str1, str2);
    printf("%s", str1);
}
char *mystrcat(char *p1, char *p2)
{
    int i = 0, n = 0;
    while (*p1 != '\0')
    {
        p1++;
    }
    int j = 0;
    while (*p2 != '\0')
    {
        *p1 = *p2;
        p1++;
        p2++;
    }
    *p1 = '\0';
    return p1;
}