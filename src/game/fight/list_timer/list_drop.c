/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_drop
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

void push_back_drop(list_drop *li, st_drop drop)
{
    list_drop node = malloc(sizeof(*node));
    list_drop lastnode = *li;

    node->it = 0;
    node->index = size_list_drop(*li);
    node->timer.clock = sfClock_create();
    node->timer.seconds = 0;
    node->destroy = false;
    node->drop.amount = drop.amount;
    node->drop.id = drop.id;
    node->drop.nb = drop.nb;
    node->drop.mode = drop.mode;
    node->drop.pos = drop.pos;
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

void reindex_drop(list_drop *li)
{
    list_drop temp = *li;

    if (temp == NULL)
        return ;
    for (int i = 0; temp != NULL; i++) {
        temp->index = i;
        temp = temp->next;
    }
    return ;
}

void print_list_drop(list_drop *li, st_global *ad)
{
    list_drop temp = *li;
    list_drop buff = *li;

    if (temp == NULL)
        return ;
    while (temp != NULL) {
        temp->timer.time = sfClock_getElapsedTime(temp->timer.clock);
        temp->timer.seconds = temp->timer.time.microseconds / 1000000.0;
        if (temp->timer.seconds > 0.01) {
            temp->it += 1;
            sfClock_restart(temp->timer.clock);
        }
        if (temp->drop.mode == 0) {
            sfText_setString(ad->ressources[0].text, itoa(temp->drop.nb, ad->nb_inv, 10));
            sfText_setPosition(ad->ressources[0].text, temp->drop.pos);
            sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);
            sfSprite_setPosition(ad->items[temp->drop.id]->sprite, (sfVector2f){temp->drop.pos.x
            + 13, temp->drop.pos.y});
            sfRenderWindow_drawSprite(ad->window->window, ad->items[temp->drop.id]->sprite, NULL);
        }
        else {
            sfText_setString(ad->ressources[0].text, number_and_string(temp->drop.amount, "credits +"));
            sfText_setPosition(ad->ressources[0].text, (sfVector2f){temp->drop.pos.x
            + 10, temp->drop.pos.y});
            sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);
        }
        if (temp->it >= 80)
            temp->destroy = true;
        if (temp->destroy == true)
            pop_position_drop(li, temp->index);
        reindex_drop(li);
        temp = temp->next;
    }
}