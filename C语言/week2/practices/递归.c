#include <stdio.h>
int func(char *p)
{
    if (*p != '\0')
    {
        func(p + 1);
    }
    printf("%c ", *p);
}
int main()
{
    char *p = "hello";
    func(p);
}