/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyComputeSquareRoot
*/

int my_compute_square_root(int nb)
{
    int odd = 1;
    int i = 0;

    while (nb != 0) {
        if (nb < 0)
            return (0);
        nb -= odd;
        odd += 2;
        i++;
    }
    return (i);
}
