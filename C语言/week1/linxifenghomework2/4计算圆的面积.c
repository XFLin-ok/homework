#include<stdio.h>
int main()
{
   float r = 0;
   float Area = 0;
   printf("请输入圆的半径r:");
   scanf("%f",&r);
   Area = 3.14 * r * r;
   printf("圆的面积为：%f",Area);
   return 0;


}