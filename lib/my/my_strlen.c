/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyStrlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return (i);
}
