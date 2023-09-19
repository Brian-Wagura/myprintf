#ifndef MAIN_H
#define MAIN_H

/*C header files*/
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */

typedef struct flags
{
    int plus;
    int space;
    int hash;
    int length_l;
    int length_h;
} flags_t;

/* Function prototypes*/
int _printf(const char *format, ...);
int my_putchr(char c);
int my_putss(char *c);
int my_putnum(int num, flags_t flags);
int my_putbin(unsigned int num);
int my_putunsigned(unsigned int num, int base, flags_t flags);

int get_flag(char c, flags_t *flags);

#endif /* MAIN_H */
