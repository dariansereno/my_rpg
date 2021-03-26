/*
** EPITECH PROJECT, 2021
** garbage
** File description:
** garbage
*/

#include "strings.h"
#include <stdlib.h>

void destroy_collector(garbage_t *collector)
{
    garbage_t *temp = NULL;

    while (collector != NULL) {
        temp = collector;
        free(collector->ptr);
        collector = collector->next;
        free(temp);
    }
}

void call_after_main(void)
{
    garbage_t **collector = my_garbage();

    if (*collector == NULL)
        return;
    destroy_collector(*collector);
}

garbage_t *add_to_garbage(garbage_t *garbage, void *ptr)
{
    garbage_t *new_node = malloc(sizeof(garbage_t));

    if (new_node == NULL)
        return (NULL);
    new_node->ptr = ptr;
    new_node->next = garbage;
    return (new_node);
}

garbage_t **my_garbage(void)
{
    static garbage_t *garbage = NULL;

    return (&garbage);
}

void *my_malloc(int size)
{
    void *ptr = malloc(size);
    garbage_t **garbage = my_garbage();

    if (ptr == NULL)
        return (NULL);
    *garbage = add_to_garbage(*garbage, ptr);
    if (*garbage == NULL)
        return (NULL);
    return (ptr);
}