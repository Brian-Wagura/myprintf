#include "main.h"

/**
 * my_putbin - Prints an int in binary format
 * @number: integer
 *
 * Return: number of characters printed
 */

int my_putbin(unsigned int num)
{
	char buffer[32];
	int i = 0, digit;

	while (num > 0)
	{
		digit = num & 1;
		buffer[i++] = digit + '0';
		num >>= 1;
	}

	for(i--; i>= 0; i--)
	{
		my_putchr(buffer[i]);
	}

	return i + 1;
}
