/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_drop_2
*/

#include "my_rpg.h"

int size_list_drop(list_drop li)
{
    list_drop node = li;
    int i = 0;

    for (; node != NULL; ++i)
        node = node->next;
    return (i);
}

void drop_copy_node(list_drop node, st_drop drop)
{
    node->drop.amount = drop.amount;
    node->drop.id = drop.id;
    node->drop.nb = drop.nb;
    node->drop.mode = drop.mode;
    node->drop.xp = drop.xp;
    node->drop.pos = drop.pos;
}

void push_back_drop(list_drop *li, st_drop drop)
{
    list_drop node = my_malloc(sizeof(*node));
    list_drop lastnode = *li;

    node->it = 0;
    node->index = size_list_drop(*li);
    node->timer.clock = sfClock_create();
    node->timer.seconds = 0;
    node->destroy = false;
    drop_copy_node(node, drop);
    node->next = NULL;
    if (*li == NULL)
        *li = node;
    else {
        while (lastnode->next != NULL)
            lastnode = lastnode->next;
        lastnode->next = node;
    }
}

void pop_position_drop(list_drop *list, int index)
{
    list_drop temp = *list;
    list_drop next = NULL;

    if (*list == NULL)
        return;
    if (index >= size_list_drop(*list))
        return ;
    if (index == 0) {
        *list = temp->next;
        sfClock_destroy(temp->timer.clock);
        return ;
    }
    for (; temp != NULL && temp->next->index != index ;)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    next = temp->next->next;
    sfClock_destroy(temp->next->timer.clock);
    temp->next = next;
}