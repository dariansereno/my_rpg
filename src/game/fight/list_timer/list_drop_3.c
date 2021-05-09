/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_drop_3
*/

#include "my_rpg.h"

list_drop pop_front_drop(list_drop li)
{
    list_elem_drop *elem;

    if (li == NULL)
        return (li);

    elem = my_malloc(sizeof(*elem));

    elem = li->next;
    sfClock_destroy(li->timer.clock);
    li = NULL;

    return (elem);
}

void destroy_list_drop(list_drop *li)
{
    while (*li != NULL)
        *li = pop_front_drop(*li);
    if (*li != NULL) {
        sfClock_destroy((*li)->timer.clock);
        *li = NULL;
    }
}