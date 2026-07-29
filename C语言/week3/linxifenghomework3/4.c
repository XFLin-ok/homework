#include <stdio.h>
double func1(double, double);

double func2(double, double);
double func3(double, double);
double func4(double, double);
int main()
{
    float *p[4] = {func1, func2, func3, func4};
}