#include<stdio.h>
int main ()
{
   int a = 0;
   int b = 0;
   int tmp = 0;
   printf("请输入两个整型数据a和b:");
   scanf("%d %d",&a,&b);
   tmp = a;
   a = b;
   b = tmp;
   printf("交换后的数据a:%d,b:%d",a,b);
   return 0;
   


}