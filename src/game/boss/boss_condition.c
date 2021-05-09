/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** boss_condition
*/

#include "my_rpg.h"

void spawn_boss_condition(st_global *ad)
{
    if (ad->var_game->lvl >= 12 && !ad->msg_boss) {
        ad->var_game->is_boss = true;
        display_big_message("THE BOSS IS HERE!", 5, ad, sfRed);
    }
    if (ad->big_msg == NULL)
        ad->msg_boss = true;
}

void victory(st_global *ad)
{
    sfTime time = sfClock_getElapsedTime(ad->var_game->victory_clock);
    float second = time.microseconds / 1000000.0;

    if (ad->var_game->destroy_boss && !ad->var_game->died) {
        sfClock_restart(ad->var_game->victory_clock);
        ad->var_game->died = true;
    }
    else if (ad->var_game->died) {
        if (second > 1.5) {
            ad->win = true;
            ad->ui->end->existing = true;
        }
    }
}