#include <stdio.h>
/*
3 7 4 9 6  5个数 4轮 第n轮比n-1次

3 7 4 9 6
3 4 7 9 6
3 4 7 9 6
3 4 7 6 9

3 4 7 6 9
3 4 7 6 9
3 4 6 7 9 

3 4 6 7 9
3 4 6 7 9

3 4 6 7 9
*/
//int (*p)(int ,int )
int BubbleMax(int a,int b)
{
    return a>b?1:0;
}

int BubbleMin(int a,int b)
{
    return a<b?1:0;
}


//封装一个冒泡排序函数  
void BubbleSort(int a[5],int size,int (*p)(int ,int ))   //回调函数 借助函数指针实现 在函数A里面调用函数B 函数B要作为参数传入函数A
{
    int i=0;
    int j=0;
    int temp=0;
    for (i = 0; i < size-1; i++)
    {
        for(j=0;j<size-1-i;j++)
        {
            if(p(a[j],a[j+1])) //冒泡大的 还是小的?
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

            }
        }
    }
}


int main()
{
    int a[5]={3,7,4,9,6};

    BubbleSort(a,sizeof(a)/sizeof(a[0]),BubbleMin); // int (*p)(int ,int )=BubbleMax;


    int i=0;

    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        printf("%d\t",a[i]);

    }
    printf("\n");
}

