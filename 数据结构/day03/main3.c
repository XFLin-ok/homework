#include "doubly_link.h"

int main()
{
    mange_node *mange = create_mangenode();
    head_insert(mange, 10);
    head_insert(mange, 20);
    head_insert(mange, 30);

    print_linklist(mange);

    tail_insert(mange, 40);
    tail_insert(mange, 50);
    tail_insert(mange, 60);

    print_linklist(mange);

    select_insert(mange);

    print_linklist(mange);

    del_node(mange, 30);

    print_linklist(mange);

    change_node(mange);

    print_linklist(mange);

    search_node(mange, 10);
}