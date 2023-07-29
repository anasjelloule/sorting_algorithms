/*
 * File: 103-merge_sort.c
 * Auth: Anas Jelloul
 */

#include "sort.h"

void mrg_sub_arr(int *sub_arr, int *buff, size_t front, size_t _md,
		size_t back);
void mrg_sort_recursive(int *sub_arr, int *bff, size_t front, size_t back);
void mrg_sort(int *array, size_t size);

/**
 * mrg_sub_arr - Sort a subarray of integers.
 * @sub_arr: A subarray of an array of integers to sort.
 * @bff: buffered sorted subarray.
 * @front: front index_array.
 * @_md: middle index_array.
 * @back: back index_array.
 */
void mrg_sub_arr(int *sub_arr, int *bff, size_t front, size_t _md,
		size_t back)
{
	size_t i, T, P = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_arr + front, _md - front);

	printf("[right]: ");
	print_array(sub_arr + _md, back - _md);

	for (i = front, T = _md; i < _md && T < back; P++)
		bff[P] = (sub_arr[i] < sub_arr[T]) ? sub_arr[i++] : sub_arr[T++];
	for (; i < _md; i++)
		bff[P++] = sub_arr[i];
	for (; T < back; T++)
		bff[P++] = sub_arr[T];
	for (i = front, P = 0; i < back; i++)
		sub_arr[i] = bff[P++];

	printf("[Done]: ");
	print_array(sub_arr + front, back - front);
}

/**
 * mrg_sort_recursive - Implement the merge sort algorithm through recursion.
 * @sub_arr: subarray of an array to sort.
 * @bff: A buffer store the sorted result.
 * @front: The front index_subarray.
 * @back: The back index_subarray.
 */
void mrg_sort_recursive(int *sub_arr, int *bff, size_t front, size_t back)
{
	size_t _md;

	if (back - front > 1)
	{
		_md = front + (back - front) / 2;
		mrg_sort_recursive(sub_arr, bff, front, _md);
		mrg_sort_recursive(sub_arr, bff, _md, back);
		mrg_sub_arr(sub_arr, bff, front, _md, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements  top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *bff;

	if (array == NULL || size < 2)
		return;

	bff = malloc(sizeof(int) * size);
	if (bff == NULL)
		return;

	mrg_sort_recursive(array, bff, 0, size);

	free(bff);
}
