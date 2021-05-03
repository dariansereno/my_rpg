/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** ui_game
*/

#include "my_rpg.h"

void set_position_ui_game(st_global *g)
{
    sfSprite_setPosition(g->ui->ui->ui[0]->sprite, \
    (sfVector2f){217, 63});
    sfSprite_setPosition(g->ui->ui->ui[1]->sprite, \
    (sfVector2f){217, 77});
    sfSprite_setPosition(g->ui->ui->ui[2]->sprite, \
    (sfVector2f){217, 91});
    sfSprite_setPosition(g->ui->ui->ui[3]->sprite, \
    (sfVector2f){75, 41});
}

void display_ui_game(st_global *g)
{
    set_position_ui_game(g);
    for (int i = 0; i < 4; i++) {
        sfSprite_setPosition(g->ui->ui->ui[i]->sprite, (sfVector2f)
        {sfSprite_getPosition(g->ui->ui->ui[i]->sprite).x +\
        g->ship->viewrect.left, \
        sfSprite_getPosition(g->ui->ui->ui[i]->sprite).y + \
        g->ship->viewrect.top});
        sfRenderWindow_drawSprite(g->window->window, \
        g->ui->ui->ui[i]->sprite, \
        NULL);
    }
}
