#include<stdio.h>
int main()
{
    float p=0.0;
    float q=0.0;
    float sum=0.0;
 for(int i=1;i<=5;i++)
 {
    printf("第%d个同学的成绩\n",i);
    printf("请输入平时成绩：");
    scanf("%f",&p);
    printf("请输入期末成绩：");
    scanf("%f",&q);
    sum=(0.3*p)+(0.7*q);
    printf("总成绩：%f\n",sum);
    
 }

}