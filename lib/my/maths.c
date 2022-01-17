/*
** EPITECH PROJECT, 2021
** Day 04
** File description:
** Maths utils
*/

int power(int number, int power)
{
    int result = 1;

    while (power >= 1) {
        result *= number;
        power--;
    }

    return result;
}

int sign_nbr(int to_sign, int negative)
{
    if (negative)
        return -to_sign;
    else
        return to_sign;
}
