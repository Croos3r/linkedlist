/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyStrncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int end = -1;

    if (n <= 0)
        return "";

    for (i; i < n; i++) {
        if (src[i] == '\0')
            end = i;
        if (end != -1 && i > end)
            dest[i] = '\0';
        else
            dest[i] = src[i];
    }
    return dest;
}
