#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *next_node, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        next_node = current->next;

        while (current->prev != NULL && current->n < current->prev->n)
        {
            /* Swap current node with previous node */
            temp = current->prev;
            current->prev = temp->prev;
            temp->next = current->next;
            current->next = temp;

            if (temp->prev != NULL)
                temp->prev->next = current;
            temp->prev = current;

            /* If the swapped node was the head, update the list */
            if (current->prev == NULL)
                *list = current;

            /* Print the list after the swap */
            print_list(*list);
        }

        current = next_node;
    }
}
