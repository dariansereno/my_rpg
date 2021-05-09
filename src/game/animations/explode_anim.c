/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** explode_anim
*/

#include "my_rpg.h"

int print_list_explo_lil_boss_rect(list_timer *temp, list_timer *li)
{
    if ((*temp)->timer.seconds > 0.04) {
        (*temp)->rect.left += 46;
        if ((*temp)->rect.left >= 460) {
            (*temp)->rect.left = 0;
            pop_position_timer(li, (*temp)->index);
            reindex_timer(li);
            (*temp) = (*temp)->next;
            return (0);
        }
        sfClock_restart((*temp)->timer.clock);
    }
    return (1);
}

void print_list_explo_lil_boss(list_timer *li, st_global *ad)
{
    list_timer temp = *li;
    list_timer buff = *li;

    if (temp == NULL)
        return ;
    while (temp != NULL) {
        temp->timer.time = sfClock_getElapsedTime(temp->timer.clock);
        temp->timer.seconds = temp->timer.time.microseconds / 1000000.0;
        if (!print_list_explo_lil_boss_rect(&temp, li))
            continue;
        sfSprite_setScale(ad->shoot->explo_sp, (sfVector2f){8, 8});
        sfSprite_setTextureRect(ad->shoot->explo_sp, temp->rect);
        sfSprite_setOrigin(ad->shoot->explo_sp, (sfVector2f){23, 23});
        sfSprite_setPosition(ad->shoot->explo_sp, temp->pos);
        sfRenderWindow_drawSprite(ad->window->window, ad->shoot->explo_sp, \
        NULL);
        temp = temp->next;
    }
}

int print_list_explo_rect(list_timer *temp, list_timer *li)
{
    if ((*temp)->timer.seconds > 0.04) {
        (*temp)->rect.left += 46;
        if ((*temp)->rect.left >= 460) {
            (*temp)->rect.left = 0;
            pop_position_timer(li, (*temp)->index);
            reindex_timer(li);
            (*temp) = (*temp)->next;
            return (0);
        }
        sfClock_restart((*temp)->timer.clock);
    }
    return (1);
}

void print_list_explo(list_timer *li, st_global *ad)
{
    list_timer temp = *li;
    list_timer buff = *li;

    if (temp == NULL)
        return ;
    while (temp != NULL) {
        temp->timer.time = sfClock_getElapsedTime(temp->timer.clock);
        temp->timer.seconds = temp->timer.time.microseconds / 1000000.0;
        if (!print_list_explo_rect(&temp, li))
            continue;
        sfSprite_setScale(ad->shoot->explo_sp, (sfVector2f){1.5, 1.5});
        sfSprite_setTextureRect(ad->shoot->explo_sp, temp->rect);
        sfSprite_setOrigin(ad->shoot->explo_sp, (sfVector2f){23, 23});
        sfSprite_setPosition(ad->shoot->explo_sp, temp->pos);
        sfRenderWindow_drawSprite(ad->window->window, ad->shoot->explo_sp, \
        NULL);
        temp = temp->next;
    }
}