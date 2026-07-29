#include <stdio.h>
int main()
{
   int num = 0, a = 0, n = 0, y = 0;
   int arry[100] = {0};
   scanf("%d", &num); // 123455
   while (num != 0)
   {
      y = num % 10;
      arry[n] = y;
      printf("余数%d ", y);
      num = num / 10;
      n++;
   }
   printf("\n");

   for (int i = n - 1; i >= 0; i--)
   {

      printf("%d ", arry[i]);
   }
}