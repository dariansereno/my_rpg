/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** ui_game
*/

#include "my_rpg.h"

void set_position_ui_game(st_global *g)
{
    sfRectangleShape_setPosition(g->ui->ui->life, (sfVector2f){217, 63});
    sfRectangleShape_setPosition(g->ui->ui->credits, (sfVector2f){217, 77});
    sfRectangleShape_setPosition(g->ui->ui->xp, (sfVector2f){217, 91});
    sfSprite_setPosition(g->ui->ui->map->sprite, \
    (sfVector2f){75, 41});
}

void display_ui_game(st_global *g)
{
    set_position_ui_game(g);
    rectangle_display_ui_game(g);
    sfRectangleShape_setSize(g->ui->ui->life, \
    (sfVector2f){g->ship->life * 263 / 200, 10});
    sfSprite_setPosition(g->ui->ui->map->sprite, (sfVector2f)
    {sfSprite_getPosition(g->ui->ui->map->sprite).x +\
    g->ship->viewrect.left, \
    sfSprite_getPosition(g->ui->ui->map->sprite).y + \
    g->ship->viewrect.top});
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->ui->map->sprite, \
    NULL);
    sfSprite_setPosition(g->ship->bship, \
    (sfVector2f){132 + g->ship->viewrect.left, 90 + g->ship->viewrect.top});
    // sfSprite_setScale(g->ship->bship, (sfVector2f))
    sfRenderWindow_drawSprite(g->window->window, g->ship->bship, NULL);
}

void rectangle_display_ui_game(st_global *g)
{
    sfRectangleShape_setPosition(g->ui->ui->life, (sfVector2f)\
    {sfRectangleShape_getPosition(g->ui->ui->life).x + g->ship->viewrect.left,
    sfRectangleShape_getPosition(g->ui->ui->life).y + g->ship->viewrect.top});
    sfRectangleShape_setPosition(g->ui->ui->credits, (sfVector2f)\
    {sfRectangleShape_getPosition(g->ui->ui->credits).x + \
    g->ship->viewrect.left, \
    sfRectangleShape_getPosition(g->ui->ui->credits).y + \
    g->ship->viewrect.top});
    sfRectangleShape_setPosition(g->ui->ui->xp, (sfVector2f)\
    {sfRectangleShape_getPosition(g->ui->ui->xp).x + g->ship->viewrect.left, \
    sfRectangleShape_getPosition(g->ui->ui->xp).y + g->ship->viewrect.top});
    sfRenderWindow_drawRectangleShape(g->window->window, g->ui->ui->life, NULL);
    sfRenderWindow_drawRectangleShape(g->window->window, \
    g->ui->ui->credits, NULL);
    sfRenderWindow_drawRectangleShape(g->window->window, g->ui->ui->xp, NULL);
}