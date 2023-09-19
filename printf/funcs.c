#include "main.h"

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        char c = va_arg(types, int);

        return (writing_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        int length = 0, x;
        char *str = va_arg(types, char *);

        UNSPECIFIED(buffer);
        UNSPECIFIED(flags);
        UNSPECIFIED(width);
        UNSPECIFIED(precision);
        UNSPECIFIED(size);
        if (str == NULL)
        {
                str = "(null)";
                if (precision >= 6)
                        str = "      ";
        }

        while (str[length] != '\0')
                length++;

        if (precision >= 0 && precision < length)
                length = precision;

        if (width > length)
        {
                if (flags & F_MINUS)
                {
                        write(1, &str[0], length);
                        for (x = width - length; x > 0; x--)
                                write(1, " ", 1);
                        return (width);
                }
		else
                {
                        for (x = width - length; x > 0; x--)
                                write(1, " ", 1);
                        write(1, &str[0], length);
                        return (width);
                }
        }
        return (write(1, str, length));
}


/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        UNSPECIFIED(types);
        UNSPECIFIED(buffer);
        UNSPECIFIED(flags);
	UNSPECIFED(width);
	UNSPECIFED(precision);
	UNSPECIFED(size);
        return (write(1, "%%", 1));
}

/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        int x = BUFFER_SIZE - 2;
        int is_negative = 0;
        long int n = va_arg(types, long int);
        unsigned long int num;

        n = convert_size_number(n, size);

        if (n == 0)
                buffer[x--] = '0';

        buffer[BUFFER_SIZE - 1] = '\0';
        num = (unsigned long int)n;

        if (n < 0)
        {
                num = (unsigned long int)((-1) * n);
                is_negative = 1;
        }

        while (num > 0)
        {
                buffer[x--] = (num % 10) + '0';
                num /= 10;
        }

        x++;

        return (write_number(is_negative, x, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        unsigned int n, m, x, sum;
        unsigned int a[32];
        int count;

        UNSPECIFIED(buffer);
        UNSPECIFIED(flags);
        UNSPECIFIED(width);
        UNSPECIFIED(precision);
        UNSPECIFIED(size);

        n = va_arg(types, unsigned int);
        m = 2147483648; /* (2 ^ 31) */
        a[0] = n / m;
        for (x = 1; x < 32; x++)
        {
                m /= 2;
                a[x] = (n / m) % 2;
        }
        for (x = 0, sum = 0, count = 0; x < 32; x++)
        {
                sum += a[x];
                if (sum || x == 31)
                {
                        char z = '0' + a[x];

                        write(1, &z, 1);
                        count++;
                }
        }
        return (count);
}

