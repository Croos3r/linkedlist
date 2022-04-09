/*
** EPITECH PROJECT, 2021
** LibLinkedList
** File description:
** List management second part
*/

#include <stddef.h>
#include <stdlib.h>
#include "list.h"

void for_each_element(list_t *list, void (* consumer)(size_t, void *))
{
    list_t *current = list;
    size_t i = 0;

    while (current != NULL) {
        consumer(i++, current->value);
        current = current->next;
    }
}

int length_list(list_t *list)
{
    list_t *current = list;
    int i = 0;

    while (current != NULL) {
        current = current->next;
        i++;
    }

    return i;
}

void free_list(list_t **list, void (* free_value)(void *))
{
    list_t *temp;

    while (*list != NULL) {
        temp = *list;
        *list = (*list)->next;
        if (free_value != NULL)
            free_value(temp->value);
        free(temp);
    }

    *list = NULL;
}
