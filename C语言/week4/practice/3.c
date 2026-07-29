#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create_node(int cdata)
{
    struct node *xnew = (struct node *)malloc(sizeof(struct node));
    xnew->data = cdata;
    xnew->next = NULL;
    return xnew;
}
void insert_top_node(struct node *head, struct node *xnew)
{
    xnew->next = head->next;
    head->next = xnew;
}
void insert_node(struct node *head, struct node *xnew)
{
    struct node *p = head->next;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = xnew;
}
struct node *change_list(struct node *head, struct node *newhead)

{
    struct node *p = head;
    struct node *q = head->next;
    while (p->next != NULL)
    {
        p->next = q->next;
        q->next = NULL;
        insert_top_node(newhead, q);
        }
    return newhead;
}
void show_node(struct node *head)
{
    struct node *p = head->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    insert_top_node(head, create_node(10));
    insert_top_node(head, create_node(20));
    insert_top_node(head, create_node(30));
    insert_top_node(head, create_node(40));
    insert_top_node(head, create_node(50));
    insert_top_node(head, create_node(60));
    show_node(head);
    insert_node(head, create_node(20));
    insert_node(head, create_node(30));
    insert_node(head, create_node(40));
    insert_node(head, create_node(50));
    insert_node(head, create_node(60));
    show_node(head);
    struct node *newhead = malloc(sizeof(struct node));
    newhead->next = NULL;
    change_list(head, newhead);
    show_node(newhead);
}