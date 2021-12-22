#include "sort.h"
/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Return: Nothing
 * Description: This function sorts an array of integers in ascending order 
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;

	if (!array || size < 2)
		return;

	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				swap(array, i, j);
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
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

