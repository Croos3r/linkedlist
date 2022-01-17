/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** Header file
*/

#ifndef MY_H
    #define MY_H

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char **my_str_to_word_array(char const *str);
int my_show_word_array(char * const *tab);
int get_digit(char digit);
int is_digit(char c);
int sign_nbr(int to_sign, int negative);
int calc_unsigned_nbr(char const *str, int char_count, int dig_start, int neg);
void increment_if_digit(int *iterator, char const *str);
void increment_if_not_digit(int *iterator, char const *str);
int get_digits(int n);
void print_digit(int n);
int strsum(char const *str);
int strnsum(char const *str, int n);
int count_words(char const *str);
int is_char_alphanumeric(char c);
int my_printf(const char *format, ...);

#endif
