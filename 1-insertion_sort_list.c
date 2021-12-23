#include "sort.h"
/**
 * insertion_sort_list - Sorts a linked list of integers in ascending order
 * @list: The list to be sorted
 * Return: Nothing
 * Description: This function sorts a linked list of integers in ascending order
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
				print_list(*list);
			}
			else
			{
				*list = next;
				next->prev = NULL;
				print_list(*list);
			}
			prev = next->prev;
			print_list(*list);
			while (prev && prev->n > next->n)
			{
				next->prev = prev->prev;
				prev->next = next->next;
				if (next->next)
					next->next->prev = prev;
				prev->prev = next;
				next->next = prev;
				prev = next->prev;
				print_list(*list);
			}
			next->prev = prev;
			print_list(*list);
			if (prev)
				prev->next = next;
			else
				*list = next;
			current = next;
			next = current->next;
			print_list(*list);
		}
		else
		{
			current = next;
			next = current->next;
			print_list(*list);
		}
	}
}
