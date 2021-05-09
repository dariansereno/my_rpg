/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_action2
*/

#include "my_rpg.h"

list_planet pop_back_planet(list_planet list)
{
    list_elem_planet *temp = NULL;
    list_elem_planet *buf = NULL;

    if (list == NULL)
        return (NULL);
    if (list->next == NULL) {
        list = NULL;
        return (NULL);
    }
    temp = list;
    buf = list;
    while (temp->next != NULL) {
        buf = temp;
        temp = temp->next;
    }
    buf->next = NULL;
    destroy_planet(temp);
    temp = NULL;
    return (list);
}

list_planet planet_from_index(int index, list_planet li)
{
    list_planet temp = li;

    if (temp == NULL)
        return (NULL);
    while (temp->index != index)
        temp = temp->next;
    if (temp == NULL)
        return (NULL);
    return (temp);
}

void init_planet(list_planet *node, list_planet *li, st_planet planet)
{
    (*node)->size = random_piped();
    (*node)->timer.clock = sfClock_create();
    (*node)->move.clock = sfClock_create();
    (*node)->spawning.clock = sfClock_create();
    (*node)->direction = random_between(0, 7);
    (*node)->index = size_list_planet(*li);
    (*node)->ennemies_spawn = random_between(5, 15);
    (*node)->sc = random_between(9, 13);
    (*node)->can_interact = false;
}

void push_back_planet(list_planet *li, st_planet planet)
{
    list_planet node = my_malloc(sizeof(*node));
    list_planet lastnode = *li;

    node->planet = planet;
    init_planet(&node, li, planet);
    node->next = NULL;
    if (*li == NULL)
        *li = node;
    else {
        while (lastnode->next != NULL)
            lastnode = lastnode->next;
        lastnode->next = node;
    }
}