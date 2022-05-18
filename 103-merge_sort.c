#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - implementation of merge sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	merge_sort_helper(array, temp, size);
	free(temp);
}

/**
 * merge_sort_helper - helper function for merge sort
 * @array: array of integers
 * @temp: temporary array
 * @size: size of array
 */
void merge_sort_helper(int *array, int *temp, size_t size)
{
	if (size < 2)
		return;
	size_t mid = size / 2;
	merge_sort_helper(array, temp, mid);
	merge_sort_helper(array + mid, temp + mid, size - mid);
	merger(array, mid, array + mid, size - mid, temp);
}

/**
 * merger - merge two sorted arrays
 * @l: left array
 * @size_l: size of left array
 * @r: right array
 * @size_r: size of right array
 * @tmp: temporary array
 */
void merger(int *l, size_t size_l, int *r, size_t size_r, int *tmp)
{
	size_t i = 0, j = 0, k = 0;

	for (i = 0; i < size_l; i++)
		tmp[i] = l[i];

	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, size_l);
	printf("[right]: ");
	print_array(r, size_r);

	for (i = 0; i < size_l && j < size_r; l[k++] = tmp[i], i++)
		for (; j < size_r && r[j] < tmp[i]; j++)
			l[k++] = r[j];

	for (; i < size_l; i++)
		l[k++] = tmp[i];

	for (; j < size_r; j++)
		l[k++] = r[j];

	printf("[Done]: ");
	print_array(l, size_l + size_r);
}
