/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** ui_game
*/

#include "my_rpg.h"

void print_craftable(st_global *g, int i)
{
    sfSprite_setPosition(g->ui->ui->craft[i]->sprite, (sfVector2f)
    {sfSprite_getPosition(g->ui->ui->craft[i]->sprite).x +\
    g->ship->viewrect.left - 10, \
    sfSprite_getPosition(g->ui->ui->craft[i]->sprite).y + \
    g->ship->viewrect.top + 10 + 890});
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->ui->craft[i]->sprite, \
    NULL);
    sfSprite_setPosition(g->items[3]->sprite, (sfVector2f)
    {g->ship->viewrect.left + 1776, g->ship->viewrect.top + 77 + 890});
    sfRenderWindow_drawSprite(g->window->window, g->items[3]->sprite,
    NULL);
    sfText_setString(g->ressources[0].text, "press j");
    sfText_setPosition(g->ressources[0].text, (sfVector2f)
    {g->ship->viewrect.left + 1755, g->ship->viewrect.top + 130 + 890});
    sfText_setCharacterSize(g->ressources[0].text, 23);
    sfRenderWindow_drawText(g->window->window, g->ressources[0].text,
    NULL);
}

void item_craft_ui_game(st_global *g)
{
    sfSprite_setPosition(g->ui->ui->item->sprite, (sfVector2f)
    {sfSprite_getPosition(g->ui->ui->item->sprite).x +\
    g->ship->viewrect.left, \
    sfSprite_getPosition(g->ui->ui->item->sprite).y + \
    g->ship->viewrect.top});
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->ui->item->sprite, \
    NULL);
    sfSprite_setScale(g->ui->ui->item->sprite, (sfVector2f){0.5, 0.5});
    if (g->var_game->craft) {
        for (int i = 0; i < 2; i++)
            print_craftable(g, i);
    }
    display_lvl(g);
}

void display_ui_game(st_global *g)
{
    set_position_ui_game(g);
    sfRectangleShape_setSize(g->ui->ui->life, \
    (sfVector2f){g->var_game->life * 263 / g->var_game->max_health, 8});
    sfRectangleShape_setSize(g->ui->ui->credits, \
    (sfVector2f){g->money->money * 263 / 10000, 8});
    sfRectangleShape_setSize(g->ui->ui->xp, \
    (sfVector2f){g->var_game->xp * 263 / g->var_game->max_xp, 8});
    sfSprite_setPosition(g->ui->ui->map->sprite, (sfVector2f)
    {sfSprite_getPosition(g->ui->ui->map->sprite).x +\
    g->ship->viewrect.left, \
    sfSprite_getPosition(g->ui->ui->map->sprite).y + \
    g->ship->viewrect.top});
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->ui->map->sprite, NULL);
    sfSprite_setPosition(g->ship->bship, \
    (sfVector2f){163 + g->ship->viewrect.left + 100, 125 + \
    g->ship->viewrect.top});
    sfSprite_setScale(g->ship->bship, (sfVector2f){2, 2});
    sfRenderWindow_drawSprite(g->window->window, g->ship->bship, NULL);
    sfSprite_setScale(g->ship->bship, (sfVector2f){1, 1});
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
    sfRectangleShape_setPosition(g->ui->ui->life_outline, (sfVector2f)\
    {sfRectangleShape_getPosition(g->ui->ui->life_outline).x + \
    g->ship->viewrect.left,
    sfRectangleShape_getPosition(g->ui->ui->life_outline).y + \
    g->ship->viewrect.top});
    rectangle_display_ui_game_bis(g);
}

void rectangle_display_ui_game_bis(st_global *g)
{
    sfRectangleShape_setPosition(g->ui->ui->credits_outline, (sfVector2f)\
    {sfRectangleShape_getPosition(g->ui->ui->credits_outline).x + \
    g->ship->viewrect.left, \
    sfRectangleShape_getPosition(g->ui->ui->credits_outline).y + \
    g->ship->viewrect.top});
    sfRectangleShape_setPosition(g->ui->ui->xp_outline, (sfVector2f)\
    {sfRectangleShape_getPosition(g->ui->ui->xp_outline).x + \
    g->ship->viewrect.left, \
    sfRectangleShape_getPosition(g->ui->ui->xp_outline).y + \
    g->ship->viewrect.top});
    sfRenderWindow_drawRectangleShape(g->window->window, \
    g->ui->ui->life_outline, NULL);
    sfRenderWindow_drawRectangleShape(g->window->window, \
    g->ui->ui->credits_outline, NULL);
    sfRenderWindow_drawRectangleShape(g->window->window, \
    g->ui->ui->xp_outline, NULL);
    sfRenderWindow_drawRectangleShape(g->window->window, g->ui->ui->life, NULL);
    sfRenderWindow_drawRectangleShape(g->window->window, \
    g->ui->ui->credits, NULL);
    sfRenderWindow_drawRectangleShape(g->window->window, g->ui->ui->xp, NULL);
}