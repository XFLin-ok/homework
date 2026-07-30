#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 航班信息类型
typedef struct flight_info
{
    char id[10];
    int num;
    char origin_palce[100];
    char destination[100];
    char time[10];
    float price;
    int maxpassengernum;
    int passengernum;
    struct flight_info *prev;
    struct flight_info *next;
} flight_info;
// 管理航班类型
typedef struct flight_mange
{
    int flightnum;
    struct flight_info *head;
    struct flight_info *tail;
} flight_mange;
// 乘客信息类型
typedef struct passenger_info
{
    struct flight_info *ticket;
    int flightnum;
    char name[24];
    char bookingStatus[10];
    struct passenger_info *prev;
    struct passenger_info *next;

} passenger_info;
// 管理乘客类型
typedef struct passenger_mange
{
    int num;
    struct passenger_info *head;
    struct passenger_info *tail;
} passenger_mange;

// 创建航班管理节点
flight_mange *flightmange_creat()
{
    flight_mange *flighmange = (flight_mange *)malloc(1 * sizeof(flight_mange));
    if (flighmange == NULL)
    {
        printf("flighmange malloc fail\n");
        return NULL;
    }
    flighmange->flightnum = 0;
    flighmange->head = NULL;
    flighmange->tail = NULL;
    return flighmange;
}
// 创建新节点 新航班
flight_info *flight_create()
{

    flight_info *flight = (flight_info *)malloc(1 * sizeof(flight_info));
    if (flight == NULL)
    {
        printf("flight malloc fail\n");
        return NULL;
    }
    flight->id[0] = 0;
    flight->destination[0] = 0;
    flight->num = 0;
    flight->maxpassengernum = 0;
    flight->origin_palce[0] = 0;
    flight->price = 0;
    flight->time[0] = 0;
    flight->passengernum = 0;
    flight->next = NULL;
    flight->prev = NULL;
    return flight;
}
// 创建乘客管理节点
passenger_mange *passenger_mange_create()
{
    passenger_mange *pmange = (passenger_mange *)malloc(1 * sizeof(passenger_mange));
    if (pmange == NULL)
    {
        printf("pmange malloc fail\n");
        return NULL;
    }
    pmange->num = 0;
    pmange->head = NULL;
    pmange->tail = NULL;
    return pmange;
}

// 创建乘客
passenger_info *passenger_create()
{
    passenger_info *newpassenger = (passenger_info *)malloc(1 * (sizeof(passenger_info)));
    if (newpassenger == NULL)
    {
        printf("newpassenger malloc fail\n");
        return NULL;
    }
    newpassenger->flightnum = 0;
    newpassenger->name[0] = 0;
    newpassenger->bookingStatus[0] = 0;
    newpassenger->ticket = NULL;
    newpassenger->next = NULL;
    newpassenger->prev = NULL;
    return newpassenger;
}
// 新增乘客与信息录入
passenger_info *passenger_add(passenger_mange *pmange)
{
    passenger_info *newpassenger = passenger_create();
    printf("输入姓名：\n");
    scanf("%s", newpassenger->name);
    printf("输入航班编号：\n");
    scanf("%d", &newpassenger->flightnum);
    if (pmange->head == NULL)
    {
        pmange->head = newpassenger;
        pmange->tail = newpassenger;
        pmange->num++;
    }
    else
    {
        pmange->tail->next = newpassenger;
        newpassenger->prev = pmange->tail;
        pmange->tail = newpassenger;
        pmange->num++;
    }
    return newpassenger;
}

