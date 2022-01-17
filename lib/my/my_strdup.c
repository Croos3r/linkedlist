/*
** EPITECH PROJECT, 2021
** Day 08
** File description:
** Task 01
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);

    my_strcpy(dest, src);

    return dest;
}
