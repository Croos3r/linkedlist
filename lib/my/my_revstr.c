/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyRevstr
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return i;
}

char *my_revstr(char *str)
{
    int str_length = my_strlen(str);
    char cache;

    for (int i = 0; i < str_length / 2; i++) {
        cache = str[i];
        str[i] = str[str_length - 1 - i];
        str[str_length - 1 - i] = cache;
    }

    return str;
}
