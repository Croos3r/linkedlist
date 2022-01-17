/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** MySwap
*/

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
