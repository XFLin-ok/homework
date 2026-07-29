#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// int
// char
// struct MyStruct
// {

// };

// 存储的数据类型
typedef int Datatype_t;

// typedef xxx Datatype_t;

// 管理节点
typedef struct sequeneclist
{
    Datatype_t *data; // 存储顺序表首地址
    int size;         // 存储顺序表容量
    int last;         // 记录最后存储的元素下标
} SList_t;

/********************************************************************************************
 *
 *    函数名称：SequenecList_Create
 *    函数功能：创建空的顺序表
 *    函数参数：
 *        @size：指的是创建的顺序表中数据元素的容量
 *
 *    返回结果：成功 返回记录顺序表指标信息的（管理节点）指针   失败 返回NULL
 *    函数作者：zyx
 *    创建日期：2026年7月23日15:06:05
 *    函数版本：V1.0
 *    优化内容：None
 *    注意事项：调用该函数时请注意接收该函数的返回值，否则无法获得顺序表的初始指标信息
 *
 * *****************************************************************************************/
SList_t *SequenecList_Create(int size)
{
    // 1.为管理节点申请堆空间 malloc calloc
    // SList_t *MyNode=(SList_t *)malloc(1*sizeof(SList_t));
    SList_t *MyNode = (SList_t *)calloc(1, sizeof(SList_t));
    // 错误判断
    if (MyNode == NULL)
    {
        printf("MyNode calloc fail\n");
        return NULL;
    }

    // 2.为顺序表申请堆空间
    Datatype_t *MySList = (Datatype_t *)calloc(size, sizeof(Datatype_t));
    if (MySList == NULL)
    {
        printf("MySList calloc fail\n");
        return NULL;
    }

    // 3.初始化管理节点
    MyNode->data = MySList; // 首地址
    MyNode->size = size;    // 容量
    MyNode->last = -1;      // 下标

    // 4.返回管理节点的地址
    return MyNode;
}

// 判断顺序表是否已经满了
bool SequenecList_IsFull(SList_t *MyNode)
{
    return (MyNode->last + 1 >= MyNode->size);
}

// 尾插法 插入数据
bool SequenecList_Tailinsert(SList_t *MyNode, Datatype_t info)
{
    // 1.如果顺序表已经满了 提示不能插入数据
    if (SequenecList_IsFull(MyNode))
    {
        printf("SequenecList Is Full,can not inset\n");
        return false;
    }

    // 2.下标+1
    MyNode->last++;

    // 3.放入数据
    MyNode->data[MyNode->last] = info;

    // 4.返回成功
    return true;
}

// 遍历打印顺序表
void SequenecList_print(SList_t *MyNode)
{
    int i = 0;
    for (i = 0; i <= MyNode->last; i++)
    {
        printf("%d\t", MyNode->data[i]);
    }
    printf("\n");
}

// 头插法
bool SequenecList_Headinsert(SList_t *MyNode, Datatype_t info)
{
    // 1.如果顺序表已经满了 提示不能插入数据
    if (SequenecList_IsFull(MyNode))
    {
        printf("SequenecList Is Full,can not inset\n");
        return false;
    }

    // 2.整个顺序表已经存储元素向后移动一位
    int i = MyNode->last;
    for (; i >= 0; i--)
    {
        MyNode->data[i + 1] = MyNode->data[i];
    }

    // 3.放入数据
    MyNode->data[0] = info;

    // 4.更新下标
    MyNode->last++;

    return true;
}

// 判断是否为空的顺序表
bool SequenecList_IsEmpty(SList_t *MyNode)
{
    return (MyNode->last == -1);
}

// 尾部删除
bool SequenecList_TailDelete(SList_t *MyNode)
{
    // 1.空顺序表不能删除
    if (SequenecList_IsEmpty(MyNode))
    {
        printf("SequenecList Is Empty,can not delete\n");
        return false;
    }

    // 2.更新下标
    MyNode->last--;
    // 让数据清空

    return true;
}
// 删除指定
bool SequenecList_SelectDelete(SList_t *MyNode, Datatype_t info)
{
    // 1.空顺序表不能删除
    if (SequenecList_IsEmpty(MyNode))
    {
        printf("SequenecList Is Empty,can not delete\n");
        return false;
    }

    // 2.遍历顺序表
    int i;
    for (i = 0; i <= MyNode->size - 1; i++)
    {
        if (MyNode->data[i] == info)
        {
            for (i; i <= MyNode->size - 1; i++)
            {
                MyNode->data[i] = MyNode->data[i + 1];
            }

            return true;
        }
    }
}

int main()
{
    // 1.创建顺序表
    SList_t *MyNode = SequenecList_Create(10);

    // 2.尾插数据
    SequenecList_Tailinsert(MyNode, 10);
    SequenecList_Tailinsert(MyNode, 20);
    SequenecList_Tailinsert(MyNode, 30);

    SequenecList_Headinsert(MyNode, 40);
    SequenecList_Headinsert(MyNode, 50);
    SequenecList_Headinsert(MyNode, 60);

    SequenecList_TailDelete(MyNode);
    SequenecList_TailDelete(MyNode);
    SequenecList_SelectDelete(MyNode, 50);
    SequenecList_SelectDelete(MyNode, 60);
    // SequenecList_SelectDelete(MyNode, 40);
    // SequenecList_SelectDelete(MyNode, 10);

    // 3.打印调试
    SequenecList_print(MyNode);
}