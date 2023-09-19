#include "main.h"

/**
 * print_unprintable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_unprintable(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        int x = 0, offset = 0;
        char *str = va_arg(types, char *);

        UNSPECIFIED(flags);
	UNSPECIFED(width);
	UNSPECIFED(precision);
	UNSPECIFED(size);

        if (str == NULL)
                return (write(1, "(null)", 6));

        while (str[x] != '\0')
        {
                if (is_printable(str[x]))
                        buffer[x + offset] = str[x];
                else
                        offset += append_hexa_code(str[x], buffer, x + offset);

                x++;
        }

        buffer[x + offset] = '\0';

        return (write(1, buffer, x + offset));
}

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        char extra_c = 0, padding = ' ';
        int index = BUFFER_SIZE - 2, length = 2, padding_start = 1;
        unsigned long num_addrs;
        char map_to[] = "0123456789abcdef";
        void *addrs = va_arg(types, void *);

        UNSPECIFIED(width);
        UNSPECIFIED(size);

        if (addrs == NULL)
                return (write(1, "(nil)", 5));

        buffer[BUFFER_SIZE - 1] = '\0';
        UNSPECIFIED(precision);

        num_addrs = (unsigned long)addrs;

        while (num_addrs > 0)
        {
                buffer[index--] = map_to[num_addrs % 16];
                num_addrs /= 16;
                length++;
        }

        if ((flags & F_ZERO) && !(flags & F_MINUS))
                padding = '0';
        if (flags & F_PLUS)
                extra_c = '+', length++;
        else if (flags & F_SPACE)
                extra_c = ' ', length++;

        index++;

        return (write_pointer(buffer, index, length,
                width, flags, padding, extra_c, padding_start));
}

/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_reverse(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        char *str;
        int x, count = 0;

        UNSPECIFIED(buffer);
        UNSPECIFIED(flags);
        UNSPECIFIED(width);
        UNSPECIFIED(size);

        str = va_arg(types, char *);

        if (str == NULL)
        {
                UNSPECIFIED(precision);

                str = ")Null(";
        }
        for (x = 0; str[x]; x++)
                ;

        for (x = x - 1; x >= 0; x--)
        {
                char z = str[x];

                write(1, &z, 1);
                count++;
        }
        return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        char x;
        char *str;
        unsigned int i, j;
        int count = 0;
        char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

        str = va_arg(types, char *);
        UNSPECIFIED(buffer);
        UNSPECIFIED(flags);
        UNSPECIFIED(width);
        UNSPECIFIED(precision);
        UNSPECIFIED(size);

        if (str == NULL)
                str = "(AHYY)";
        for (i = 0; str[i]; i++)
        {
                for (j = 0; in[j]; j++)
                {
                        if (in[j] == str[i])
                        {
                                x = out[j];
                                write(1, &x, 1);
                                count++;
                                break;
                        }
                }
                if (!in[j])
                {
                        x = str[i];
                        write(1, &x, 1);
                        count++;
                }
        }
        return (count);
}
