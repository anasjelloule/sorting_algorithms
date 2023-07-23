/*
 * File: 2-selection_sort.c
 * Auth: Anas Jelloul
 */

#include "sort.h"

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
 * selection_sort - Sort an array_integers in ascending order
 *                  using selection_sort_algorithm.
 * @array: array_integers.
 * @size: size of array.
 */
void selection_sort(int *array, size_t size)
{
	int *_min;
	size_t cnt, i;

	if (array == NULL || size < 2)
		return;

	for (cnt = 0; cnt < size - 1; cnt++)
	{
		_min = array + cnt;
		for (i = cnt + 1; i < size; i++)
			_min = (array[i] < *_min) ? (array + i) : _min;

		if ((array + cnt) != _min)
		{
			swtch_ints(array + cnt, _min);
			print_array(array, size);
		}
	}
}
