#include "sort.h"
/**
 * quick_sort - Sorts a list of integers in ascending order using the Quick sort
 * algorithm and the Lomuto partition scheme
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Return: Nothing
 * Description: This function sorts an array of integers in ascending order
 * using the Quick sort algorithm 
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1);
}
/**
 * quick_sort_rec - Sorts a list of integers in ascending
 * 
 * @array: pointer to array
 * @start: start
 * @end: end
 */
void quick_sort_rec(int *array, int start, int end)
{
	int pivot, i, j;

	if (start >= end)
		return;

	pivot = array[end];
	i = start;
	j = end - 1;

	while (i <= j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot && j >= 0)
			j--;
		if (i <= j)
		{
			swap(&array[i], &array[j]);
			print_array(array, end + 1);
			i++;
			j--;

		}
	}
	swap(&array[i], &array[end]);
	print_array(array, end + 1);
	swap(&array[i], &array[end]);
	print_array(array, end + 1);
	quick_sort_rec(array, start, i - 1);
	swap(&array[i], &array[end]);
	print_array(array, end + 1);
	quick_sort_rec(array, i + 1, end);
	swap(&array[i], &array[end]);
	print_array(array, end + 1);
}

/**
 * @swap - swap vars
 * 
 * @a: index pointer
 * @b: index pointer 
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

