/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** linked list main actions
*/

#include "my_rpg.h"

void push_back_timer(list_timer *li, sfVector2f pos, int dir)
{
    list_timer node = malloc(sizeof(*node));
    list_timer lastnode = *li;

    node->it = 0;
    node->index = size_list_timer(*li);
    node->timer.clock = sfClock_create();
    node->timer.seconds = 0;
    node->destroy = false;
    node->rect = (sfIntRect){.height = 46, .width = 46, .left = 0,
    .top = 0};
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

void pop_position_timer(list_timer *list, int index)
{
    list_timer temp = *list;
    list_timer next = NULL;

    if (*list == NULL)
        return;
    if (index >= size_list_timer(*list))
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
    free(temp->next);
    temp->next = next;
}

void reindex_timer(list_timer *li)
{
    list_timer temp = *li;

    if (temp == NULL)
        return ;
    for (int i = 0; temp != NULL; i++) {
        temp->index = i;
        temp = temp->next;
    }
    return ;
}

int size_list_timer(list_timer li)
{
    list_timer node = li;
    int i = 0;

    for (; node != NULL; ++i){
        node = node->next;}
    return (i);
}

list_timer timer_from_index(int index, list_timer li)
{
    list_timer temp = li;

    if (temp == NULL)
        return (NULL);
    while (temp->index != index)
        temp = temp->next;
    if (temp == NULL)
        return (NULL);
    return (temp);
}