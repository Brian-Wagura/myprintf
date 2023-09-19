#include "main.h"
#include <stdarg.h>

/**
 * my_putnum - Prints an integer
 * @num: integer
 * @flags: flag structure
 *
 * Return: number of characters printed
 */

int my_putnum(int num, flags_t flags)
{
	char buffer[sizeof(int) * 3 + 1];
	int i = 0, digit, count = 0;
	int is_negative = 0; // Flag to track whether the number is negative

	// Handle negative numbers
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	// Handle the '+' flag
	if (flags.plus && !is_negative)
	{
		my_putchr('+');
		count++;
	}
	// Handle the ' ' flag
	else if (flags.space && !is_negative)
	{
		my_putchr(' ');
		count++;
	}
	// Handle negative numbers with the correct sign
	if (is_negative)
	{
		my_putchr('-');
		count++;
	}

	if (num == 0)
	{
		my_putchr('0');
		count++;
	}
	else
	{
		while (num > 0)
		{
			digit = num % 10;
			buffer[i++] = digit + '0';
			num /= 10;
			count++;
		}
		for (i--; i >= 0; i--)
		{
			my_putchr(buffer[i]);
		}
	}

	return count;
}
