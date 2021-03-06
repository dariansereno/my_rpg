/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** atk_queue
*/

#include "my_rpg.h"

void throw_attack(st_global *ad)
{
    if (ad->boss->current != NULL) {
        attack_1(ad);
        attack_2(ad);
        attack_3(ad);
        attack_4(ad);
        attack_5(ad);
    }
}

void atk_queue_boss(st_global *ad)
{
    sfTime time;
    float second;

    if (!ad->var_game->boss_generated)
        return;
    time = sfClock_getElapsedTime(ad->boss->clock->clock);
    second = time.microseconds / 1000000.0;

    if (ad->boss->current == NULL) {
        ad->boss->current = ad->boss->atk_li;
        if (ad->boss->current != NULL){
            ad->boss->atk_li = pop_front_boss(ad->boss->atk_li);
            sfClock_restart(ad->boss->duration->clock);
        }
    }
    throw_attack(ad);
}