/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** health_module
*/

#include "my_rpg.h"

void health_contains_2(st_global *ad, int seconds, list_planet pl)
{
    for (int i = 0; i < pl->planet.modules[2]; i++) {
        if (seconds > 1) {
            if (pl->planet.modules[2] > 0)
                if (ad->var_game->life < ad->var_game->max_health)
                    ad->var_game->life += (int)5 * pl->planet.mul_housing;
            sfClock_restart(ad->planets->gen_mod->clock);
        }
    }
}

void health_contains(st_global *ad, int seconds, list_planet pl)
{
    if (circle_contains(500, (sfVector2f){pl->planet.pos.x,
    pl->planet.pos.y}, ad->ship->bshippos) && pl->planet.modules[2] > 0) {
        sfCircleShape_setPosition(ad->circle, (sfVector2f){(float)pl->planet.pos.x, (float)pl->planet.pos.y});
        sfRenderWindow_drawCircleShape(ad->window->window, ad->circle, NULL);
    }
    health_contains_2(ad, seconds, pl);
}

void effect_health_module(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    int rand;
    sfTime time = sfClock_getElapsedTime(ad->planets->gen_mod->clock);
    float seconds = time.microseconds / 1000000.0;

    while (pl != NULL) {
        if (pl->planet.colonized)
            health_contains(ad, seconds, pl);
        pl = pl->next;
    }
}