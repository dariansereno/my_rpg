/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** com_module
*/

#include "my_rpg.h"

void effect_com_module_content(st_global *ad, list_planet *pl)
{
    if ((*pl)->planet.colonized) {
        for (int i = 0; i < (*pl)->planet.modules[1]; i++) {
            ad->money->money += (int)30 * (*pl)->planet.mul_housing;
        }
    }
}

void effect_com_module(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    sfTime time = sfClock_getElapsedTime(ad->planets->com);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 10) {
        while (pl != NULL) {
            effect_com_module_content(ad, &pl);
            pl = pl->next;
        }
        sfClock_restart(ad->planets->com);
    }
}