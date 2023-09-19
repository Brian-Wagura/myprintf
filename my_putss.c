#include "main.h"

/**
 * my_putss - print string
 * @c: string
 *
 * Return: number of bytes
 */

int my_putss(char *c)
{
	int count = 0;

	if (c)
	{
		for (count = 0; c[count] != '\0'; count++)
		{
			my_putchr(c[count]);
		}
	}
	return (count);
}
