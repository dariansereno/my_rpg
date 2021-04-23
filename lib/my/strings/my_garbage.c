/*
** EPITECH PROJECT, 2019
** garbage_collector.c
** File description:
** functions for garbage_collector
*/

#include "strings.h"
#include <stdlib.h>
#include <stdio.h>

my_garbage_t **current_garbage(void)
{
    static my_garbage_t *garbage = NULL;

    return (&garbage);
}

void call_after_main(void)
{
    my_garbage_t **garbage = current_garbage();

    if (*garbage == NULL)
        return;
    destroy_ptr_to_garbage(*garbage);
}

my_garbage_t *add_ptr_to_garbage \
(my_garbage_t *garbage, void *mal)
{
    my_garbage_t *node = malloc(sizeof(my_garbage_t));

    if (node == NULL)
        return (NULL);
    node->mal = mal;
    node->next = garbage;
    return (node);
}

void destroy_ptr_to_garbage(my_garbage_t *garbage)
{
    my_garbage_t *node = NULL;
    
    while (garbage != NULL) {
        node = garbage;
        free(garbage->mal);
        garbage = garbage->next;
        free(node);
    }
}

void *my_malloc(int size_of)
{
    my_garbage_t **garbage = current_garbage();
    void *ptr = malloc(size_of);

    if (ptr == NULL) {
        free(ptr);
        return (NULL);
    }
    *garbage = add_ptr_to_garbage(*garbage, ptr);
    if (*garbage == NULL)
        return (NULL);
    return (ptr);
}