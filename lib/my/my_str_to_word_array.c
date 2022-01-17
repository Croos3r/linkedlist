/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyStrToWordArray
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);

int is_char_alphanumeric(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int count_words(char const *str)
{
    int counter = 0;
    char last_char = 'a';

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_char_alphanumeric(last_char))
            counter += !is_char_alphanumeric(str[i]);
        last_char = str[i];
    }

    return ++counter;
}

char **my_str_to_word_array(char const *str)
{
    char **rslt = malloc(sizeof(char) * my_strlen(str) - count_words(str) - 1);
    char *temp = malloc(sizeof(char) * 200);
    char *to_add = malloc(sizeof(char));
    int i = 0;

    for (int j = 0; j <= my_strlen(str); j++) {
        if (!is_char_alphanumeric(str[j]) && my_strlen(temp) > 0) {
            rslt[i++] = temp;
            temp = malloc(sizeof(char) * 200);
            continue;
        }
        if (is_char_alphanumeric(str[j])) {
            to_add[0] = str[j];
            my_strcat(temp, to_add);
        }
    }
    return rslt;
}
