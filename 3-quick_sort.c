#include "sort.h"
/**
 * quick_sort - Sorts a list of integers in ascending order using the Quick sort
 * algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Return: Nothing
 * Description: This function sorts an array of integers in ascending order
 * using the Quick sort algorithm 
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1);
}

/**
 * quick_sort_rec - Sorts a list of integers in ascending order using the Quick
 * sort algorithm
 * @array: The array to be sorted
 * @start: Index of the first element
 * @end: Index of the last element
 */
void quick_sort_rec(int *array, int start, int end)
{
	int pivot, i, j;

	if (start >= end)
		return;

	pivot = array[start];
	i = start;
	j = end;

	while (i < j)
	{
		while (array[i] <= pivot && i < j)
			i++;
		while (array[j] > pivot)
			j--;
		if (i < j)
			swap(array, i, j);
		print_array(array, end + 1);

	}
	swap(array, start, j);
	print_array(array, end + 1);
	quick_sort_rec(array, start, j - 1);
	quick_sort_rec(array, j + 1, end);
}

/**
 * swap - Swaps two elements in an array
 * array: The array to be sorted
 * i: Index of the first element
 * j: Index of the second element
 * Return: Nothing
 * Description: This function swaps two elements in an array
 */
void swap(int *array, size_t i, size_t j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

