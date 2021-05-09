/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** ship_shoot_2
*/

#include "my_rpg.h"

void ship_shoot(st_global *ad)
{
    sfTime time = sfClock_getElapsedTime(ad->ship->reload->clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > ad->var_game->reload_time) {
        push_back_timer(&ad->shoot->li_shoot, ad->ship->bshippos,
        deduct_dir(ad));
        reindex_timer(&ad->shoot->li_shoot);
        sfClock_restart(ad->ship->reload->clock);
    }
}