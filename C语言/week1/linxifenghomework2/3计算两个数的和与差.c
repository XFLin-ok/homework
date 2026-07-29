#include<stdio.h>
int main()
{
  int a = 0;
  int b = 0;
  int he = 0;
  int cha = 0;
  printf("请输入两个整数a和b:");
  scanf("%d %d",&a,&b);
  he = a + b;
  cha = a - b;
  printf("两数之和为：%d",he);
  printf("两数之差为：%d",cha);
  return 0;



}