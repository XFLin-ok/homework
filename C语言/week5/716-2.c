#include<stdio.h>
int main()
{
    float interest1,interest2,interest3;
    int principal=1000;
    float r1=0.0036;
    float r2=0.0225;
    float r3=0.0198;
    float sum1,sum2,sum3;
    printf("方法一：\n");
    interest1=principal*1*r1;
    sum1=interest1+principal;
    printf("本息和：%.4f\n",sum1);
    printf("方法二：\n");
    interest2=principal*1*r2;
    sum2=interest2+principal;
    printf("本息和：%.4f\n",sum2);
     printf("方法三：\n");
    interest3=principal*0.5*r3;
    sum3=interest3+principal;
    interest3=sum3*0.5*r3;
    sum3=interest3+sum3;
    printf("本息和：%.4f\n",sum3);

}