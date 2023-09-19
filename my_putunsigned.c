// #include "main.h"

// /**
//  * my_putunsigned - Print an unsigned int in
//  * a given base
//  * @num: integer
//  * @base: base
//  *
//  * Return: number of chars
//  */

// int my_putunsigned(unsigned int num, int base)
// {
// 	char buffer[32];
// 	int i = 0, digit;

// 	while (num > 0)
// 	{
// 		digit = num % base;
// 		if (digit >= 10)
// 		{
// 			digit += 'A' - 10;
// 		}
// 		else
// 		{
// 			digit += '0';
// 		}
// 		buffer[i++] = digit;
// 		num /= base;
// 	}

// 	for (i--; i >= 0; i--)
// 	{
// 		my_putchr(buffer[i]);
// 	}
// 	return i + 1;
// }
#include "main.h"

/**
 * my_putunsigned - Print an unsigned int in a given base
 * @num: integer
 * @base: base
 * @flags: flag structure
 *
 * Return: number of characters printed
 */

int my_putunsigned(unsigned int num, int base, flags_t flags)
{
	char buffer[32];
	int i = 0, digit, count = 0;

	while (num > 0)
	{
		digit = num % base;
		if (digit >= 10)
		{
			if (flags.length_l || flags.length_h)
			{
				digit += (flags.length_l && !flags.length_h) ? 'A' - 10 : 'a' - 10;
			}
			else
			{
				digit += 'A' - 10;
			}
		}
		else
		{
			digit += '0';
		}
		buffer[i++] = digit;
		num /= base;
		count++;
	}

	if (flags.hash && (base == 8 || base == 16) && num != 0)
	{
		my_putchr('0');
		count++;
		if (base == 16)
		{
			my_putchr((flags.length_l || flags.length_h) ? 'X' : 'x');
			count++;
		}
	}

	for (i--; i >= 0; i--)
	{
		my_putchr(buffer[i]);
	}

	return count;
}
