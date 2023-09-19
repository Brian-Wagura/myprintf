#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNSPECIFIED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - Struct op
 *
 * @format: The format.
 * @fn: The function associated.
 */
struct format
{
        char format;
        int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct format fmt_t - Struct op
 *
 * @format: The format.
 * @fm_t: The function associated.
 */
typedef struct format fmt_t;

int _printf(const char *format, ...);
int printing(const char *format, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* Prints numbers */
int print_int(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_hexa_caps(va_list types, char buffer[],
        int flags, int width, int precision, int size);

int print_hex(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_unprintable(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int handle_flags(const char *format, int *x);
int handle_width(const char *format, int *x, va_list list);
int handle_precision(const char *format, int *x, va_list list);
int handle_size(const char *format, int *x);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
        int flags, int width, int precision, int size);


/* Writing */
int writing_char(char c, char buffer[],
        int flags, int width, int precision, int size);
int write_number(int is_negative, int ind, char buffer[],
        int flags, int width, int precision, int size);
int write_num(int ind, char buffer[],
        int flags, int width, int prec,
        int length, char padd, char extra_c)
int write_unsigned(int is_negative, int ind,
        char buffer[],
        int flags, int width, int precision, int size);
int write_pointer(char buffer[], int index, int length,
        int width, int flags, char padding, char extra_c, int padding_start);


/* Utilities */
int is_printable(char c);
int append_hexa_code(char ascii_code, char buffer[], int x);
int is_digit(char c);
long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);


#endif
