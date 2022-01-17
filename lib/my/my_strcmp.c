/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyStrcmp
*/

int strsum(char const *str)
{
    int sum = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        sum += str[i];
    }

    return sum;
}

int my_strcmp(char const *s1, char const *s2)
{
    int sum1 = strsum(s1);
    int sum2 = strsum(s2);

    if (sum1 == sum2)
        return 0;
    if (sum1 > sum2)
        return 1;

    return -1;
}
