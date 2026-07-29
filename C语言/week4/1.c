#include <stdio.h>
#include <stdlib.h>
struct node
{
    int a;
    struct node *next;
};

int main()
{
    struct node *p1 = (struct node *)malloc(sizeof(struct node));
    struct node *p2 = (struct node *)malloc(sizeof(struct node));
    struct node *p3 = (struct node *)malloc(sizeof(struct node));
    struct node *p4 = (struct node *)malloc(sizeof(struct node));
    struct node *p5 = (struct node *)malloc(sizeof(struct node));
    p1->a = 10;
    p2->a = 20;
    p3->a = 30;
    p4->a = 40;
    p5->a = 50;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    printf("p1->next: %p\n", p1->next);
    printf("p2: %p\n", p2);
    printf(" *(p1->next): %d\n", (p1->next)->a);
    struct node *p = p1;
    while (p != NULL)
    {
        printf("%p=%d\n", p, p->a);
        p = p->next;
    }
}