/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** interaction
*/

#include "my_rpg.h"

void display_selector(st_object *selector, st_global *ad, list_planet planets,
sfVector2f origin)
{
    sfSprite_setPosition(selector->sprite, (sfVector2f)
    {(float)planets->planet.pos.x, (float)planets->planet.pos.y});
    sfSprite_setOrigin(selector->sprite, origin);
    sfSprite_setScale(selector->sprite, (sfVector2f){5, 5});
    sfRenderWindow_drawSprite(ad->window->window, selector->sprite
    ,NULL);
}

void display_interaction(st_global *ad)
{
    list_planet planets = ad->planets->planets;
    sfVector2f disp = {0, 0};

    while (planets != NULL) {
        if (planets->interact == true) {
            disp.x = ad->ship->viewrect.left + 1750;
            disp.y = ad->ship->viewrect.top + 50;
            sfSprite_setPosition(ad->ui->interacting->sprite, disp);
            sfSprite_setScale(ad->ui->interacting->sprite, (sfVector2f){7, 7});
            sfRenderWindow_drawSprite(ad->window->window,
            ad->ui->interacting->sprite, NULL);
            if (planets->planet.type >= 0 && planets->planet.type <= 6)
                display_selector(ad->ui->selector[1], ad, planets,
                (sfVector2f){39, 39});
            if (planets->planet.type >= 7 && planets->planet.type <= 23)
                display_selector(ad->ui->selector[0], ad, planets,
                (sfVector2f){27, 27});
            if (planets->planet.type >= 24)
                display_selector(ad->ui->selector[2], ad, planets,
                (sfVector2f){31.5, 32});
        }
        planets = planets->next;
    }
}