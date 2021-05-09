/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list
*/

#include "my_rpg.h"

void push_back_timer_b(list_timer_b *li, sfVector2f dir, sfVector2f pos)
{
    list_timer_b node = malloc(sizeof(*node));
    list_timer_b lastnode = *li;

    node->it = 0;
    node->index = size_list_timer_b(*li);
    node->timer.clock = sfClock_create();
    node->timer.seconds = 0;
    node->destroy = false;
    node->pos = pos;
    node->dir = dir;
    node->next = NULL;
    if (*li == NULL)
        *li = node;
    else {
        while (lastnode->next != NULL)
            lastnode = lastnode->next;
        lastnode->next = node;
    }
}

void pop_position_timer_b(list_timer_b *list, int index)
{
    list_timer_b temp = *list;
    list_timer_b next = NULL;

    if (*list == NULL)
        return;
    if (index >= size_list_timer_b(*list))
        return ;
    if (index == 0) {
        *list = temp->next;
        free(temp);
        return ;
    }
    for (; temp != NULL && temp->next->index != index ;)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    next = temp->next->next;
    sfClock_destroy(temp->next->timer.clock);
    free(temp->next);
    temp->next = next;
}

void reindex_timer_b(list_timer_b *li)
{
    list_timer_b temp = *li;

    if (temp == NULL)
        return ;
    for (int i = 0; temp != NULL; i++) {
        temp->index = i;
        temp = temp->next;
    }
    return ;
}

int size_list_timer_b(list_timer_b li)
{
    list_timer_b node = li;
    int i = 0;

    for (; node != NULL; ++i){
        node = node->next;}
    return (i);
}

list_timer_b timer_from_index_b(int index, list_timer_b li)
{
    list_timer_b temp = li;

    if (temp == NULL)
        return (NULL);
    while (temp->index != index)
        temp = temp->next;
    if (temp == NULL)
        return (NULL);
    return (temp);
}