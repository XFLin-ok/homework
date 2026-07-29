#include "singly_cycle_link.h"

int main()
{

    Mange_t *Pmange = CircularLinkedList_Create();

    CircularLinkedList_Tailinsert(Pmange, 10);
    CircularLinkedList_Tailinsert(Pmange, 20);
    CircularLinkedList_Tailinsert(Pmange, 30);
    CircularLinkedList_Tailinsert(Pmange, 40);
    CircularLinkedList_Tailinsert(Pmange, 50);

    CircularLinkedList_print(Pmange);

    del_node(Pmange, 10);

    CircularLinkedList_print(Pmange);

    search_node(Pmange, 50);

    change_node(Pmange);

    CircularLinkedList_print(Pmange);
}
