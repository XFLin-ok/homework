#include <stdio.h>
#include "singly_link.h"
int main()
{
    mange_node *mange = mange_node_create();
    tail_insert(mange, 10);
    tail_insert(mange, 20);
    tail_insert(mange, 30);

    head_insert(mange, 40);
    head_insert(mange, 50);
    head_insert(mange, 60);

    print_linklist(mange);

    search_node(mange, 30);
    search_node(mange, 40);
    search_node(mange, 60);

    del_node(mange, 20);

    print_linklist(mange);
    del_mindata(mange);
    print_linklist(mange);
    del_mindata(mange);
    print_linklist(mange);

    change_node(mange);
    print_linklist(mange);
}
