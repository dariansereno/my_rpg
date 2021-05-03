/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** explode_anim
*/

#include "my_rpg.h"

void print_list_explo(list_timer *li, st_global *ad)
{
    list_timer temp = *li;
    list_timer buff = *li;

    if (temp == NULL)
        return ;
    while (temp != NULL) {
        temp->timer.time = sfClock_getElapsedTime(temp->timer.clock);
        temp->timer.seconds = temp->timer.time.microseconds / 1000000.0;
        if (temp->timer.seconds > 0.04) {
            ad->shoot->explo_rect.left += 46;
            if (ad->shoot->explo_rect.left >= 460) {
                ad->shoot->explo_rect.left = 0;
                pop_position_timer(li, temp->index);
                reindex_timer(li);
                temp = temp->next;
                continue;
            }
            sfClock_restart(temp->timer.clock);
        }
        sfSprite_setScale(ad->shoot->explo_sp, (sfVector2f){1.5, 1.5});
        sfSprite_setTextureRect(ad->shoot->explo_sp, ad->shoot->explo_rect);
        sfSprite_setOrigin(ad->shoot->explo_sp, (sfVector2f){23, 23});
        sfSprite_setPosition(ad->shoot->explo_sp, temp->pos);
        sfRenderWindow_drawSprite(ad->window->window, ad->shoot->explo_sp, NULL);
        temp = temp->next;
    }
}