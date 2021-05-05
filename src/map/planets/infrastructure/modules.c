/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** commercial_mod
*/

#include "my_rpg.h"

void effect_com_module(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    sfTime time = sfClock_getElapsedTime(ad->planets->gen_mod->clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 10) {
        while (pl != NULL) {
            if (pl->planet.colonized) {
                for (int i = 0; i < pl->planet.modules[1]; i++) {
                    ad->money->money += 30; // ajouter multiplicateur du module habitation
                }
            }
            pl = pl->next;
        }
        sfClock_restart(ad->planets->gen_mod->clock);
    }
}

void effect_extract_module(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    sfTime time = sfClock_getElapsedTime(ad->planets->gen_mod->clock);
    float seconds = time.microseconds / 1000000.0;
    int rand;

    if (seconds > 60) {
        while (pl != NULL) {
            if (pl->planet.colonized) {
                for (int i = 0; i < pl->planet.modules[3]; i++) {
                    rand = random_between(0, 10);
                    if (rand <= 5)
                        ad->ressources[0].nb += 1;
                    else if (rand > 5 && rand <= 8)
                        ad->ressources[1].nb += 1;
                    else
                        ad->ressources[2].nb += 1;
                }
            }
            pl = pl->next;
        }
        sfClock_restart(ad->planets->gen_mod->clock);
    }
}

void effect_health_module(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    int rand;
    sfTime time = sfClock_getElapsedTime(ad->planets->gen_mod->clock);
    float seconds = time.microseconds / 1000000.0;

    while (pl != NULL) {
        if (pl->planet.colonized) {
            if (circle_contains(300, (sfVector2f){pl->planet.pos.x,
            pl->planet.pos.y}, ad->ship->bshippos)) {
                sfCircleShape_setOrigin(ad->circle, (sfVector2f){150, 150});
                sfCircleShape_setPosition(ad->circle, (sfVector2f){(float)pl->planet.pos.x, (float)pl->planet.pos.y});
                sfRenderWindow_drawCircleShape(ad->window->window, ad->circle, NULL);
            }
            for (int i = 0; i < pl->planet.modules[2]; i++) {
                if (seconds > 1) {
                    if (pl->planet.modules[2] > 0)
                        if (ad->ship->life < 200)
                            ad->ship->life += 5;
                }
            }
        }
        pl = pl->next;
    }
}