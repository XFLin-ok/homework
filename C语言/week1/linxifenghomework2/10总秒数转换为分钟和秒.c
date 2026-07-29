#include<stdio.h>
int main()
{
  int sumsecond = 0;
  int minute = 0;
  int second= 0;
  printf("请输入总秒数：");
  scanf("%d",&sumsecond);
  minute = sumsecond/60;
  second = sumsecond%60;
  printf("一共%d分%d秒",minute,second);
  return 0;


}