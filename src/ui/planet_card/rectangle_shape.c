/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** rectangle_shape
*/

#include "my_rpg.h"

void rectangle_shape_planet_card_set(st_global *g, list_planet planets)
{
    sfRectangleShape_setSize(g->ui->planet_card->r_o_2, \
    (sfVector2f){(266 * planets->planet.stats.o / 100), 9});
    sfRectangleShape_setSize(g->ui->planet_card->r_h, \
    (sfVector2f){(266 * planets->planet.stats.h / 100), 9});
    sfRectangleShape_setSize(g->ui->planet_card->r_h_2_o, \
    (sfVector2f){(266 * planets->planet.stats.h2o / 100), 9});
    sfRectangleShape_setSize(g->ui->planet_card->r_co_2, \
    (sfVector2f){(266 * planets->planet.stats.co2 / 100), 9});
    sfRectangleShape_setSize(g->ui->planet_card->r_n, \
    (sfVector2f){(266 * planets->planet.stats.N / 100), 9});
    sfRectangleShape_setSize(g->ui->planet_card->r_n_2, \
    (sfVector2f){(266 * planets->planet.stats.n2 / 100), 9});
    sfRectangleShape_setFillColor(g->ui->planet_card->r_o_2, \
    sfColor_fromRGB(177, 198, 170));
    sfRectangleShape_setFillColor(g->ui->planet_card->r_co_2, \
    sfColor_fromRGB(177, 198, 170));
    sfRectangleShape_setFillColor(g->ui->planet_card->r_h, \
    sfColor_fromRGB(177, 198, 170));
    rectangle_shape_planet_card_position(g);
}

void rectangle_shape_planet_card_position(st_global *g)
{
    sfRectangleShape_setFillColor(g->ui->planet_card->r_h_2_o, \
    sfColor_fromRGB(177, 198, 170));
    sfRectangleShape_setFillColor(g->ui->planet_card->r_n, \
    sfColor_fromRGB(177, 198, 170));
    sfRectangleShape_setFillColor(g->ui->planet_card->r_n_2, \
    sfColor_fromRGB(177, 198, 170));
    sfRectangleShape_setPosition(g->ui->planet_card->r_o_2, \
    (sfVector2f){g->ship->viewrect.left + 429, g->ship->viewrect.top + 362});
    sfRectangleShape_setPosition(g->ui->planet_card->r_h, \
    (sfVector2f){g->ship->viewrect.left + 429, g->ship->viewrect.top + 447});
    sfRectangleShape_setPosition(g->ui->planet_card->r_h_2_o, \
    (sfVector2f){g->ship->viewrect.left + 429, g->ship->viewrect.top + 534});
    sfRectangleShape_setPosition(g->ui->planet_card->r_co_2, \
    (sfVector2f){g->ship->viewrect.left + 429, g->ship->viewrect.top + 620});
    sfRectangleShape_setPosition(g->ui->planet_card->r_n, \
    (sfVector2f){g->ship->viewrect.left + 429, g->ship->viewrect.top + 706});
    sfRectangleShape_setPosition(g->ui->planet_card->r_n_2, \
    (sfVector2f){g->ship->viewrect.left + 429, g->ship->viewrect.top + 787});
}