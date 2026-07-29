#include <stdio.h>
#include <stdlib.h>
struct node
{
    int a;
    struct node *next;
};

struct node *create_node(int x)
{
    struct node *xnew = malloc(sizeof(struct node));
    xnew->a = x;
    xnew->next = NULL;
    return xnew;
}
struct node *insert_node(struct node *p1, struct node *p2)
{
    struct node *p = p1;
    while (p->next != NULL)
    {
        p = p->next;
    }
}
void insert_top_node(struct node *head, struct node *xnew)
{
    xnew->next = head->next;
    head->next = xnew;
}
void change_node(struct node *head, int data, int cdata)
{
    struct node *p = head;
    while (p != NULL)
    {
        if (p->a == data)
        {
            p->a = cdata;
            printf("修改成功！\n");
        }
        p = p->next;
    }
}
int main()
{
    struct node *head = create_node(10);
    struct node *p = head;
    insert_top_node(head, create_node(20));
    insert_top_node(head, create_node(30));
    insert_top_node(head, create_node(40));
    insert_top_node(head, create_node(50));
    while (p != NULL)
    {
        printf("%d\n", p->a);
        p = p->next;
    }
    change_node(head, 30, 3000);
    struct node *q = head;
    while (q != NULL)
    {
        printf("%d\n", q->a);
        q = q->next;
    }
}