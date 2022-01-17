/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyComputePowerRec
*/

int my_compute_power_rec(int nb, int p)
{
    int computed_power;

    if (p == 0)
        return (1);

    if (p < 0)
        return (0);

    computed_power = my_compute_power_rec(nb, --p);

    if ((long) nb * computed_power > 2147483647)
        return (0);

    nb *= computed_power;

    return (nb);
}