// 插入节点 录入航班信息
bool flight_info_insert(flight_mange *flighmange)
{
    while (1)
    {
        int select;
        flight_info *newflight = flight_create();
        printf("输入航班编号：\n");
        scanf("%d", &newflight->num);
        printf("输入航班ID：\n");
        scanf("%s", newflight->id);
        printf("输入航班始发地：\n");
        scanf("%s", newflight->origin_palce);
        printf("输入航班目的地：\n");
        scanf("%s", newflight->destination);
        printf("输入航班起飞时间：\n");
        scanf("%s", newflight->time);
        printf("输入航班价格：\n");
        scanf("%f", &newflight->price);
        printf("输入航班最大乘客数：\n");
        scanf("%d", &newflight->maxpassengernum);
        if (flighmange->head == NULL)
        {
            flighmange->head = newflight;
            flighmange->tail = newflight;
            newflight->next = NULL;
            newflight->prev = NULL;
            flighmange->flightnum++;
        }
        else
        {
            flighmange->tail->next = newflight;
            newflight->prev = flighmange->tail;
            flighmange->tail = newflight;
            flighmange->flightnum++;
        }
        printf("-------1、继续录入 2、返回-------\n");
        scanf("%d", &select);
        if (select == 2)
        {
            break;
        }
    }
    return true;
}
// 删除航班信息
bool flight_info_del(flight_mange *flighmange)
{
    int tmpnum = 0;
    flight_info *p = flighmange->head;
    if (p == NULL)
    {
        printf("无航班信息！\n");
        return false;
    }
    printf("请输入需要删除的航班编号：\n");
    scanf("%d", &tmpnum);
    // 找到该航班
    while (p != NULL)
    {
        if (p->num == tmpnum)
        {
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        printf("无航班信息！\n");
        return false;
    }
    // 只有一个节点
    if (p->next == NULL)
    {
        flighmange->head = NULL;
        flighmange->tail = NULL;
        flighmange->flightnum--;
        free(p);
    }
    // 尾删
    else if (p->next == NULL)
    {
        flighmange->tail = p->prev;
        p->prev->next = NULL;
        p->prev = NULL;
        flighmange->flightnum--;
        free(p);
    }
    // 头删
    else if (p == flighmange->head)
    {
        flighmange->head = p->next;
        p->next->prev = NULL;
        p->next = NULL;
        flighmange->flightnum--;
        free(p);
    }
    // 中间删
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->prev = NULL;
        p->next = NULL;
        flighmange->flightnum--;
        free(p);
    }
    printf("删除成功！\n");
    return true;
}
// 浏览订票信息
bool book_info_browse(flight_mange *flighmange, passenger_mange *pmange)
{
    passenger_info *p = pmange->head;
    if (p == NULL)
    {
        printf("暂无订票信息!\n");
        return false;
    }

    printf("订票信息如下：\n");
    for (int i = 1; i <= pmange->num; i++)
    {
        printf("%d、%s 航班编号:%d 状态：%s\n", i, p->name, p->flightnum, p->bookingStatus);
        p = p->next;
    }
    return true;
}
// 查看候补
bool check_alternate(passenger_mange *pmange)
{
    passenger_info *p = pmange->head;
    if (p == NULL)
    {
        printf("暂无订单\n");
        return false;
    }

    while (p != NULL)
    {
        if (strcmp(p->bookingStatus, "候补") == 0)
        {
            printf("姓名：%s 航班编号：%d 状态：%s\n", p->name, p->flightnum, p->bookingStatus);
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        printf("无候补订单\n");
        return false;
    }
    return true;
}
// 订票
bool book_tickets(flight_mange *flighmange, passenger_mange *pmange)
{
    flight_info *p = flighmange->head;
    // 判断是否有航班
    if (p == NULL)
    {
        printf("当前无可飞航班！\n");
        return false;
    }
    printf("当前可订票航班有：\n");
    for (int i = 0; i < flighmange->flightnum; i++)
    {
        printf("航班编号%d\n", p->num);
        p = p->next;
    }
    // 重置指针p
    p = flighmange->head;
    // 录入个人信息并选取航班
    passenger_info *newpassenger = passenger_add(pmange);
    int tmpnum = newpassenger->flightnum;
    while (p != NULL)
    {
        if (p->num == tmpnum)
        {
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        printf("无航班信息！\n");
        return false;
    }
    newpassenger->ticket = p;
    p->passengernum++;
    if (p->passengernum <= p->maxpassengernum)
    {
        strcpy(newpassenger->bookingStatus, "订票成功");
        printf("订票成功！航班编号为%d的航班信息为:\n航班ID:%s\n航班始发地：%s\n航班目的地：%s\n航班起飞时间：%s\n航班价格：%f\n航班最大乘客数：%d\n航班已订乘客数：%d\n请合理安排时间登机!\n", p->num, p->id, p->origin_palce, p->destination, p->time, p->price, p->maxpassengernum, p->passengernum);
    }
    else
    {
        strcpy(newpassenger->bookingStatus, "候补");
        printf("航班无剩余机票，进入候补队列\n");
    }
    return true;
}
// 改签
bool change_tickets(flight_mange *flighmange, passenger_mange *pmange)
{
    char name[24] = {0};
    int changeflight;
    printf("姓名：\n");
    scanf("%s", name);
    passenger_info *p = pmange->head;
    flight_info *f = flighmange->head;
    while (p != NULL)
    {
        if (strcmp(p->name, name) == 0)
        {
            printf("请输入需要将航班编号%d改为:", p->flightnum);
            p->ticket->passengernum--;
            scanf("%d", &changeflight);
            while (f != NULL)
            {
                if (f->num == changeflight)
                {
                    break;
                }
                f = f->next;
            }
            if (f == NULL)
            {
                printf("无该航班信息！\n");
                return false;
            }
            p->ticket = f;
            f->passengernum++;
            if (f->passengernum <= f->maxpassengernum)
            {
                strcpy(p->bookingStatus, "改签成功");
                printf("改签成功！航班编号为%d的航班信息为:\n航班ID:%s\n航班始发地：%s\n航班目的地：%s\n航班起飞时间：%s\n航班价格：%f\n航班最大乘客数：%d\n航班已订乘客数：%d\n请合理安排时间登机!\n", f->num, f->id, f->origin_palce, f->destination, f->time, f->price, f->maxpassengernum, f->passengernum);
            }
            else
            {
                strcpy(p->bookingStatus, "候补");
                printf("航班无剩余机票，进入候补队列\n");
            }
            break;
        }

        p = p->next;
    }
    if (p == NULL)
    {

        printf("%s的订单不存在!\n", name);
        return false;
    }

    return true;
}
// 退票
bool del_tickets(passenger_mange *pmange)
{
    char name[24] = {0};
    int select = 0;
    passenger_info *p = pmange->head;
    if (p == NULL)
    {
        printf("暂无订票信息!\n");
        return false;
    }
    printf("输入姓名：\n");
    scanf("%s", name);
    while (p != NULL)
    {
        if (strcmp(p->name, name) == 0)
        {
            printf("姓名%s的订票信息如下:\n", name);
            printf("航班编号：%d\n订单状态:%s\n是否确认退票(1/0)?\n", p->flightnum, p->bookingStatus);
            scanf("%d", &select);
            if (select == 1)
            {
                if (pmange->num == 1)
                {
                    pmange->head = NULL;
                    pmange->tail = NULL;
                    pmange->num--;
                    free(p);
                }
                else if (p->next == NULL)
                {
                    pmange->tail == p->prev;
                    p->prev->next = NULL;
                    p->prev == NULL;
                    pmange->num--;
                    free(p);
                }
                else
                {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    p->next = NULL;
                    p->prev = NULL;
                    pmange->num--;
                    free(p);
                }
                printf("退票成功！！\n");
            }
            else
            {
                printf("退票失败！！\n");
                return false;
            }
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        printf("找不到%s的订单!\n", name);
        return false;
    }
    return true;
}
// 浏览航班信息，遍历
bool flight_info_browse(flight_mange *flighmange)
{
    int tmpnum = 0;
    flight_info *p = flighmange->head;
    if (p == NULL)
    {
        printf("暂无航班信息！\n");
        return false;
    }
    while (1)
    {

        printf("请输入需要查询的航班编号：\n");
        scanf("%d", &tmpnum);
        while (p != NULL)
        {
            if (p->num == tmpnum)
            {
                break;
            }
            p = p->next;
        }
        if (p == NULL)
        {
            printf("未找到编号为%d的航班!\n", tmpnum);
            return false;
        }
        printf("航班编号为%d的航班信息为:\n", p->num);
        printf("航班ID:%s\n", p->id);
        printf("航班始发地：%s\n", p->origin_palce);
        printf("航班目的地：%s\n", p->destination);
        printf("航班起飞时间：%s\n", p->time);
        printf("航班价格：%f\n", p->price);
        printf("航班最大乘客数：%d\n", p->maxpassengernum);
        printf("航班已订乘客数：%d\n", p->passengernum);
        int select;
        printf("-------1、继续查询 2、退出-------\n");
        scanf("%d", &select);
        if (select == 2)
        {
            break;
        }
    }
    return true;
}
bool search_persional_flightinfo(flight_mange *flighmange, passenger_mange *pmange)
{
    char name[24] = {0};
    flight_info *f = flighmange->head;
    passenger_info *p = pmange->head;
    if (f == NULL)
    {
        printf("暂无航班信息！\n");
        return false;
    }
    printf("请输入姓名：\n");
    scanf("%s", name);
    while (p != NULL)
    {
        if (strcmp(p->name, name) == 0)
        {
            if (strcmp(p->bookingStatus, "候补"))
            {
                printf("该订单为候补订单，暂无航班信息！\n");
                return false;
            }

            printf("%s的航班信息为:\n", name);
            printf("航班ID:%s\n", p->ticket->id);
            printf("航班始发地：%s\n", p->ticket->origin_palce);
            printf("航班目的地：%s\n", p->ticket->destination);
            printf("航班起飞时间：%s\n", p->ticket->time);
            printf("航班价格：%f\n", p->ticket->price);
            printf("航班最大乘客数：%d\n", p->ticket->maxpassengernum);
            printf("航班已订乘客数：%d\n", p->ticket->passengernum);
            break;
            ;
        }

        p = p->next;
    }
    if (p == NULL)
    {
        printf("%s暂无相关订单,请购票!\n", name);
    }
}
// 系统入口
bool system_enhance()
{
    int select;
    int select1;
    int select2;
    int select3;
    int select4;
    flight_mange *flighmange = flightmange_creat();
    passenger_mange *pmange = passenger_mange_create();
    while (1)
    {

        printf("欢迎进入航班信息管理系统！请选择登入身份\n1、票务人员\n2、旅客\n3、退出\n");
        scanf("%d", &select);
        while (1)
        {

            switch (select)
            {
            case 1:
                printf("请选择需要的操作：\n1、录入航班信息\n2、删除航班信息\n3、浏览航班信息\n4、浏览订票信息\n5、查看候补\n");
                scanf("%d", &select1);
                break;
            case 2:
                printf("请选择需要的操作：\n1、订票\n2、改签\n3、退票\n4、浏览航班信息\n5、查询自己的航班信息\n");
                scanf("%d", &select2);
                break;
            case 3:
                return false;

            default:
                break;
            }

            if (select == 1)
            {

                switch (select1)
                {
                case 1:
                    flight_info_insert(flighmange);
                    break;
                case 2:
                    flight_info_del(flighmange);
                    break;
                case 3:
                    flight_info_browse(flighmange);
                    break;
                case 4:
                    book_info_browse(flighmange, pmange);
                    break;
                case 5:
                    check_alternate(pmange);
                    break;
                case 6:
                    break;
                default:
                    printf("输入有误！\n");
                    break;
                }
            }
            else
            {
                switch (select2)
                {
                case 1:
                    book_tickets(flighmange, pmange);
                    break;
                case 2:
                    change_tickets(flighmange, pmange);
                    break;
                case 3:
                    del_tickets(pmange);
                    break;
                case 4:
                    flight_info_browse(flighmange);
                    break;
                case 5:
                    search_persional_flightinfo(flighmange, pmange);
                    break;
                case 6:
                    break;
                default:
                    printf("输入有误！\n");
                    break;
                }
            }
            printf("-------1、返回上一级 2、退出-------\n");
            scanf("%d", &select4);
            if (select4 == 2)
            {
                break;
            }
        }
        printf("-------1、返回主界面 2、退出程序-------\n");
        scanf("%d", &select3);
        if (select3 == 2)
        {
            break;
        }
    }
}
int main()
{
    system_enhance();
}
