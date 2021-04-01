/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** collisions
*/

#include "my_rpg.h"

void planet_collision(st_global *ad)
{
    list_planet planet = ad->planets->planets;
    sfVector2f s = sfSprite_getPosition(ad->ship->bship);
    sfVector2f p = (sfVector2f){0, 0};
    int r = 100;

    while (planet != NULL) {
        p = sfSprite_getPosition(planet->planet.sprite);
        if (((s.x - p.x) * (s.x - p.x)) + ((s.y - p.y) * (s.y - p.y)) < (r * r)) {
            printf("oui\n");
        }
        planet = planet->next;
    }
}