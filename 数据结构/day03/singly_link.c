#include "singly_link.h"

// 创建管理节点
mange_node *mange_node_create()
{
    // 分配堆空间
    mange_node *mange = (mange_node *)malloc(1 * sizeof(mange_node));
    // 判断是否成功分配
    if (mange == NULL)
    {
        printf("create mange node fail\n");
        return NULL;
    }
    // 初始化
    mange->head = NULL;
    mange->tail = NULL;
    mange->num = 0;
    return mange;
}
// 创建新节点
data_node *data_node_create(data_t data)
{
    // 分配堆空间
    data_node *node = (data_node *)malloc(1 * sizeof(data_node));
    if (node == NULL)
    {
        printf("create node fail\n");
        return NULL;
    }
    // 初始化
    node->data = data;
    node->next = NULL;
    return node;
}
// 尾插法
bool tail_insert(mange_node *mange, data_t data)
{
    // 创建新节点
    data_node *newnode = data_node_create(data);
    if (newnode == NULL)
    {
        printf("create new node fail\n");
        return false;
    }
    // 空链表
    if (mange->head == NULL)
    {
        mange->head = newnode;
        mange->tail = newnode;
        mange->num++;
    }
    else // 非空链表
    {
        mange->tail->next = newnode;
        mange->tail = newnode;
        mange->num++;
    }
    return true;
}
// 头插法
bool head_insert(mange_node *mange, data_t data)
{
    // 创建节点
    data_node *newnode = data_node_create(data);
    if (newnode == NULL)
    {
        printf("create new node fail\n");
        return false;
    }
    // 空链表
    if (mange->head == NULL)
    {
        mange->head = newnode;
        mange->tail = newnode;
        mange->num++;
    }
    else // 非空链表
    {

        newnode->next = mange->head;
        mange->head = newnode;
        mange->num++;
    }
    return true;
}
// 删除节点
bool del_node(mange_node *mange, data_t data)
{
    data_node *q = mange->head;
    data_node *tmp = NULL;
    while (q != NULL)
    {
        if (q->data == data)
        {
            break;
        }
        tmp = q;
        q = q->next;
    }
    if (q == mange->head)
    {
        mange->head = q->next;
        q->next = NULL;
        mange->num--;
        free(q);
        printf("删除了数据为%d的节点\n", data);
    }
    else if (q == mange->tail)
    {
        mange->tail = tmp;
        tmp->next = NULL;
        mange->num--;
        free(q);
        printf("删除了数据为%d的节点\n", data);
    }
    else
    {
        tmp->next = q->next;
        q->next = NULL;
        mange->num--;
        free(q);
        printf("删除了数据为%d的节点\n", data);
    }
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
// 删除最小值节点
void del_mindata(mange_node *mange)
{
    data_node *q2 = mange->head;
    int min = q2->data;
    while (q2 != NULL)
    {
        if ((q2->data) < min)
        {
            min = q2->data;
        }
        q2 = q2->next;
    }
    printf("最小值为%d\n", min);
    del_node(mange, min);
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
    while (p->data != select || p->next != NULL)
    {
        p = p->next;
    }
    if (p->data != select)
    {
        printf("没有找到该节点\n");
        return false;
    }
    else
    {
        p->data = data;
    }
    return true;
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