#include <unistd.h>

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int is_bit_set = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return;
	}

	while (mask > 0)
	{
		is_bit_set = (n & mask) != 0;

		if (is_bit_set)
			write(1, "1", 1);
		else
			write(1, "0", 1);

		mask >>= 1;
	}
}
