#include <stdio.h>
int main()
{
    int ln = 0, wn = 0, yn = 0;
    char *p[] = {"hello", "world", "happy", "new", "year"};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; p[i][j] != '\0'; j++)
        {
            if (p[i][j] == 'l')
            {
                ln++;
            }
            if (p[i][j] == 'w')
            {
                wn++;
            }
            if (p[i][j] == 'y')
            {
                yn++;
            }
        }
    }
    printf("l=%d w=%d y=%d\n", ln, wn, yn);
}