/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** extract_mod
*/

#include "my_rpg.h"

void extract(st_global *ad, list_planet *pl)
{
    int rand = random_between(0, 10);

    if (rand <= 5)
            ad->ressources[0].nb += 1;
    else if (rand > 5 && rand <= 8)
        ad->ressources[1].nb += (int)1 * (*pl)->planet.mul_housing;
    else
        ad->ressources[2].nb += (int)1 * (*pl)->planet.mul_housing;
}

void effect_extract_module_content_2(st_global *ad, list_planet *pl)
{
    for (int i = 0; i < (*pl)->planet.modules[3]; i++)
        extract(ad, pl);
}

void effect_extract_module_content(st_global *ad, list_planet *pl)
{
    if ((*pl)->planet.colonized)
        effect_extract_module_content_2(ad, pl);
}

void effect_extract_module(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    sfTime time = sfClock_getElapsedTime(ad->planets->extract);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 40) {
        while (pl != NULL) {
            effect_extract_module_content(ad, &pl);
            pl = pl->next;
        }
        sfClock_restart(ad->planets->extract);
    }
}