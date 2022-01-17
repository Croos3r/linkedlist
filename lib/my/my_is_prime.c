/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyIsPrime
*/

int my_is_prime(int nb)
{
    if ((nb == 0) || (nb == 1) || (nb != 2 && nb % 2 == 0) || (nb < 0))
        return (0);
    for (int i = 3; i < nb; i += 2) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}
