/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyIsneg
*/

void my_putchar(char c);

int my_isneg(int nb)
{
    if (nb < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return (0);
}
