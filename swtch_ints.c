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
