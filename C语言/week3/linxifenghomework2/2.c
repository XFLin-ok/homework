#include <stdio.h>
int main()
{
    for (int i = 1; i <= 7; i++)
    {
        switch (i)
        {
        case 1:
        case 7:
            printf("   *\n");
            break;
        case 2:
        case 6:
            printf("  ***\n");
            break;
        case 3:
        case 5:
            printf(" *****\n");
            break;
        case 4:
            printf("*******\n");
            break;

        default:
            break;
        }
    }
}