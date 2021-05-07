/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_boss
*/

#include "my_rpg.h"

int size_list_boss(list_boss li)
{
    list_boss node = li;
    int i = 0;

    for (; node != NULL; ++i)
        node = node->next;
    return (i);
}

void push_back_boss(list_boss *li, int duration, int atk_type)
{
    list_boss node = my_malloc(sizeof(*node));
    list_boss lastnode = *li;

    node->duration = duration;
    node->type = atk_type;
    node->time = malloc(sizeof(*node->time));
    node->time->clock = sfClock_create();
    node->next = NULL;
    if (*li == NULL)
        *li = node;
    else {
        while (lastnode->next != NULL)
            lastnode = lastnode->next;
        lastnode->next = node;
    }
}

list_boss pop_front_boss(list_boss li)
{
    list_elem_boss *elem;

    if (li == NULL)
        return (li);

    elem = my_malloc(sizeof(*elem));

    elem = li->next;
    li = NULL;

    return (elem);
}

void destroy_list_boss(list_boss *li)
{
    while (*li != NULL)
        *li = pop_front_boss(*li);
    if (*li != NULL) {
        sfClock_destroy((*li)->time->clock);
        free((*li)->time);
        *li = NULL;
    }
}