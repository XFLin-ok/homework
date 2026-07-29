#ifndef _DOUBLY_CYCLE_LINK_H
#define _DOUBLY_CYCLE_LINK_H

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
    struct data_node *prev;
    struct data_node *next;
} data_node;
// 管理节点类型
typedef struct mange_node
{
    data_node *head;
    data_node *tail;
    data_t num;
} mange_node;
// 函数声明
//  创建管理节点
mange_node *create_mangenode();
// 创建新节点
data_node *create_newnode(data_t);
// 头插法
bool head_insert(mange_node *, data_t);
// 尾插
bool tail_node(mange_node *, data_t);
// 删除节点
bool del_node(mange_node *, data_t);
// 查询节点
bool search_node(mange_node *, data_t);
// 修改节点
bool change_node(mange_node *);
// 打印链表
void print_linklist(mange_node *);
#endif