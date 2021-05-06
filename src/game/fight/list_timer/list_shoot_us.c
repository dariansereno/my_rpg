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

void print_list_shoot(list_timer *li, sfSprite **sprite, st_global *ad)
{
    list_timer temp = *li;
    list_timer buff = *li;

    if (temp == NULL)
        return ;
    while (temp != NULL) {
        temp->timer.time = sfClock_getElapsedTime(temp->timer.clock);
        temp->timer.seconds = temp->timer.time.microseconds / 1000000.0;
        if (temp->timer.seconds > 0.01) {
            temp->pos = change_pos_by_dir(temp->dir, temp->pos);
            temp->it += 1;
            sfClock_restart(temp->timer.clock);
        }
        sfSprite_setScale(sprite[temp->dir], (sfVector2f){1.5, 1.5});
        sfSprite_setPosition(sprite[temp->dir], temp->pos);
        sfRenderWindow_drawSprite(ad->window->window, sprite[temp->dir], NULL);
        if (is_on_planet(ad, temp->pos))
            temp->destroy = true;
        if (temp->it >= ad->var_game->range)
            temp->destroy = true;
        collision_shoot(ad, &temp);
        if (temp->destroy == true)
            pop_position_timer(li, temp->index);
        reindex_timer(li);
        temp = temp->next;
    }
}