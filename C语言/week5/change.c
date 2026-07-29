#include <stdio.h>

void change(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}

int main ()
{
    int a=100;
    int b=200;
    printf("a=%d,b=%d\n",a,b);
  change(&a,&b);
  printf("a=%d,b=%d\n",a,b);

}