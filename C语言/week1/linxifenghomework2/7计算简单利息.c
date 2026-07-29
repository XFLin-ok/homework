#include<stdio.h>
int main()
{
   float org = 0;
   float Annualinterest = 0;
   float time = 0;
   float interest = 0;
   printf("请输入本金，年利率，时间");
   scanf("%f %f %f",&org,&Annualinterest,&time);
   interest = (org * Annualinterest * time) / 100;
   printf("利息为：%f",interest);
   return 0;





}