#include <stdio.h>
int main()
{
    char str1[100] = {"strabcdefj"};
    char str2[100] = {0};
    scanf("%s", str2);
    mystrstr(str1, str2);
}
char *mystrstr(char *p1, char *p2)
{
    while (*p1 != '\0')
    {
        if (*p1 == *p2)
        {

            for (p2; *p2 != '\0'; p2++, p1++)
            {
                if (*p1 != *p2)
                    return 0;
            }
        }
        p1++;
    }
    return p1;
}