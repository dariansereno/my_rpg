/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_drop
*/

#include "my_rpg.h"

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

void list_drop_mode_0(st_global *ad, list_drop *temp)
{
    sfText_setString(ad->ressources[0].text, itoa((*temp)->drop.nb, \
    ad->nb_inv, 10));
    sfText_setPosition(ad->ressources[0].text, (*temp)->drop.pos);
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, \
    NULL);
    sfSprite_setPosition(ad->items[(*temp)->drop.id]->sprite, (sfVector2f) \
    {(*temp)->drop.pos.x
    + 13, (*temp)->drop.pos.y});
    sfRenderWindow_drawSprite(ad->window->window, ad->items \
    [(*temp)->drop.id]->sprite, NULL);
    sfText_setString(ad->ressources[0].text, \
    number_and_string((*temp)->drop.xp, "xp +"));
    sfText_setPosition(ad->ressources[0].text, \
    (sfVector2f){(*temp)->drop.pos.x + 8, (*temp)->drop.pos.y + 25});
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, \
    NULL);
}

void list_drop_mode_1(st_global *ad, list_drop *temp)
{
    sfText_setString(ad->ressources[0].text, \
    number_and_string((*temp)->drop.amount, "credits +"));
    sfText_setPosition(ad->ressources[0].text, (sfVector2f){ \
    (*temp)->drop.pos.x + 10, (*temp)->drop.pos.y});
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, \
    NULL);
    sfText_setString(ad->ressources[0].text, \
    number_and_string((*temp)->drop.xp, "xp +"));
    sfText_setPosition(ad->ressources[0].text, \
    (sfVector2f){(*temp)->drop.pos.x + 8, (*temp)->drop.pos.y + 25});
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, \
    NULL);
}

void print_list_drop_contents(list_drop *li, st_global *ad, list_drop *temp)
{
    (*temp)->timer.time = sfClock_getElapsedTime((*temp)->timer.clock);
    (*temp)->timer.seconds = (*temp)->timer.time.microseconds / 1000000.0;
    if ((*temp)->timer.seconds > 0.01) {
        (*temp)->it += 1;
        sfClock_restart((*temp)->timer.clock);
    }
    if ((*temp)->drop.mode == 0)
        list_drop_mode_0(ad, temp);
    else
        list_drop_mode_1(ad, temp);
}

void print_list_drop(list_drop *li, st_global *ad)
{
    list_drop temp = *li;
    list_drop buff = *li;

    if (temp == NULL)
        return ;
    while (temp != NULL) {
        print_list_drop_contents(li, ad, &temp);
        if (temp->it >= 80)
            temp->destroy = true;
        if (temp->destroy == true)
            pop_position_drop(li, temp->index);
        reindex_drop(li);
        temp = temp->next;
    }
}