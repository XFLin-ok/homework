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
        newnode->prev = newnode;
        newnode->next = newnode;
        mange->num++;
    }
    else // 非空链表
    {
        mange->head->prev = newnode;
        newnode->next = mange->head;
        mange->tail->next = newnode;
        newnode->prev = mange->tail;
        mange->head = newnode;
        mange->num++;
    }
    return true;
}
// 尾插
bool tail_node(mange_node *mange, data_t data)
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
        newnode->prev = newnode;
        newnode->next = newnode;
        mange->num++;
    }
    else
    {
        newnode->prev = mange->tail;
        mange->tail->next = newnode;
        newnode->next = mange->head;
        mange->tail = newnode;
        mange->num++;
    }
}
// 删除节点
bool del_node(mange_node *mange, data_t data)
{
    data_node *p = mange->head;
    data_node *tmp = NULL;
    // 判断空链表
    if (mange == NULL)
    {
        return false;
    }
    // 只有一个节点
    if (mange->num == 1)
    {
        free(mange->tail);
        mange->head = NULL;
        mange->tail = NULL;
        mange->num = 0;
        return true;
    }
    // 找到前驱节点与目标节点
    while (1)
    {
        if (p->data == data)
        {
            break;
        }

        tmp = p;
        p = p->next;
    }
    if (p->next == mange->head) // 尾删
    {

        tmp->next = mange->head;
        mange->head->prev = p;
        p->next = NULL;
        p->prev = NULL;
        mange->tail = tmp;
        mange->num--;
        free(p);
    }
    else if (p == mange->head) // 头删
    {
        mange->head = p->next;
        mange->tail->next = p->next;
        p->next->prev = mange->tail;
        p->prev = NULL;
        p->next = NULL;
        mange->num--;
        free(p);
    }
    else // 中间删
    {
        tmp->next = p->next;
        p->next->prev = tmp;
        p->prev = NULL;
        p->next = NULL;
        mange->num--;
        free(p);
    }
    return true;
}
// 查询节点
bool search_node(mange_node *mange, data_t data)
{
    data_node *q1 = mange->head;
    int i = 0;
    do
    {
        if (q1->data == data)
        {
            printf("找到%d为第%d个节点的数据\n", data, i + 1);
            return true;
        }
        i++;
        q1 = q1->next;
    } while (q1 != mange->head);
    return false;
}

// 修改节点
bool change_node(mange_node *mange)
{
    data_t select = 0;
    data_t data = 0;
    data_node *p = mange->head;
    printf("输入需要修改节点的原数据\n");
    scanf("%d", &select);
    // 寻找节点
    while (p->data != select && p->next != mange->head)
    {
        p = p->next;
    }
    if (p->data != select)
    {
        printf("没有找到该节点\n");
        return false;
    }
    printf("输入需要修改后的数据\n");
    scanf("%d", &data);
    // 修改节点数据
    {
        p->data = data;
    }
    return true;
}

// 打印链表
void print_linklist(mange_node *mange)

{
    data_node *p = mange->head;
    do
    {
        printf("%d\t", p->data);
        p = p->next;
    } while (p != mange->head);
    printf("\n");
}

int main()
{
    mange_node *mange = create_mangenode();

    head_insert(mange, 10);
    head_insert(mange, 20);
    head_insert(mange, 30);

    tail_node(mange, 40);
    tail_node(mange, 50);
    tail_node(mange, 60);

    del_node(mange, 40);

    print_linklist(mange);
    search_node(mange, 60);

    change_node(mange);

    print_linklist(mange);
}