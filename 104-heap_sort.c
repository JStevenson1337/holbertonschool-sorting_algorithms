#include "sort.h"

/**
 * merge - merge two sorted arrays
 * @array: first array
 * @temp: temporary array
 * @size: size of array
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * merge - merge two sorted arrays
 * @array: first array
 * @temp: temporary array
 * @size: size of array
 */
void sort(int *a, int n)
{
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

/**
 * merge - merge two sorted arrays
 * @array: first array
 * @temp: temporary array
 * @size: size of array
 */
void heapify(int *array, size_t size, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;
	if (right < size && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - sort an array using heap sort
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t n = size;

	for (i = n / 2 - 1; i >= 0; i--)
	{
		heapify(array, n, i);
	}

	for (i = n - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		n--;
		heapify(array, n, 0);
	}
}







