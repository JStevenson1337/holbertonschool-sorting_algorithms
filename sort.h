#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stddef.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_list(const listint_t *list);
void print_array(const int *array, size_t size);


void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void sort_helper(int *array, int *temp, size_t size);


void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);



void swap(int *a, int *b);
void quick_sort_rec(int *array, int start, int end);
void swap_list(const listint_t *a, const listint_t *b);
void quick_sort_rec(int *array, int start, int end);

void merge_sort(int *array, size_t size);
void merge_sort_helper(int *array, int *temp, size_t size);
void merger(int *l, size_t size_l, int *r, size_t size_r, int *tmp);

void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t i);
void heap_sort_rec(int *array, size_t size);

int maxIntInArray(int arr[], int n);
int init_arr_len(int *arr_len);
void radix_sort(int arr[], int n);


int linear_search(int *array, size_t size, int value);

#endif
