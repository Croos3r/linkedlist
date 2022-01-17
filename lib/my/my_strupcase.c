/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyStrupcase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }

    return str;
}
