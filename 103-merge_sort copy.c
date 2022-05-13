#include "sort.h"
/**
 * merge - merge two sorted arrays
 * @array: first array
 * @temp: temporary array
 * @size: size of array
 */
void merge(int *array, int *temp, size_t size)
{
	size_t i = 0, j = 0, k = 0;

	while (i < size / 2 && j < size - size / 2)
	{
		if (array[i] < array[size / 2 + j])
		{
			temp[k] = array[i];
			printf("Merging...\n");
			printf("[left]: ");
			print_array(array, size);
			printf("[right]: ");
			print_array(array + size / 2, size - size / 2);
			i++;
		}
		else
		{
			temp[k] = array[size / 2 + j];
			j++;
		}
		k++;
	}
	while (i < size / 2)
	{
		temp[k] = array[i];
		i++;
		k++;
	}
	while (j < size - size / 2)
	{
		temp[k] = array[size / 2 + j];
		j++;
		k++;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * sort_helper - merge two sorted arrays
 * @array: first array
 * @size: size of array
 * @temp: temporary array
 */
void sort_helper(int *array, int *temp, size_t size)
{
	if (size < 2)
		return;
	size_t mid = size / 2;

	sort_helper(array, temp, mid);
	sort_helper(array + mid, temp + mid, size - mid);
	merge(array, temp, size);
}

/**
 * merge_sort - merge two sorted arrays
 * @array: first array
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *temp = malloc(sizeof(int) * size);

	if (temp == NULL)
		return;
	sort_helper(array, temp, size);
	free(temp);
}
