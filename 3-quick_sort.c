/*
 * Auth: Anas Jelloul
 */

#include "sort.h"

void swtch_ints(int *a, int *b);
int lmto_partitions(int *array, size_t size, int left, int right);
void lmto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swtch_ints - Switch two integers.
 * @a: 1_integer to switch.
 * @b: 2_integer to switch.
 */
void swtch_ints(int *a, int *b)
{
int _temp;

_temp = *a;
*a = *b;
*b = _temp;
}

/**
 * lmto_partitions - partitions the array
 * @array: to be Done.
 * @size: size_array.
 * @left: start_array.
 * @right: ending_array.
 *
 * Return: partition index.
 */
int lmto_partitions(int *array, size_t size, int left, int right)
{
	int *pvt, abv, end;

	pvt = array + right;
	for (abv = end = left; end < right; end++)
	{
		if (array[end] < *pvt)
		{
			if (abv < end)
			{
				swtch_ints(array + end, array + abv);
				print_array(array, size);
			}
			abv++;
		}
	}

	if (array[abv] > *pvt)
	{
		swtch_ints(array + abv, pvt);
		print_array(array, size);
	}

	return (abv);
}

/**
 * lmto_sort -  quicksort_algorithm through recursion.
 * @array: to be Done
 * @size: size_array.
 * @left: starting index_array partition.
 * @right: ending index_array partition.
 *
 */
void lmto_sort(int *array, size_t size, int left, int right)
{
	int prt;

	if (right - left > 0)
	{
		prt = lmto_partitions(array, size, left, right);
		lmto_sort(array, size, left, prt - 1);
		lmto_sort(array, size, prt + 1, right);
	}
}

/**
 * quick_sort -  quick sorts an array
 * @array:  array to be Done.
 * @size: size_array.
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lmto_sort(array, size, 0, size - 1);
}
