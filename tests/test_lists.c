#include <criterion/criterion.h>
#include <stdio.h>
#include "list.h"

Test(list_creation, simple)
{
    list_t *list = create_list(5);

    cr_expect_eq(list->value, 5);
    cr_expect_null(list->next);
}

Test(list_creation, null_value)
{
    list_t *list = create_list(NULL);

    cr_expect_null(list->value);
    cr_expect_null(list->next);
}

Test(list_mutation_add, simple)
{
    list_t *list = create_list("Hello");

    add_element(&list, "World!");

    cr_expect_str_eq(list->value, "Hello");
    cr_assert_not_null(list->next);
    cr_expect_str_eq(list->next->value, "World!");
    cr_expect_null(list->next->next);
}

Test(list_mutation_add, empty)
{
    list_t *list = NULL;

    add_element(&list, "Prout");

    cr_expect_str_eq(list->value, "Prout");
    cr_expect_null(list->next);
}

Test(list_mutation_add, big)
{
    size_t max = 9000;
    list_t *list = NULL;

    for (size_t i = 0; i <= max; ++i)
        add_element(&list, i);
    for (size_t i = 0; i <= max; ++i) {
        cr_expect_eq(list->value, i);
        if (i == max)
            cr_assert_null(list->next);
        else
            cr_assert_not_null(list->next, "%d\n", i);
        list = list->next;
    }
}

Test(list_mutation_push, simple)
{
    list_t *list = create_list("World!");

    push_element(&list, "Hello");

    cr_expect_str_eq(list->value, "Hello");
    cr_assert_not_null(list->next);
    cr_expect_str_eq(list->next->value, "World!");
    cr_expect_null(list->next->next);
}

Test(list_mutation_push, empty)
{
    list_t *list = NULL;

    push_element(&list, "Prout");

    cr_expect_str_eq(list->value, "Prout");
    cr_expect_null(list->next);
}

Test(list_mutation_push, big)
{
    size_t max = 9000;
    list_t *list = NULL;

    for (size_t i = 0; i <= max; ++i)
        push_element(&list, i);
    for (int i = max; i >= 0; --i) {
        cr_expect_eq(list->value, i);
        if (i == 0)
            cr_assert_null(list->next);
        else
            cr_assert_not_null(list->next);
        list = list->next;
    }
}

Test(list_mutation_remove_first, simple)
{
    list_t *list = create_list("Prout");

    cr_expect_str_eq(remove_first_element(&list, NULL), "Prout");
    cr_expect_null(list);
}

Test(list_mutation_remove_first, empty)
{
    list_t *list = NULL;

    cr_expect_null(remove_first_element(&list, NULL));
}

Test(list_mutation_remove_first, two_elements)
{
    list_t *list = create_list("Hello");

    add_element(&list, "World");
    cr_expect_str_eq(remove_first_element(&list, NULL), "Hello");
    cr_expect_str_eq(list->value, "World");
    cr_expect_null(list->next);
}

Test(list_mutation_remove_first, big)
{
    size_t max = 9000;
    list_t *list = NULL;

    for (size_t i = 0; i <= max; ++i)
        add_element(&list, i);
    for (size_t i = 0; i <= max ; ++i)
        cr_expect_eq(remove_first_element(&list, NULL), i);
}

Test(list_mutation_remove_last, simple)
{
    list_t *list = create_list("Prout");

    cr_expect_str_eq(remove_last_element(&list), "Prout");
    cr_expect_null(list);
}

Test(list_mutation_remove_last, two_elements)
{
    list_t *list = create_list("Hello");

    add_element(&list, "World");
    cr_expect_str_eq(remove_last_element(&list), "World");
    cr_expect_str_eq(list->value, "Hello");
    cr_expect_null(list->next);
}

Test(list_mutation_remove_last, empty)
{
    list_t *list = NULL;

    cr_expect_null(remove_last_element(&list));
}

Test(list_mutation_remove_last, big)
{
    size_t max = 9000;
    list_t *list = NULL;
    void *value;

    for (size_t i = 0; i <= max; ++i)
        add_element(&list, i);
    for (int i = max; i >= 0 ; --i)
        cr_expect_eq(remove_last_element(&list), i);
}

Test(list_destruction, simple)
{
    list_t *list = create_list(0);

    free_list(&list, NULL);
}

Test(list_destruction, empty)
{
    list_t *list = NULL;

    free_list(&list, NULL);
}

Test(list_destruction, big)
{
    list_t *list = NULL;

    for (size_t i = 0; i < 500; ++i)
        add_element(&list, i);

    free_list(&list, NULL);
}

Test(list_destruction, value_free)
{
    int *value = malloc(sizeof(int));
    list_t *list = create_list(value);

    *value = 42;
    free_list(&list, &free);
}

void consumer(size_t index, void *value)
{
    cr_expect_eq(index, value);
}

Test(list_for_each, simple)
{
    list_t *list = create_list(0);

    for_each_element(list, &consumer);
}

Test(list_for_each, empty)
{
    list_t *list = NULL;

    for_each_element(list, &consumer);
}

Test(list_for_each, big)
{
    list_t *list = NULL;

    for (size_t i = 0; i < 500; ++i)
        add_element(&list, i);
    for_each_element(list, &consumer);
}

Test(list_length, simple)
{
    list_t *list = create_list(0);

    cr_expect_eq(length_list(list), 1);
}

Test(list_length, empty)
{
    list_t *list = NULL;

    cr_expect_eq(length_list(list), 0);
}

Test(list_length, big)
{
    list_t *list = NULL;

    for (size_t i = 0; i < 9000; ++i)
        add_element(&list, i);
    cr_assert_eq(length_list(list), 9000);
}
