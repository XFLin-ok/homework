// 5. 统计数值个数
// 题目描述：
// 输入一个整数，统计该整数的数值个数，例如:输入 1234521 ，输出2 个1 ，2 个2  ， 1 个3  ，1 个4 ， 1个5
// 考察点：求余运算与除法运算

// 5. 统计数值个数
// 题目描述：
// 输入一个整数，统计该整数的数值个数，例如:输入 1234521 ，输出2 个1 ，2 个2  ， 1 个3  ，1 个4 ， 1个5
// 考察点：求余运算与除法运算
#include <stdio.h>

// int main()
// {
//     long long val = 0;
//     printf("请输入一个数值\n");

//     scanf("%lld", &val);

//     int n0 = 0, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0;

//     while (1)
//     {
//         int n = val % 10; // 12345 % 10  =  5  ,1234 % 10 = 4   ,  123 % 10 = 3  , 12 % 10  = 2
//         switch (n)
//         {
//         case 0:
//             n0++;
//             break;
//         case 1:
//             n1++;
//             break;
//         case 2:
//             n2++;
//             break;
//         case 3:
//             n3++;
//             break;
//         case 4:
//             n4++;
//             break;
//         case 5:
//             n5++;
//             break;
//         case 6:
//             n6++;
//             break;
//         case 7:
//             n7++;
//             break;
//         case 8:
//             n8++;
//             break;
//         case 9:
//             n9++;
//             break;
//         default:
//             break;
//         }

//         val = val / 10; // 12345/ 10  = 1234  ,1234/10 = 123   ,   123 / 10  = 12   ,  12 /10 = 1
//         if (val < 10)
//         {
//             printf("%lld\n", val);
//             switch (val)
//             {
//             case 0:
//                 n0++;
//                 break;
//             case 1:
//                 n1++;
//                 break;
//             case 2:
//                 n2++;
//                 break;
//             case 3:
//                 n3++;
//                 break;
//             case 4:
//                 n4++;
//                 break;
//             case 5:
//                 n5++;
//                 break;
//             case 6:
//                 n6++;
//                 break;
//             case 7:
//                 n7++;
//                 break;
//             case 8:
//                 n8++;
//                 break;
//             case 9:
//                 n9++;
//                 break;
//             default:
//                 break;
//             }
//             break;
//         }
//     }

//     printf("%d 0 ,%d 1 ,%d 2 ,%d 3,%d 4,%d 5,%d 6,%d 7,%d 8,%d 9\n", n0, n1, n2, n3, n4, n5, n6, n7, n8, n9);
// }

#include <stdio.h>
int num = 0;
int num1 = 0;
int n = 0;
int n1 = 1;
int main()
{
    printf("输入一个整数：");
    scanf("%d", &num);
    num1 = num;
    while (num1 > 0)
    {
        num1 = num1 / 10;
        n++;
    }
    printf("n=%d\n", n);
    while (n > 1)
    {
        n1 = n1 * 10;
        --n;
    }
    printf("n1=%d\n", n1);
    while (n1 >= 10)
    {

        num = num % n1;
        printf("n1=%d\n", n1);
        printf("num=%d\n", num);
        n1 = n1 / 10;
    }
}