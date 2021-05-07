/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** attack_1
*/

#include "my_rpg.h"

void attack_1_action(st_global *ad)
{
    sfTime time = sfClock_getElapsedTime(ad->boss->reload);
    float second = time.microseconds / 1000000.0;

    if (second > 0.5) {
        push_back_timer_b(&ad->boss->shoot, calculate_target_vector(ad->boss->
        boss->pos, ad->ship->bshippos,
        (int)heuristic(ad->boss->boss->pos, ad->ship->bshippos) / 50), ad->boss->boss->pos);
        sfClock_restart(ad->boss->reload);
    }
}

void attack_1(st_global *ad)
{
    sfTime time = sfClock_getElapsedTime(ad->boss->current->time->clock);
    float second = time.microseconds / 1000000.0;

    if (ad->boss->current->type != 1)
        return;
    if (second < ad->boss->current->duration) {
        printf("type = %d\n", ad->boss->current->type);
        if (ad->boss->clock->seconds > 0.5) {
            attack_1_action(ad);
            sfClock_restart(ad->boss->clock->clock);
        }
    }
    else {
        ad->boss->current = NULL;
    }
}