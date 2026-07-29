#include <stdio.h>
enum choices
{
    no,
    yes,
    maybe
};
int main()
{
    int n = 0;
    scanf("%d", &n);
    switch (n)
    {
    case no:
        printf("no\n");
        break;
    case yes:
        printf("yes\n");
        break;
    case maybe:
        printf("maybe\n");

    default:
        break;
    }
}