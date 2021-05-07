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

void check_collision_ship_b(st_global *ad, list_timer_b *shoot)
{
    if (circle_contains(15, ad->ship->bshippos, (*shoot)->pos)) {
        ad->var_game->life -= ad->enn_damage;
        (*shoot)->destroy = true;
    }
    if (is_on_planet(ad, (*shoot)->pos))
        (*shoot)->destroy = true;
}

void print_list_shoot_b(list_timer_b *li, sfSprite *sprite, st_global *ad)
{
    list_timer_b temp = *li;
    list_timer_b buff = *li;

    if (temp == NULL)
        return ;
    while (temp != NULL) {
        temp->timer.time = sfClock_getElapsedTime(temp->timer.clock);
        temp->timer.seconds = temp->timer.time.microseconds / 1000000.0;
        if (temp->timer.seconds > 0.01) {
            temp->pos.x += (float)temp->dir.x;
            temp->pos.y += (float)temp->dir.y;
            temp->it += 1;
            sfClock_restart(temp->timer.clock);
        }
        sfSprite_setOrigin(sprite, (sfVector2f){16, 16});
        sfSprite_setScale(sprite, (sfVector2f){1.5, 1.5});
        sfSprite_setPosition(sprite, temp->pos);
        sfRenderWindow_drawSprite(ad->window->window, sprite, NULL);
        if (is_on_planet(ad, temp->pos))
            temp->destroy = true;
        if (temp->it >= 40)
            temp->destroy = true;
        check_collision_ship_b(ad, &temp);
        if (temp->destroy == true)
            pop_position_timer_b(li, temp->index);
        reindex_timer_b(li);
        temp = temp->next;
    }
}