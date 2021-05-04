/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** colonise_planet
*/

#include "my_rpg.h"

void print_can_colonise(st_global *ad)
{
    list_planet pl = ad->planets->planets;

    while (pl != NULL) {
        if (pl->planet.type >= 7 && pl->planet.type <= 20 && pl->can_interact \
        && pl->size == 2 && !pl->planet.colonized && \
        ad->ressources[3].nb >= 1) {
            sfText_setPosition(ad->ressources[0].text, (sfVector2f) \
            {pl->planet.pos.x - 120, pl->planet.pos.y - 180});
            sfText_setString(ad->ressources[0].text, "Press C to colonize");
            sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text,
            NULL);
        }
        pl = pl->next;
    }
}

void colonise_planet(st_global *ad)
{
    list_planet pl = ad->planets->planets;

    while (pl != NULL) {
        if (pl->planet.type >= 7 && pl->planet.type <= 20 && pl->can_interact \
        && pl->size == 2 && !pl->planet.colonized && ad->ressources[3].nb >= 1 \
        && ad->window->event.type == sfEvtKeyPressed
        && ad->window->event.key.code == sfKeyC) {
            pl->planet.colonized = true;
            ad->ressources[3].nb -= 1;
            printf("sexe\n");
            break;
        }
        pl = pl->next;
    }
}