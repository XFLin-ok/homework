#include<stdio.h>
int main()
{
   float price = 0 ;
   float quantity = 0;
   float sum = 0;
   printf("请输入商品单价和数量：");
   scanf("%f %f",&price,&quantity);
   sum = price * quantity;
   printf("需要支付的总金额为：%f",sum);
   return 0;


}