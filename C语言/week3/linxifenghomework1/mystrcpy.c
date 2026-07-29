#include <stdio.h>
#include <string.h>
char *mystrcpy(char *, char *);
int main()
{
    char str1[100] = {"abcd"};
    char str2[100] = {};
    scanf("%s", str2);
    mystrcpy(str1, str2);
    printf("%s", str1);
}
char *mystrcpy(char *p1, char *p2)
{
    for (int i = 0; p2[i] != '\0'; i++)
    {
        p1[i] = p2[i];
    }
    return p1;
}
