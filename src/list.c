/*
** EPITECH PROJECT, 2021
** libLinkedList
** File description:
** List management
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

list_t *create_list(void *value)
{
    list_t *list = malloc(sizeof(list_t));

    list->next = NULL;
    list->value = value;

    return list;
}

void add_element(list_t **list, void *value)
{
    list_t *current = *list;

    if (current == NULL) {
        *list = create_list(value);
        return;
    }

    while (current->next != NULL)
        current = current->next;

    current->next = create_list(value);
}

void push_element(list_t **list, void *value)
{
    list_t *new_list;

    if (*list == NULL) {
        *list = create_list(value);
        return;
    }

    new_list = create_list(value);
    new_list->next = *list;
    *list = new_list;
}

void *remove_first_element(list_t **list, void (* free_value)(void *))
{
    list_t *old_head = *list;
    void *result;

    if (*list == NULL)
        return NULL;

    result = (*list)->value;
    *list = (*list)->next;
    old_head->next = NULL;
    free_list(&old_head, free_value);

    return result;
}

void *remove_last_element(list_t **list)
{
    list_t *current = *list;
    void *result;

    if (current == NULL)
        return NULL;
    if (current->next == NULL) {
        result = current->value;
        *list = NULL;
        return result;
    }
    while (current->next->next != NULL)
        current = current->next;
    result = current->next->value;
    current->next = NULL;
    return result;
}
