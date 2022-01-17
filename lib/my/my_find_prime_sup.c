/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyFindPrimeSup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    for (int i = nb; i < 2147483647; i++) {
        if (my_is_prime(i))
            return (i);
    }
    return (0);
}
