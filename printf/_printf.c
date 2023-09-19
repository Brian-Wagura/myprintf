#include "main.h"

void print_buff(char buffer[], int *buff_index);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int x, printed = 0, printed_chars = 0;
        int flags, width, precision, size, buff_index = 0;
        va_list list;
        char buffer[BUFFER_SIZE];

        if (format == NULL)
                return (-1);

        va_start(list, format);

        for (x = 0; format && format[x] != '\0'; x++)
        {
                if (format[x] != '%')
                {
                        buffer[buff_index++] = format[x];
                        if (buff_index == BUFFER_SIZE)
                                print_buffer(buffer, &buff_index);
                        printed_chars++;
                }
		else
                {
                        print_buffer(buffer, &buff_index);
                        flags = handle_flags(format, &x);
                        width = handle_width(format, &x, list);
                        precision = handle_precision(format, &x, list);
                        size = handle_size(format, &x);
                        ++x;
                        printed = printing(format, &x, list, buffer,
                                flags, width, precision, size);
                        if (printed == -1)
                                return (-1);
                        printed_chars += printed;
                }
        }

        print_buffer(buffer, &buff_index);

        va_end(list);

        return (printed_chars);


}

/**
 * print_buff - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_index: Index at which to add next char, represents the length.
 */
void print_buff(char buffer[], int *buff_index)
{
        if (*buff_index > 0)
                write(1, &buffer[0], *buff_index);

        *buff_index = 0;
}
