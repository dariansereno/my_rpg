/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** planet_card
*/

#include "my_rpg.h"

void display_planet_card(st_global *g)
{
    if (g->ui->planet_card->existing == sfTrue)
        sfRenderWindow_drawSprite(g->window->window, g->ui->planet_card->mockup_s, NULL);
}