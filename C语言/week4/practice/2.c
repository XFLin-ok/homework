#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insert_top_node(struct node *head, struct node *xnew)
{
    xnew->next = head->next;
    head->next = xnew;
}
void change_node(struct node *head, int x, int y)
{
    struct node *p = head->next;
    while (p != NULL)
    {
        if (p->data == x)
        {
            p->data = y;
            printf("修改成功！\n");
        }

        p = p->next;
    }
}
struct node *create_node(int x)
{
    struct node *xnew = (struct node *)malloc(sizeof(struct node));
    xnew->data = x;
    xnew->next = NULL;
    return xnew;
}
struct node insert_node(struct node *head, struct node *xnew)
{
    struct node *p = head->next;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = xnew;
}
// 遍历链表
void show_head(struct node *head)
{
    struct node *p = head->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
void search_node(struct node *head, int x)
{
    struct node *p = head->next;
    while (p != NULL)
    {
        if (p->data == x)
            printf("找到了！\n");
        p = p->next;
    }
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    struct node *p1 = create_node(10);
    printf("头插\n");
    insert_top_node(head, p1);
    insert_top_node(head, create_node(20));
    insert_top_node(head, create_node(30));
    insert_top_node(head, create_node(40));
    insert_top_node(head, create_node(50));
    show_head(head);
    search_node(head, 40);
    printf("尾插\n");
    insert_node(head, create_node(20));
    insert_node(head, create_node(30));
    insert_node(head, create_node(40));
    insert_node(head, create_node(50));
    show_head(head);
    change_node(head, 30, 3000);
    show_head(head);

    return 0;
}