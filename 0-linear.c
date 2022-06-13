#include "sort.h"
/**
 * linear_search - search elements 1 by 1
 * @array: pointer to array
 * @size: is the number of elements in array
 * @value: search item
 *
 * Return: index of value
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
	return (-1);
	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = %d\n", i, array[i]);
		if (array[i] == value)
		return (i);
	}
	return (-1);
}
