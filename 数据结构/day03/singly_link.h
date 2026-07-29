#ifndef _SINGLY_LINK_H
#define _SINGLY_LINK_H
// 头文件
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 数据类型
typedef int data_t;

// 数据节点类型
typedef struct data_node
{
    data_t data;
    struct data_node *next;
} data_node;
// 管理节点结构体类型
typedef struct mange_node
{
    struct data_node *head;
    struct data_node *tail;
    int num;
} mange_node;

// 函数声明
mange_node *mange_node_create();
data_node *data_node_create(data_t);
bool tail_insert(mange_node *, data_t);
// 头插法
bool head_insert(mange_node *, data_t);
// 删除节点
bool del_node(mange_node *, data_t);
// 查询节点
bool search_node(mange_node *, data_t);
// 删除最小值节点
void del_mindata(mange_node *);
// 修改节点
bool change_node(mange_node *);
// 打印链表
void print_linklist(mange_node *);

#endif