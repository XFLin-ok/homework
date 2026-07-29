#include "doubly_link.h"

// 创建管理节点
mange_node *create_mangenode()
{
    // 申请堆空间
    mange_node *mange = (mange_node *)malloc(1 * sizeof(mange_node));
    // 判断
    if (mange == NULL)
    {
        printf("mange malloc fail\n");
        return NULL;
    }
    mange->head = NULL;
    mange->tail = NULL;
    mange->num = 0;
    return mange;
}
// 创建新节点
data_node *create_newnode(data_t data)
{
    // 申请堆空间
    data_node *newnode = (data_node *)malloc(1 * sizeof(data_node));
    // 判断
    if (newnode == NULL)
    {
        printf("newdata malloc fail\n");
        return NULL;
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
// 头插法
bool head_insert(mange_node *mange, data_t data)
{
    data_node *newnode = create_newnode(data);
    // 判断
    if (newnode == NULL)
    {
        printf("newdata malloc fail\n");
        return false;
    }
    if (mange->head == NULL) // 空链表
    {
        mange->head = newnode;
        mange->tail = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
        mange->num++;
    }
    else // 非空链表
    {
        mange->head->prev = newnode;
        newnode->next = mange->head;
        mange->head = newnode;
        mange->num++;
    }
    return true;
}
// 尾插法
bool tail_insert(mange_node *mange, data_t data)
{
    // 创建新节点
    data_node *newnode = create_newnode(data);
    // 判断
    if (newnode == NULL)
    {
        printf("newdata malloc fail\n");
        return false;
    }
    if (mange->head == NULL)
    {
        mange->head = newnode;
        mange->tail = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
        mange->num++;
    }
    else
    {
        mange->tail->next = newnode;
        newnode->prev = mange->tail;
        mange->tail = newnode;
        mange->num++;
    }
    return true;
}
// 选择插
bool select_insert(mange_node *mange)
{
    data_t select = 0;
    data_t data = 0;
    // 选择插入
    printf("请选择将数据插入到哪个数据节点的后面\n");
    scanf("%d", &select);
    printf("请输入需要插入的数据\n");
    scanf("%d", &data);
    // 创建新节点
    data_node *newnode = create_newnode(data);
    data_node *p = mange->head;
    // 判断
    if (newnode == NULL)
    {
        printf("newdata malloc fail\n");
        return false;
    }
    // 空链表
    if (mange->head == NULL)
    {
        mange->head = newnode;
        mange->tail = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
        mange->num++;
    }
    // 找到目标节点
    while (p != NULL)
    {
        if (p->data == select)
        {
            break;
        }
        p = p->next;
    }
    // 空链表
    if (mange->head == NULL)
    {
        mange->head = newnode;
        mange->tail = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
        mange->num++;
    }
    // 情况2：没有找到目标节点
    if (p == NULL)
    {
        printf("未找到值为 %d 的节点，插入失败！\\n", select);
        free(newnode); // 释放申请的节点，防止内存泄漏
        return false;
    }
    // 情况3：找到目标节点，分两种：中间节点 / 尾节点
    newnode->prev = p;
    newnode->next = p->next;

    if (p->next != NULL)
    {
        p->next->prev = newnode;
    }
    else
    {
        // p是尾节点，新节点成为新尾
        mange->tail = newnode;
    }
    p->next = newnode;

    mange->num++;
    return true;
}
// 删除节点
bool del_node(mange_node *mange, data_t data)
{
    data_node *p = mange->head;
    if (mange->head == NULL)
    {
        return false;
    }
    while (p != NULL)
    {
        if (p->data == data)
        {
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        return false;
    }
    if (p == mange->head) // 头删
    {
        mange->head = p->next;
        p->next->prev = NULL;
        p->next = NULL;
        mange->num--;
        free(p);
    }
    else if (p->next == NULL)
    {
        mange->tail = p->prev;
        p->prev->next = NULL;
        p->prev = NULL;
        mange->num--;
        free(p);
    }
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->next = NULL;
        p->prev = NULL;
        mange->num--;
        free(p);
    }
    return true;
}
// 修改节点
bool change_node(mange_node *mange)
{
    data_t select = 0;
    data_t data = 0;
    data_node *p = mange->head;
    printf("输入需要修改节点的原数据\n");
    scanf("%d", &select);
    printf("输入需要修改后的数据\n");
    scanf("%d", &data);
    // 寻找节点
    while (p->data != select && p->next != NULL)
    {
        p = p->next;
    }
    if (p->data != select)
    {
        printf("没有找到该节点\n");
        return false;
    }
    else // 修改节点数据
    {
        p->data = data;
    }
    return true;
}
// 查询节点
bool search_node(mange_node *mange, data_t data)
{
    data_node *q1 = mange->head;
    int i = 0;
    while (q1 != NULL)
    {
        if (q1->data == data)
        {
            printf("找到%d为第%d个节点的数据\n", data, i + 1);
            return true;
        }
        i++;
        q1 = q1->next;
    }
    return false;
}
// 打印链表
void print_linklist(mange_node *mange)

{
    data_node *p = mange->head;
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}