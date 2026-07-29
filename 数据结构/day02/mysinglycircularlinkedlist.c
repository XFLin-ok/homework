#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 设计结点
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

// 创建空的循环链表---管理结点
Mange_t *CircularLinkedList_Create(void)
{
    // 1.申请堆空间
    Mange_t *Pmange = (Mange_t *)malloc(1 * sizeof(struct Mange));
    if (Pmange == NULL)
    {
        printf("Pmange malloc fail\n");
        return NULL;
    }

    // 2.初始化
    Pmange->Head = NULL;
    Pmange->Tail = NULL;
    Pmange->num = 0;

    return Pmange;
}

DataNode *CircularLinkedList_NewNode(Data_t data)
{
    // 1.申请堆空间
    DataNode *NewNode = (DataNode *)malloc(1 * sizeof(DataNode));
    if (NewNode == NULL)
    {
        printf("NewNode malloc fail\n");
        return NULL;
    }

    // 2.初始化数据
    NewNode->data = data;
    NewNode->next = NULL;

    return NewNode;
}
// 尾插
bool CircularLinkedList_Tailinsert(Mange_t *Pmange, Data_t data)
{
    // 1.创建新结点
    DataNode *NewNode = CircularLinkedList_NewNode(data);
    if (NewNode == NULL)
    {
        printf("NewNode fail\n");
        return false;
    }

    // 先分情况
    // 判断空链表
    if (Pmange->Head == NULL)
    {
        // 更新首尾结点地址
        Pmange->Head = NewNode;
        Pmange->Tail = NewNode;

        // 构成循环
        NewNode->next = NewNode;

        // 数量+1
        Pmange->num++;
    }
    else
    {
        // 1.并入链表
        NewNode->next = Pmange->Head;

        // 2.旧尾指向新尾
        Pmange->Tail->next = NewNode;
        // 3.更新为新尾结点地址
        Pmange->Tail = NewNode;
        // 4.
        Pmange->num++;
    }

    return true;
}

// 尾删除节点
// bool del_tailnode(Mange_t *Pmange)
// {
//     DataNode *p = Pmange->Head;
//     DataNode *tmp = NULL;
//     // 判断空链表
//     if (Pmange == NULL)
//     {
//         return false;
//     }
//     // 只有一个节点
//     if (Pmange->num == 1)
//     {
//         free(Pmange->Tail);
//         Pmange->Head = NULL;
//         Pmange->Tail = NULL;
//         Pmange->num = 0;
//         return true;
//     }

//     // 找到前驱节点
//     while (1)
//     {
//         if (p == Pmange->Tail)
//         {
//             break;
//         }

//         tmp = p;
//         p = p->next;
//     }

//     p->next = NULL;
//     tmp->next = Pmange->Head;
//     Pmange->Tail = tmp;
//     Pmange->num--;
//     return true;
// }
// 删除节点
bool del_node(Mange_t *Pmange, Data_t data)
{
    DataNode *p = Pmange->Head;
    DataNode *tmp = NULL;
    // 判断空链表
    if (Pmange == NULL)
    {
        return false;
    }
    // 只有一个节点
    if (Pmange->num == 1)
    {
        free(Pmange->Tail);
        Pmange->Head = NULL;
        Pmange->Tail = NULL;
        Pmange->num = 0;
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
    if (p->next == Pmange->Head) // 尾删
    {
        p->next = NULL;
        tmp->next = Pmange->Head;
        Pmange->Tail = tmp;
        Pmange->num--;
        free(p);
    }
    else if (p == Pmange->Head) // 头删
    {
        Pmange->Head = p->next;
        Pmange->Tail->next = p->next;
        p->next = NULL;
        Pmange->num--;
        free(p);
    }
    else // 中间删
    {
        tmp->next = p->next;
        p->next = NULL;
        Pmange->num--;
        free(p);
    }
    return true;
}
// 查询节点
bool search_node(Mange_t *Pmange, Data_t data)
{
    DataNode *q1 = Pmange->Head;
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
    } while (q1 != Pmange->Head);
    return false;
}
// 修改节点
bool change_node(Mange_t *Pmange)
{
    Data_t select = 0;
    Data_t data = 0;
    DataNode *p = Pmange->Head;
    printf("输入需要修改节点的原数据\n");
    scanf("%d", &select);
    printf("输入需要修改后的数据\n");
    scanf("%d", &data);
    // 寻找节点
    while (p->data != select && p->next != Pmange->Head)
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
// 寻找倒数第k个元素
int search_k(Mange_t *Pmange, Data_t k, Data_t num)
{
    DataNode *p = Pmange->Head;
    int i;
    // 判断特殊情况
    if (p == NULL || num - k < 0)
    {
        printf("not found\n");
        return 0;
    }
    // 遍历到倒数第k个节点
    for (int i = 0; i < num - k; i++)
    {
        p = p->next;
    }

    printf("倒数第%d个元素:%d\n", k, p->data);
    return 1;
}

// 遍历打印
void CircularLinkedList_print(Mange_t *Pmange)
{
    DataNode *TempNode = Pmange->Head;

    do
    {
        // 1.打印数据
        printf("%d\t", TempNode->data);

        // 2.移动
        TempNode = TempNode->next;

    } while (TempNode != Pmange->Head);

    printf("\n");
}

int main()
{

    Mange_t *Pmange = CircularLinkedList_Create();

    CircularLinkedList_Tailinsert(Pmange, 10);
    CircularLinkedList_Tailinsert(Pmange, 20);
    CircularLinkedList_Tailinsert(Pmange, 30);
    CircularLinkedList_Tailinsert(Pmange, 40);
    CircularLinkedList_Tailinsert(Pmange, 50);

    CircularLinkedList_print(Pmange);

    del_node(Pmange, 10);

    CircularLinkedList_print(Pmange);

    search_node(Pmange, 50);

    // change_node(Pmange);

    CircularLinkedList_print(Pmange);

    search_k(Pmange, 5, Pmange->num);
}
