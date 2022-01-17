/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyStrncmp
*/

int strnsum(char const *str, int n)
{
    int sum = 0;

    for (int i = 0; str[i] != '\0' && i < n; i++) {
        sum += str[i];
    }

    return sum;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int sum1 = strnsum(s1, n);
    int sum2 = strnsum(s2, n);

    if (n <= 0)
        return 0;

    if (sum1 == sum2)
        return 0;
    if (sum1 > sum2)
        return 1;

    return -1;
}
