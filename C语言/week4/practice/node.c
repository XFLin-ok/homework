#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void show_node(struct node *head)
{
    struct node *p = head->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
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
void insert_top_node(struct node *head, struct node *xnew)
{
    xnew->next = head->next;
    head->next = xnew;
}

void jiudi_node(struct node *head)
{
    struct node *p = head;

    while (p->next != NULL)
    {
        struct node *p1 = head;
        struct node *q = head->next;
        while (q->next != NULL)
        {
            p1 = q;
            q = q->next;
        }

        p1->next = NULL;
        p->next = q;
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
    show_node(head);
    jiudi_node(head);
    show_node(head);
}
