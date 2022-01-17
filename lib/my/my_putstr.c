/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyPutstr
*/

#include <unistd.h>

void my_putchar(char c);
int my_strlen(char *str);

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));

    return (0);
}
