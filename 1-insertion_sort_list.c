#include "sort.h"

/**
 * swap_nodes - Swaps doubly-linked list listint_t nodes.
 * @h: pointer to doubly-linked list head.
 * @n1: pointer to first node to be swapped.
 * @n2: second node to be swapped.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;

	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;

	else
		*h = n2;

	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts integer doubly linked list
 * with insertion sort algorithm.
 * @list: pointer to doubly-linked list of integers head.
 *
 * Description: Prints list after every swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;

		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
