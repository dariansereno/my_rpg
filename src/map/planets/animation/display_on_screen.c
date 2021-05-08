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
        if (planets->planet.pos.x >= ad->ship->viewrect.left - 1200 &&
        planets->planet.pos.x <= ad->ship->viewrect.left + WIDTH + 1200
        && planets->planet.pos.y >= ad->ship->viewrect.top - 1200 &&
        planets->planet.pos.y <= ad->ship->viewrect.top + HEIGHT + 1200)
            planets->on_screen = true;
        else
            planets->on_screen = false;
        planets = planets->next;
    }
}