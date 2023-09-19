#include "main.h"
#include <stdarg.h>
#include <stdint.h>

int _printf(const char *format, ...)
{
    unsigned int count = 0;
    va_list args;
    const char *ptr;
    flags_t flags = {0, 0, 0, 0, 0};

    if (!format || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr != '%')
        {
            my_putchr(*ptr);
            count++;
        }
        else
        {
            ptr++;
            while (get_flag(*ptr, &flags))
                ptr++;

            switch (*ptr)
            {
            case 'c':
                count++;
                my_putchr(va_arg(args, int));
                break;
            case 's':
                count += my_putss(va_arg(args, char *));
                break;
            case '%':
                count++;
                my_putchr('%');
                break;
            case 'd':
            case 'i':
                if (flags.plus)
                {
                    count++;
                    my_putchr('+');
                }
                else if (flags.space)
                {
                    count++;
                    my_putchr(' ');
                }
                count += my_putnum(va_arg(args, int), flags);
                break;
            case 'u':
                if (flags.plus)
                {
                    count++;
                    my_putchr('+');
                }
                else if (flags.space)
                {
                    count++;
                    my_putchr(' ');
                }
                count += my_putunsigned(va_arg(args, unsigned int), 10, flags);
                break;
            case 'o':
                if (flags.hash)
                {
                    count++;
                    my_putchr('0');
                }
                count += my_putunsigned(va_arg(args, unsigned int), 8, flags);
                break;
            case 'x':
                if (flags.hash)
                {
                    count++;
                    my_putchr('0');
                    my_putchr('x');
                }
                count += my_putunsigned(va_arg(args, unsigned int), 16, flags);
                break;
            case 'X':
                if (flags.hash)
                {
                    count++;
                    my_putchr('0');
                    my_putchr('X');
                }
                count += my_putunsigned(va_arg(args, unsigned int), 16, flags);
                break;
            case 'S':
            {
                const char *string = va_arg(args, const char *);
                while (*string != '\0')
                {
                    if (*string < 32 || *string >= 127)
                    {
                        my_putchr('\\');
                        my_putchr('x');
                        count += 2;
                        count += my_putunsigned((unsigned char)(*string), 16, flags);
                    }
                    else
                    {
                        my_putchr(*string);
                        count++;
                    }
                    string++;
                }
                break;
            }
            case 'p':
            {
                void *pointer = va_arg(args, void *);
                char buffer[32];
                int j = 0, digit;
                while ((uintptr_t)pointer > 0)
                {
                    digit = (uintptr_t)pointer & 0xF;
                    if (digit >= 10)
                    {
                        digit += 'a' - 10;
                    }
                    else
                    {
                        digit += '0';
                    }
                    buffer[j++] = digit;
                    pointer = (void *)((uintptr_t)pointer >> 4);
                }
                my_putchr('0');
                my_putchr('x');
                count += 2;
                for (j--; j >= 0; j--)
                {
                    count += my_putchr(buffer[j]);
                }
                break;
            }
            default:
                // Handle unsupported conversion type
                break;
            }
        }
    }
    va_end(args);
    return count;
}
