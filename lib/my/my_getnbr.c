/*
** EPITECH PROJECT, 2021
** Day 04
** File description:
** MyGetNbr
*/

int get_digit(char digit);
int is_digit(char c);
int power(int number, int power);
int my_strlen(char const *str);
int sign_nbr(int to_sign, int negative);

int calc_unsigned_nbr(char const *str, int char_count, int dig_start, int neg)
{
    int power_e = 0;
    int result = 0;
    int current_digit;
    long to_add;

    while (char_count > dig_start) {
        current_digit = get_digit(str[char_count - 1]);
        to_add = current_digit * power(10, power_e);
        if (((long) result + to_add > (neg ? 2147483648 : 2147483647)))
            return (0);
        if ((long) result + to_add < 0)
            return (0);
        result += to_add;
        power_e++;
        char_count--;
    }
    return (result);
}

void increment_if_digit(int *iterator, char const *str)
{
    int i = *iterator;

    while (is_digit(str[i])) {
        i++;
    }
    *iterator = i;
}

void increment_if_not_digit(int *iterator, char const *str)
{
    int i = *iterator;
    int length = my_strlen(str);

    while (!is_digit(str[i]) && i < length) {
        i++;
    }
    *iterator = i;
}

char get_last_char_or_placeholder(char const *str, int index, char placeholder)
{
    if (index > 0)
        return str[index - 1];
    else
        return placeholder;
}

int my_getnbr(char const *str)
{
    char last_char;
    int char_count = 0;
    int digits_start = 0;
    int negative = 0;
    int result = 0;

    increment_if_not_digit(&char_count, str);
    last_char = get_last_char_or_placeholder(str, char_count, '+');
    if (last_char == '-')
        negative = 1;
    digits_start = char_count;
    increment_if_digit(&char_count, str);
    if (digits_start == char_count)
        return (0);
    if (char_count - digits_start > 10)
        return (0);
    result = calc_unsigned_nbr(str, char_count, digits_start, negative);
    return (sign_nbr(result, negative));
}
