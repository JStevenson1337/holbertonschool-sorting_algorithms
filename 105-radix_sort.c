#include "sort.h"

/**
 * max_int - find the max int in an array
 * @arr: array of ints
 * @n: size of arrays
 *
 * Return: max int in array
 */
int max_int(int arr[], int n)
{
	int i;
	int max = arr[0];

	for (i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}

/**
 * radix_sort - Sorting using place values from least significant digit
 * @arr: The array to sort
 * @n: the number of digits of the array (to sort on the left side)
 * Return: void
*/

void radix_sort(int arr[], int n)
{
	int digits = 0, i, j, maximum, num, power;
	int count[10];
	int *new_array;

	if (arr == NULL || n < 2)
		return;
	maximum = max_int(arr, n);
	while (maximum > 0)
	{
		digits++;
		maximum /= 10;
	}
	new_array = malloc(sizeof(int) * n);
	if (new_array == NULL)
		return;
	for (i = 0; i < 10; i++)
		count[i] = 0;
	for (i = 0; i < n; i++)
	{
		num = arr[i];
		power = 1;
		for (j = 0; j < digits; j++)
		{
			count[num / power % 10]++;
			power *= 10;
		}
	}
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		num = arr[i];
		power = 1;
		for (j = 0; j < digits; j++)
		{
			new_array[count[num / power % 10] - 1] = num;
			count[num / power % 10]--;
			power *= 10;
		}
	}
	for (i = 0; i < n; i++)
		arr[i] = new_array[i];
	free(new_array);
}
