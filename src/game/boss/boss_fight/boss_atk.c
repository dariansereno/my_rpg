/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** boss_atk
*/

#include "my_rpg.h"

void boss_atk(st_global *ad)
{
    if (!ad->var_game->boss_generated)
        return;
    sfTime time;
    float second;

    time = sfClock_getElapsedTime(ad->boss->atk_timer->clock);
    second = time.microseconds / 1000000.0;
    if (second > 1) {
        push_back_boss(&ad->boss->atk_li, random_between(5, 10), random_between(2, 2));
        sfClock_restart(ad->boss->atk_timer->clock);
    }
}