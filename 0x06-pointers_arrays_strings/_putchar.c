#include "main.h"
#include <unisrd.h>

/**
 * _putchar - write the character to print 
 * @c: The character to print 
 *
 * Return: on success 1.
 * on erro, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
