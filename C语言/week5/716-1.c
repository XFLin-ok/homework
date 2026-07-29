#include<stdio.h>
int main ()
{
  float f=0.0;
  float c=0.0;
  printf("请输入华氏度：");
  scanf("%f",&f);
  c=5*1.0/9*(f-32);
  printf("摄氏度：%.6f\n",c);


}