/*
** EPITECH PROJECT, 2021
** Day 04
** File description:
** Digit utils
*/

int get_digit(char digit)
{
    return (digit - 48);
}

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}
