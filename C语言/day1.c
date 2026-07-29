#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create_node(int data)
{
    struct node *p = malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    return p;
}
insert_node(struct node *head, struct node *xnew)
{
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = xnew;
}

int main()
{
}