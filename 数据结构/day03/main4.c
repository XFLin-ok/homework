#include "doubly_cycle_link.h"

int main()
{
    mange_node *mange = create_mangenode();

    head_insert(mange, 10);
    head_insert(mange, 20);
    head_insert(mange, 30);

    tail_node(mange, 40);
    tail_node(mange, 50);
    tail_node(mange, 60);

    del_node(mange, 40);

    print_linklist(mange);
    search_node(mange, 60);

    change_node(mange);

    print_linklist(mange);
}