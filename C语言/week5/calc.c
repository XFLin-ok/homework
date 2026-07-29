#include<stdio.h>
int add(int a,int b)
{
    return a+b;
}
int sub(int a,int b)
{
    return a-b;
}
int multiplication(int a,int b)
{
    return a*b;
}
float division(float a,float b)
{
    if(b==0)
    {
        printf("除数不能为0！");
        return 0;
    }
    else
    {
        return (float)a/b;
    }
}
int main()
{
 printf("%d\n",add(100,122));
 printf("%d\n",sub(100,122));
 printf("%d\n",multiplication(100,122));
 printf("%.2f\n",division(100,122));
division(100,0);



}