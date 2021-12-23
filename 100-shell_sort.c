#include "sort.h"
/**
 * shell_sort - Sorts an array of integers using the Shell sort algorithm and knuth shuffle
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Return: Nothing
 * Description: This function sorts an array of integers in ascending order
 */
void shell_sort(int *array, size_t size)
{
	unsigned int i, j, k, temp;
	int gap = 1
			, temp_gap = 0;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		

	}
}
