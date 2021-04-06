/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** planet_card
*/

#include "my_rpg.h"

void display_planet_card(st_global *g)
{
    list_planet planets = NULL;

    if (g->ui->planet_card->existing == sfTrue) {
        planets = g->planets->planets;
        sfRenderWindow_drawSprite(g->window->window, g->ui->planet_card->mockup_s, NULL);
        while (planets != NULL) {
            if (planets->interact == true) {
                sfSprite_setPosition(planets->planet.sprite, \
                (sfVector2f){g->ship->viewrect.left + 965, g->ship->viewrect.top + 440});
                sfRenderWindow_drawSprite(g->window->window, planets->planet.sprite, NULL);
            }
            planets = planets->next;
        }
    }
}