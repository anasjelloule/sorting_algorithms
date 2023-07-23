/*
 * File: 100-shell_sort.c
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
 * shell_sort - Sort_array in ascending
 * @array: array_integers.
 * @size: size_array.
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t _gp, cnt, i;

	if (array == NULL || size < 2)
		return;

	for (_gp = 1; _gp < (size / 3);)
		_gp = _gp * 3 + 1;

	for (; _gp >= 1; _gp /= 3)
	{
		for (cnt = _gp; cnt < size; cnt++)
		{
			i = cnt;
			while (i >= _gp && array[i - _gp] > array[i])
			{
				swap_ints(array + i, array + (i - _gp));
				i -= _gp;
			}
		}
		print_array(array, size);
	}
}
