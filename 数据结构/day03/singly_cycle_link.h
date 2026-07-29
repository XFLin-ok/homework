#ifndef SINGLY_CYCLE_LINK_H
#define SINGLY_CYCLE_LINK_H
// 头文件
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 存储的数据类型
typedef int Data_t;

// 设计数据结点的类型
typedef struct DataNode
{
    Data_t data;           // int data;
    struct DataNode *next; // 错误的写法DataNode *next;
} DataNode;

// 设计管理结点的类型
typedef struct Mange
{
    int num;               // 已经插入结点数量
    struct DataNode *Head; // 首结点地址
    struct DataNode *Tail; // 尾结点地址
} Mange_t;

// 函数声明
Mange_t *CircularLinkedList_Create();
DataNode *CircularLinkedList_NewNode(Data_t);
// 尾插法
bool CircularLinkedList_Tailinsert(Mange_t *, Data_t);
// 删除节点
bool del_node(Mange_t *, Data_t);
// 查询节点
bool search_node(Mange_t *, Data_t);
// 修改节点
bool change_node(Mange_t *);
// 遍历打印
void CircularLinkedList_print(Mange_t *);

#endif