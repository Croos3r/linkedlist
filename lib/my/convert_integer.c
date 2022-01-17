/*
** EPITECH PROJECT, 2021
** MyPrintf
** File description:
** Integer conversion and related stuff
*/

#include <stdlib.h>
#include "my.h"
#include "utils.h"

char *my_uitoa(int);
char *my_itoa(int);
char *my_itoa_binary(int);
char *my_itoa_octal(int);
char *my_itoa_hexadecimal_lower(int);
char *my_itoa_hexadecimal_upper(int);

const char INT_CONVERT_FLAGS[] = "udiboxX";
char *(* const INT_CONVERTERS[])(int) = {
        &my_uitoa,
        &my_itoa,
        &my_itoa,
        &my_itoa_binary,
        &my_itoa_octal,
        &my_itoa_hexadecimal_lower,
        &my_itoa_hexadecimal_upper,
};

int int_len_for_base(int integer, char const *base)
{
    int base_len = my_strlen(base);
    int digits = 0;

    while (integer != 0) {
        integer /= base_len;
        digits++;
    }

    return digits;
}

char *my_itoa_base(int integer, char const *base)
{
    int i = 0;
    int cache = ABS(integer);
    int base_len = my_strlen(base);
    int result_len = int_len_for_base(cache, base) + (integer < 0 ? 2 : 1);
    char *result = malloc(sizeof(char) * result_len);

    if (integer == 0)
        return "0";

    while (cache > 0) {
        result[i++] = base[cache % base_len];
        cache /= base_len;
    }

    if (integer < 0)
        result[result_len - 2] = '-';
    result[result_len - 1] = '\0';
    my_revstr(result);
    return result;
}

char *my_uitoa_base(unsigned int integer, char const *base)
{
    int i = 0;
    unsigned int cache = integer;
    int base_len = my_strlen(base);
    int result_len = int_len_for_base(ABS((int) cache), base) + 1;
    char *result = malloc(sizeof(char) * result_len);

    while (cache > 0) {
        result[i++] = base[cache % base_len];
        cache /= base_len;
    }

    result[result_len - 1] = '\0';
    my_revstr(result);
    return result;
}

char *convert_int_for_flag(int integer, char flag)
{
    int flags_number = my_strlen(INT_CONVERT_FLAGS);

    for (int i = 0; i < flags_number; ++i)
        if (INT_CONVERT_FLAGS[i] == flag)
            return INT_CONVERTERS[i](integer);
    return NULL;
}
