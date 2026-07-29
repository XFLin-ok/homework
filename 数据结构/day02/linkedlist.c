#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//存储的数据类型
typedef int Data_t;

//设计数据结点的类型
typedef struct DataNode
{
    Data_t data; //int data;
    struct DataNode *next; //错误的写法DataNode *next;
}DataNode;

//设计管理结点的类型
typedef struct Mange
{
    int num;
    struct DataNode *Head;
    struct DataNode *Tail;
}Mange_t;

//创建空链表--先创建管理结点
Mange_t *LinkedList_MangeCreate(void)
{
    //申请堆空间
    // Mange_t *PMange=(Mange_t *)malloc(1*sizeof(struct Mange));
    Mange_t *PMange=(Mange_t *)malloc(1*sizeof(Mange_t));
    if(PMange==NULL)
    {
        printf("PMange malloc fail\n");
        return NULL;
    }

    //给初始化
    PMange->num=0;
    PMange->Head=NULL;
    PMange->Tail=NULL;

    return PMange;
}

//--创建空链表--存数据的头结点
// bool  LinkedList_DateNodeCreate(Mange_t *PMange,Data_t data)
// {
//     //申请数据结点的堆空间
//     DataNode* DataN=(DataNode*)malloc(1*sizeof(DataNode));
//     if(DataN == NULL)
//     {
//         printf("DataN malloc fail\n");
//         return false;
//     }

//     //赋值数据
//     DataN->data=data;

//     DataN->next=NULL;

//     //登记链表
//     PMange->Head=DataN;
//     PMange->Tail=DataN;
//     PMange->num++;

//     return true;
// }

//创建新的结点
DataNode* LinkedList_DateNodeCreate(Data_t data)
{
    //申请数据结点的堆空间
    DataNode* DataN=(DataNode*)malloc(1*sizeof(DataNode));
    if(DataN == NULL)
    {
        printf("DataN malloc fail\n");
        return NULL;
    }

    //赋值数据
    DataN->data=data;
    DataN->next=NULL;

    return DataN;
}


//尾插法
bool  LinkedList_Tailinsert(Mange_t *PMange,Data_t data)
{
    //创建新结点
    DataNode* NewData= LinkedList_DateNodeCreate(data);
    if(NewData==NULL)
    {
        printf("new Node fail\n");
        return false;
    }

    //登记加入链表
    //空链表
    if(PMange->Head==NULL)
    {

        PMange->Head=NewData;
        PMange->Tail=NewData;
        PMange->num++;
    }
    else  //非空链表
    {
        //1.并入链表
        PMange->Tail->next=NewData; //尾插根据尾指针来方便
        //2.更新尾指针
        PMange->Tail=NewData;
        PMange->num++;    
    }
   
    //
    return true;
}

//头插法
bool  LinkedList_Headinsert(Mange_t *PMange,Data_t data)
{
    //创建新结点
    DataNode* NewData= LinkedList_DateNodeCreate(data);
    if(NewData==NULL)
    {
        printf("new Node fail\n");
        return false;
    }

    //判断是否为空链表
    //if(PMange->num == 0)
    if(PMange->Head == NULL) //空链表
    {
        PMange->Head=NewData;
        PMange->Tail=NewData;

        PMange->num++;
    }
    else //非空链表
    {
        //1.并入
        NewData->next=PMange->Head;

        //2.更新头
        PMange->Head=NewData;

        PMange->num++;
    }
    return true;
}


//链表打印
void LinkedList_print(Mange_t *PMange)
{
    //int temp=PMange->num;//用num不能访问
    DataNode* TempData=PMange->Head; //首结点


    while(TempData !=NULL)
    {
        printf("%d\t",TempData->data);
        TempData=TempData->next;
    }
    printf("\n");
}

//删除结点 删除指定数据结点  //头删 尾删  中间删
bool  LinkedList_DeleteNode(Mange_t *PMange,Data_t data)
{
    DataNode* PDataN=PMange->Head;  //要找的删除的数据结点
    DataNode* TempData=NULL; //要删结点的前一个

    if(PDataN==NULL)
    {
        printf("Linkedlist is empty\n");
        return false;
    }

    while(PDataN!=NULL)
    {
        if(PDataN->data == data)
        {
            break;
        }

        TempData=PDataN; //记录当前结点
        PDataN=PDataN->next; //移动到下一个
    }

    //如果找到的是首结点
    if(PDataN == PMange->Head)
    {
        //1.更新链表
        PMange->Head=PDataN->next;//头指针指向p结点的下一个
        //2.断开
        PDataN->next=NULL;
        //3.
        free(PDataN);
    }
    else if(PDataN == PMange->Tail)
    {
        //1.更新链表
        PMange->Tail=TempData;
        //2.断开
        TempData->next=NULL;
        //3.释放
        free(PDataN);
    }
    else
    {
        //1.更新链表
        TempData->next=PDataN->next;
        //2.断开
        PDataN->next=NULL;
        //3.
        free(PDataN);
    }

    //更新num
    PMange->num--;

    return true;
    
}



int main()
{
    //1.创建管理结点
    Mange_t * PMange= LinkedList_MangeCreate();

    //2.尾插
    LinkedList_Tailinsert(PMange,10);
    LinkedList_Tailinsert(PMange,20);
    LinkedList_Tailinsert(PMange,30);

    LinkedList_Headinsert(PMange,40);
    LinkedList_Headinsert(PMange,50);
    LinkedList_Headinsert(PMange,60);

    LinkedList_DeleteNode(PMange,40);
    //3.打印调试
    LinkedList_print(PMange);
}


