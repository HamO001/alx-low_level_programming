#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to retrieve the bit from.
 * @index: The index of the bit to retrieve.
 *
 * Return: The value of the bit at the given index, or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);  /* Invalid index */

	mask <<= index;

	if (n & mask)
		return (1);   /* Bit is set (1) */
	else
		return (0);   /* Bit is not set (0) */
}
