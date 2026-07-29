#include<stdio.h>
int main()
{
   printf("请输入立方体的边长：");
   float c = 0;
   scanf("%f",&c);
   float volume = 0;
   volume = c * c * c;
   printf("立方体的体积为：%f",volume);
   return 0;


}