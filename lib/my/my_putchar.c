/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyPutchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
