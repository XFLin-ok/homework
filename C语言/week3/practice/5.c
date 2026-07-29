#include <stdio.h>
int mystrlen(char *);
int main()
{
    char *p = "21234\0a2";
    int len1 = strlen(p);
    printf("%d\n", len1);
    int len = mystrlen(p);
    printf("%d\n", len);
}
int mystrlen(char *p)
{
    int i = 0, n = 0;
    while (p[i] != '\0')
    {
        ++n;
        i++;
    }
    return n;
}