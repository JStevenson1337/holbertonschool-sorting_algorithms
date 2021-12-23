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
		printf("1\n");
		if (current->n > next->n)
		{
			printf("2\n");
			if (current->prev)
			{
				printf("3\n");
				current->prev->next = next;
				next->prev = current->prev;
				print_list(*list);
				
			}
			else
			{
				printf("4\n");
				*list = next;
				next->prev = NULL;
				print_list(*list);
			}
			prev = next->prev;
			print_list(*list);
			while (prev && prev->n > next->n)
			{
				printf("5\n");
				next->prev = prev->prev;
				prev->next = next->next;
				if (next->next)
					next->next->prev = prev;
				prev->prev = next;
				next->next = prev;
				prev = next->prev;
				print_list(*list);
			}
			printf("6\n");
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
			printf("7\n");
			current = next;
			next = current->next;
			print_list(*list);
		}
	}
}
