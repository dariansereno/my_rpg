/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** destroy_boss
*/

#include "my_rpg.h"

void destroy_boss_fight(st_global *ad)
{
    sfSprite_destroy(ad->boss->bg->sprite);
    sfTexture_destroy(ad->boss->bg->texture);
    sfSprite_destroy(ad->boss->boss->sprite);
    sfTexture_destroy(ad->boss->boss->texture);
    if (ad->boss->current != NULL)
        sfClock_destroy(ad->boss->current->time->clock);
    sfClock_destroy(ad->boss->clock->clock);
    sfClock_destroy(ad->boss->atk_timer->clock);
    destroy_list_boss(&ad->boss->atk_li);
}