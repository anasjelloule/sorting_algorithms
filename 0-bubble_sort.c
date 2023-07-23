/*
 * File: 0-bubble_sort.c
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
 * bubble_sort - Sort an array_integers in ascending order.
 * @array: array_integers to be done.
 * @size:  size of array.
 *
 * Description: Prints the array after every switch.
 */
void bubble_sort(int *array, size_t size)
{
  size_t cnt, _len = size;
  bool bbly = false;

  if (array == NULL || size < 2)
    return;

  while (bbly == false)
    {
      bbly = true;
      for (cnt = 0; cnt < _len - 1; cnt++)
	{
	  if (array[cnt] > array[cnt + 1])
	    {
	      swtch_ints(array + cnt, array + cnt + 1);
	      print_array(array, size);
	      bbly = false;
	    }
	}
      _len--;
    }
}
