/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** attack_5
*/

#include "my_rpg.h"

void attack_5_shield(st_global *ad)
{
    sfSprite_setPosition(ad->boss->shield_sp, ad->boss->boss->pos);
    sfSprite_setOrigin(ad->boss->shield_sp, (sfVector2f){30, 30});
    sfSprite_setScale(ad->boss->shield_sp, (sfVector2f){10, 10});
    sfRenderWindow_drawSprite(ad->window->window, ad->boss->shield_sp, NULL);
}

void attack_5(st_global *ad)
{
    sfTime time;
    float second;
    sfTime time_s;
    float second_s;

    if (ad->boss->current == NULL || ad->boss->current->type != 5)
        return;
    time = sfClock_getElapsedTime(ad->boss->current->time->clock);
    second = time.microseconds / 1000000.0;
    if (second < ad->boss->current->duration) {
        ad->boss->shield = true;
        ad->boss->take_dmg = 0;
    }
    else  {
        ad->boss->take_dmg = 1;
        ad->boss->shield = false;
        sfClock_restart(ad->boss->clock->clock);
        ad->boss->current = NULL;
    }
}