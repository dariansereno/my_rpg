/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** interaction
*/

#include "my_rpg.h"

void interaction(st_global *ad)
{
    list_planet planet = ad->planets->planets;
    sfVector2f s = sfSprite_getPosition(ad->ship->bship);
    sfVector2f p = (sfVector2f){0, 0};
    int r = 350;

    while (planet != NULL) {
        p = sfSprite_getPosition(planet->planet.sprite);
        if (((s.x - p.x) * (s.x - p.x)) + ((s.y - p.y) * (s.y - p.y)) < (r * r)
        && planet->size == 2) {
            printf("orgie d'homme bien dur\n");
            planet->can_interact = true;
        }
        else
            planet->can_interact = false;
        planet = planet->next;
    }
}