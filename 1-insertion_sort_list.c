#include "sort.h"
/**
 * insertion_sort_list - Sorts a linked list of integers in ascending order
 * @list: The list to be sorted
 * Return: Nothing 
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;
	listint_t *next;

	if (!list || !(*list))
		return;

	if (!(*list)->next)
		return;

	current = *list;
	next = current->next;

	while (next)
	{
		if (current->n > next->n)
		{
			if (current->prev)
			{
				current->prev->next = next;
				next->prev = current->prev;
			}
			else
			{
				*list = next;
				next->prev = NULL;
			}
			prev = next->prev;
			while (prev && prev->n > next->n)
			{
				next->prev = prev->prev;
				prev->next = next->next;
				if (next->next)
					next->next->prev = prev;
				prev->prev = next;
				next->next = prev;
				prev = next->prev;
			}
			next->prev = prev;
			if (prev)
				prev->next = next;
			else
				*list = next;
			current = next;
			next = current->next;
		}
		else
		{
			current = next;
			next = current->next;
		}
	}
}
