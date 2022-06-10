#include "sort.h"


/**
 * init_arr_len - resets arr_len values to 0
 * @arr_len: array containing amounts of members for arrays in `arrays`
 */
void init_arr_len(int *arr_len)
{
	int i;

	for (i = 0; i < 10; i++)
		arr_len[i] = 0;

	return;
}

/**
 * build_arr - allocates space for arrays to be held in `arrays`
 * @array_of_arrays: array of arrays each containing sorted members of `array`
 * @arr_len: array containing amounts of members for arrays in `arrays`
 */
void build_arr(int *arr_len, int **arrays)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		if (arr_len[i] > 0)
		{
			arrays[i] = malloc(sizeof(int) * arr_len[i]);
			if (!arrays[i])
			{
				for (j = 0; j < i; j++)
					free(arrays[j]);
				free(arrays);
				exit(EXIT_FAILURE);
			}
		}
	}

	return;
}

/**
 * arr_high - Sorts an array of integers in ascending order
 * @array: array
 * @size: size of array
 * Return: Maximum integer
 */
int arr_high(int *array, size_t size)
{
	int i, high;

	high = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > high)
			high = array[i];
	}

	return (high);
}

/**
 * into_array - puts members of `array` into `arrays`
 * @array: array of values to be printed
 * @size: number of elements in array
 * @arrays: array of arrays each containing sorted members of `array`
 * @arr_len: array containing amounts of members for arrays in `arrays`
 */
void into_array(int *array, size_t size, int **arrays, int *arr_len)
{
	int i, j, k, digit;

	for (i = 0; i < (int)size; i++)
	{
		digit = array[i] / 10;
		j = 0;
		while (digit > 0)
		{
			digit /= 10;
			j++;
		}
		arr_len[j]++;
	}

	for (k = 0; k < 10; k++)
	{
		if (arr_len[k] > 0)
		{
			printf("%d: ", k);
			print_array(arrays[k], arr_len[k]);
			free(arrays[k]);
		}
	}

	return;
}

/**
	radix_sort - sort arrays
 * @array: first array
 * @size: number of elements in array
 */
void radix_sort(int *array, size_t size)
{
	int *temp, *arr_len, **arrays;
	int i, high;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		exit(EXIT_FAILURE);

	arr_len = malloc(sizeof(int) * 10);
	if (!arr_len)
		exit(EXIT_FAILURE);

	arrays = malloc(sizeof(int *) * 10);
	if (!arrays)
		exit(EXIT_FAILURE);

	init_arr_len(arr_len);
	build_arr(arr_len, arrays);

	high = arr_high(array, size);
	for (i = 1; i <= high; i *= 10)
	{
		into_array(array, size, arrays, arr_len);
		for (i = 0; i < 10; i++)
			arr_len[i] = 0;
	}

	free(temp);
	free(arr_len);
	free(arrays);

	return;
}
