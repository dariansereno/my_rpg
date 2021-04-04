/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** display_on_screen
*/

#include "my_rpg.h"

void display_on_view(st_global *ad)
{
    list_planet planets = ad->planets->planets;
    sfFloatRect bg;

    while (planets != NULL) {
        if (planets->planet.pos.x >= ad->ship->viewrect.left - 200 &&
        planets->planet.pos.x <= ad->ship->viewrect.left + 1920 + 200
        && planets->planet.pos.y >= ad->ship->viewrect.top - 200 &&
        planets->planet.pos.y <= ad->ship->viewrect.top + 1080 + 200)
            planets->on_screen = true;
        else
            planets->on_screen = false;
        planets = planets->next;
    }
}