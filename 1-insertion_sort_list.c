[200~#include <stdio.h>
#include <stdlib.h>

/**
 *  * struct listint_s - Doubly linked list node
 *   *
 *    * @n: Integer stored in the node
 *     * @prev: Pointer to the previous element of the list
 *      * @next: Pointer to the next element of the list
 *       */
typedef struct listint_s
{
	    int n;
	        struct listint_s *prev;
		    struct listint_s *next;
} listint_t;

/**
 *  * insertion_sort_list - Sorts a doubly linked list of integers in
 *   * ascending order using the Insertion sort algorithm.
 *    *
 *     * @list: Pointer to the head of the doubly linked list to be sorted
 *      */
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

