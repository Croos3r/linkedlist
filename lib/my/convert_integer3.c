/*
** EPITECH PROJECT, 2021
** MyPrintf
** File description:
** Integer conversion and related stuff second part
*/

char *my_uitoa_base(unsigned int, char *);

char *my_uitoa(unsigned integer)
{
    return my_uitoa_base(integer, "0123456789");
}
