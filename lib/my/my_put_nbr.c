/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MyPutNbr
*/

void my_putchar(char c);
int power(int number, int power);

void print_digit(int n)
{
    if (n < 0)
        n *= -1;
    my_putchar(48 + n);
}

int get_digits(int n)
{
    int cache = n / 10;
    int i = 1;

    if (n < 0) {
        while (cache < 0) {
            cache = cache / 10;
            i++;
        }
    } else {
        while (cache > 0) {
            cache = cache / 10;
            i++;
        }
    }

    return (i);
}

int my_put_nbr(int n)
{
    int digits;

    if (n < 0) {
        my_putchar('-');
        n *= -1;
    }

    digits = get_digits(n) - 1;

    while (digits >= 0) {

        print_digit(n / power(10, digits));
        n %= power(10, digits);
        digits--;
    }

    return (0);
}
