#include "main.h"

int get_flag(char c, flags_t *flags)
{
    int flag_found = 1;
    switch (c)
    {
    case '+':
        flags->plus = 1;
        break;
    case ' ':
        flags->space = 1;
        break;
    case '#':
        flags->hash = 1;
        break;
    case 'l':
        flags->length_l = 1;
        break;
    case 'h':
        flags->length_h = 1;
        break;
    default:
        flag_found = 0;
    }
    return flag_found;
}
