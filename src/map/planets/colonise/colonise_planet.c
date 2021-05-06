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

void print_can_trade(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    int print = 180;

    while (pl != NULL) {
        if (pl->can_interact && pl->size == 2 && pl->planet.tradable) {
            if (pl->planet.type >= 7 && pl->planet.type <= 20 && pl->can_interact \
            && pl->size == 2 && !pl->planet.colonized && \
            ad->ressources[3].nb >= 1)
                print = 210;
            sfText_setPosition(ad->ressources[0].text, (sfVector2f) \
            {pl->planet.pos.x - 97, pl->planet.pos.y - print});
            sfText_setString(ad->ressources[0].text, "Press I to trade");
            sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text,
            NULL);
        }
        pl = pl->next;
    }
}

void print_can_quest(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    int print = 180;

    while (pl != NULL) {
        if (pl->can_interact && pl->size == 2 && pl->planet.quest) {
            if (pl->planet.type >= 7 && pl->planet.type <= 20 && pl->can_interact \
            && pl->size == 2 && !pl->planet.colonized && \
            ad->ressources[3].nb >= 1)
                print += 30;
            if (pl->planet.type >= 7 && pl->planet.type <= 20 && pl->can_interact \
            && pl->size == 2 && !pl->planet.colonized && \
            ad->ressources[3].nb >= 1)
                print += 30;
            sfText_setPosition(ad->ressources[0].text, (sfVector2f) \
            {pl->planet.pos.x - 97, pl->planet.pos.y - print});
            sfText_setString(ad->ressources[0].text, "Press Q to interact");
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
            ad->var_game->xp += random_between(10, 50) * ad->var_game->mul_xp;
            ad->ressources[3].nb -= 1;
            break;
        }
        pl = pl->next;
    }
}