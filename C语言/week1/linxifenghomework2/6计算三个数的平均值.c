#include<stdio.h>
int main()
{
   int a = 0;
   int b = 0;
   int c = 0;
   float tmp1 =0;
   float tmp2 =0;
   float avg = 0;
   printf("请输入三个整数：");
   scanf("%d %d %d",&a,&b,&c);
   avg = (a + b + c)/3;
   printf("这三个数的平均值为：%f",avg);
   return 0;


}