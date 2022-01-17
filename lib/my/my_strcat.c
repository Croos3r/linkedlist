/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyStrcat
*/

int my_strlen(char *str);

char *my_strcat(char *dest, char const *src)
{
    int length = my_strlen(dest);
    int i = 0;

    for (i; src[i] != '\0'; i++) {
        dest[length + i] = src[i];
    }

    dest[length + i] = '\0';

    return dest;
}
