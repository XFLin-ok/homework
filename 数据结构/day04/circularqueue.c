#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 基于顺序表 循环队列

// 设计数据类型
typedef int data_t;

// 设计管理结点
typedef struct circularqueue
{
    data_t *Head; // 记录首地址
    int front;    // 记录队首下标
    int rear;     // 记录队尾下标
    int maxnum;   // 最大容量
} Cqueue_t;

// 创建空队列
Cqueue_t *CircularQueue_Create(int size)
{
    // 1.申请管理结点的堆空间
    Cqueue_t *pmange = (Cqueue_t *)calloc(1, sizeof(Cqueue_t));
    if (pmange == NULL)
    {
        printf("pmange calloc fail\n");
        return NULL;
    }

    // 2.初始化
    pmange->front = 0;     // 队首下标
    pmange->rear = 0;      // 队尾下标
    pmange->maxnum = size; // 容量
    pmange->Head = (data_t *)calloc(size, sizeof(data_t));
    if (pmange->Head == NULL)
    {
        printf("Head calloc fail\n");
        return NULL;
    }

    return pmange;
}

// 入队--尾插
bool CircularQueue_enqueue(Cqueue_t *pmange, data_t data)
{
    // 特殊情况 满队
    if ((pmange->rear + 1) % (pmange->maxnum) == pmange->front)
    {
        printf("queue is full\n");
        return false;
    }

    // 直接放入数据
    pmange->Head[pmange->rear] = data;
    // 更新尾下标
    pmange->rear = (pmange->rear + 1) % (pmange->maxnum); // 特别注意:直接+1 不能构成循环

    return true;
}

// 出队--头删
data_t CircularQueue_dequeue(Cqueue_t *pmange)
{
    data_t tempbuf = 0;
    // 特殊情况 空队
    if (pmange->rear == pmange->front)
    {
        printf("queue is empty\n");
        return -1; // 考虑是否影响数据
    }

    // 先拿到数据
    tempbuf = pmange->Head[pmange->front];
    // 再更新 队首
    pmange->front = (pmange->front + 1) % (pmange->maxnum);

    return tempbuf;
}

// 遍历
void CircularQueue_print(Cqueue_t *pmange)
{
    int i = pmange->front;

    for (; i % (pmange->maxnum) != pmange->rear;)
    {
        printf("%d\t", pmange->Head[i]);
        i = (i + 1) % (pmange->maxnum);
    }
    printf("\n");
}

int main()
{
    Cqueue_t *pmange = CircularQueue_Create(10);

    CircularQueue_enqueue(pmange, 10);
    CircularQueue_enqueue(pmange, 20);
    CircularQueue_enqueue(pmange, 30);
    CircularQueue_enqueue(pmange, 40);

    printf("dequeue data:%d\n", CircularQueue_dequeue(pmange));
    printf("dequeue data:%d\n", CircularQueue_dequeue(pmange));
    printf("dequeue data:%d\n", CircularQueue_dequeue(pmange));
    printf("dequeue data:%d\n", CircularQueue_dequeue(pmange));
    printf("dequeue data:%d\n", CircularQueue_dequeue(pmange));
    CircularQueue_print(pmange);
}