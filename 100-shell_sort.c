#include "sort.h"
/**
 * shell_sort - Sorts an array of integers using the Shell sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Return: Nothing
 * Description: This function sorts an array of integers in ascending order
 */
void shell_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, gap = 1;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		i = gap;
		while (i < size)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap(array, j - gap, j);
				j -= gap;
				print_array(array, size);
			}
			i++;
		}
		gap = (gap - 1) / 3;
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
