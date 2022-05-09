#include "sort.h"

void merge(int *array, int start, int mid, int end, int *temp)
{
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = array[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        temp[k] = array[j];
        j++;
        k++;
    }
    for (i = start; i <= end; i++)
    {
        array[i] = temp[i - start];
    }
}

void merge_sort(int *array, size_t size)
{
    int *temp = malloc(sizeof(int) * size);
    int start, end;
    if (size < 2)
    {
        return;
    }
    start = 0;
    end = size - 1;
    while (start < end)
    {
        merge(array, start, (start + end) / 2, end, temp);
        start = (start + end) / 2 + 1;
        end = end - 1;
    }
    free(temp);
}


