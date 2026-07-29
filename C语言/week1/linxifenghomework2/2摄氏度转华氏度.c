#include<stdio.h>
int main()
{
    float C = 0;
    float F = 0;
   printf("请输入一个摄氏温度：");
   scanf("%f",&C);
   F = C * 1.8 + 32;
   printf("华氏温度为：%f",F);
   return 0;

}