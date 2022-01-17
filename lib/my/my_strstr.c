/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyStrstr
*/

char const *my_strstr(char *str, char const *to_find)
{
    int start = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[0])
            start = i;
        if (start == -1)
            continue;
        if (str[i] != to_find[i - start])
            start = -1;
    }
    if (start == -1)
        return ((void *) 0);
    else
        return to_find;
}
