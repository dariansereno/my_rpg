/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** print_colonised
*/

#include "my_rpg.h"

void print_colonised_selec(st_global *ad)
{
    list_planet pl = ad->planets->planets;

    while (pl != NULL) {
        if (pl->planet.colonized) {
            sfSprite_setPosition(ad->planets->colonized_pl, (sfVector2f)
            {(float)pl->planet.pos.x, (float)pl->planet.pos.y});
            sfSprite_setScale(ad->planets->colonized_pl, (sfVector2f){5, 5});
            sfRenderWindow_drawSprite(ad->window->window, \
            ad->planets->colonized_pl, NULL);
        }
        pl = pl->next;
    }
}