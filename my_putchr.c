#include <unistd.h>

/**
 * my_putchr - print a character
 * @c: char input
 *
 * Return: 1
 */

int my_putchr(char c)
{
	return (write(1, &c, 1));
}
