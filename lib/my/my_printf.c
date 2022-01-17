/*
** EPITECH PROJECT, 2021
** MyPrintf
** File description:
** Entrypoint of the project
*/

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include "my.h"

char *convert_int_for_flag(int, char);

bool find_and_print_value(const char *format, int *i, va_list ap)
{
    char flag = format[++(*i)];
    char *converted;

    switch (flag) {
        case '%':
            my_putchar('%');
            return true;
        case 's':
            my_putstr(va_arg(ap, char *));
            return true;
        case 'c':
            my_putchar(va_arg(ap, int));
            return true;
        default:
            break;
    }
    converted = convert_int_for_flag(va_arg(ap, int), flag);
    if (converted != NULL)
        my_putstr(converted);
    return converted != NULL;
}

int my_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; ++i) {
        if (format[i] != '%') {
            my_putchar(format[i]);
            continue;
        }
        if (!find_and_print_value(format, &i, ap))
            return -1;
    }
    va_end(ap);
    return 0;
}
