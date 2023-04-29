#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;

	while (curr != NULL)
	{
		tmp = curr->prev;
		while (tmp != NULL && tmp->n > curr->n)
		{
			tmp->next = curr->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp;
			curr->next = tmp;
			curr->prev = tmp->prev;
			if (tmp->prev != NULL)
				tmp->prev->next = curr;
			tmp->prev = curr;
			tmp = curr->prev;
			if (tmp == NULL)
				*list = curr;
			print_list(*list);
		}
		curr = curr->next;
	}
}
