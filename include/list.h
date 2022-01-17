/*
** EPITECH PROJECT, 2021
** LibLinkedList
** File description:
** Project main header file
*/

#ifndef LIST_H
    #define LIST_H

typedef struct list {
    void *value;
    struct list *next;
} list_t;

list_t *create_list(void *value);
void free_list(list_t **list, void (* free_value)(void *));
void for_each_element(list_t *list, void (* consumer)(size_t, void *));
int length_list(list_t *list);
void add_element(list_t **list, void *value);
void push_element(list_t **list, void *value);
void *remove_first_element(list_t **list, void (* free_value)(void *));
void *remove_last_element(list_t **list);

#endif
