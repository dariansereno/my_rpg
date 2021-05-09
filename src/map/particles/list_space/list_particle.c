/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_particle
*/

#include "my_rpg.h"

int size_list_particle(list_particle li)
{
    list_particle node = li;
    int i = 0;

    for (; node != NULL; ++i)
        node = node->next;
    return (i);
}

void push_particle_copy_node(list_particle node, st_global_particle *g,
sfVector2f pos)
{
    node->particle.lifetime = 5;
    node->particle.color = (sfColor){random_between(100, 150),
    random_between(100, 150), random_between(100, 150), 255};
    node->particle.radius = 4;
    node->particle.alpha = 255;
    node->particle.emitter = pos;
    node->particle.clock = sfClock_create();
    node->particle.start_time = sfClock_getElapsedTime(g->clock).microseconds
    / 1000000.0;
}

void push_back_particle(list_particle *li, st_global_particle *g,
sfVector2f pos)
{
    list_particle node = my_malloc(sizeof(*node));
    list_particle lastnode = *li;

    push_particle_copy_node(node, g, pos);
    node->index = size_list_particle(*li);
    node->destroy = false;
    node->next = NULL;
    if (*li == NULL)
        *li = node;
    else {
        while (lastnode->next != NULL)
            lastnode = lastnode->next;
        lastnode->next = node;
    }
}

void pop_position_particle(list_particle *list, int index)
{
    list_particle temp = *list;
    list_particle next = NULL;

    if (*list == NULL)
        return;
    if (index >= size_list_particle(*list))
        return ;
    if (index == 0) {
        *list = temp->next;
        return ;
    }
    for (; temp != NULL && temp->next->index != index ;)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    next = temp->next->next;
    temp->next = next;
}

void reindex_particle(list_particle *li)
{
    list_particle temp = *li;

    if (temp == NULL)
        return ;
    for (int i = 0; temp != NULL; i++) {
        temp->index = i;
        temp = temp->next;
    }
    return ;
}