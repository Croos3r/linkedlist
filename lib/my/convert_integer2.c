/*
** EPITECH PROJECT, 2021
** MyPrintf
** File description:
** Integer conversion and related stuff second part
*/

char *my_uitoa_base(unsigned int, char *);
char *my_itoa_base(int, char*);

char *my_itoa_octal(unsigned integer)
{
    return my_uitoa_base(integer, "01234567");
}

char *my_itoa_hexadecimal_lower(unsigned int integer)
{
    return my_uitoa_base(integer, "0123456789abcdef");
}

char *my_itoa_hexadecimal_upper(unsigned int integer)
{
    return my_uitoa_base(integer, "0123456789ABCDEF");
}

char *my_itoa(int integer)
{
    return my_itoa_base(integer, "0123456789");
}

char *my_itoa_binary(unsigned int integer)
{
    return my_uitoa_base(integer, "01");
}
