/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** item_position_trade_card
*/

#include "my_rpg.h"

void item_position_trade_card_one(st_global *g, int i, int x, list_planet planets)
{
    if (planets->trade[i]->id == 1 && i == 0) {
        sfSprite_setPosition(g->items[1]->sprite, (sfVector2f)
        {g->ship->viewrect.left + x, g->ship->viewrect.top + 565});
        sfSprite_setScale(g->items[1]->sprite, (sfVector2f){2, 2});
        sfRenderWindow_drawSprite(g->window->window, g->items[1]->sprite, NULL);
    }
    if (planets->trade[i]->id == 1 && i == 1) {
        sfSprite_setPosition(g->items[1]->sprite, (sfVector2f)
        {g->ship->viewrect.left + x, g->ship->viewrect.top + 650});
        sfSprite_setScale(g->items[1]->sprite, (sfVector2f){2, 2});
        sfRenderWindow_drawSprite(g->window->window, g->items[1]->sprite, NULL);
    }
    if (planets->trade[i]->id == 1 && i == 2) {
        sfSprite_setPosition(g->items[1]->sprite, (sfVector2f)
        {g->ship->viewrect.left + x, g->ship->viewrect.top + 735});
        sfSprite_setScale(g->items[1]->sprite, (sfVector2f){2, 2});
        sfRenderWindow_drawSprite(g->window->window, g->items[1]->sprite, NULL);
    }
}

void item_position_trade_card_two(st_global *g, int i, int x, list_planet planets)
{
    if (planets->trade[i]->id == 2 && i == 0) {
        sfSprite_setPosition(g->items[2]->sprite, (sfVector2f)
        {g->ship->viewrect.left + x + 5, g->ship->viewrect.top + 565});
        sfSprite_setScale(g->items[2]->sprite, (sfVector2f){2, 2});
        sfRenderWindow_drawSprite(g->window->window, g->items[2]->sprite, NULL);
    }
    if (planets->trade[i]->id == 2 && i == 1) {
        sfSprite_setPosition(g->items[2]->sprite, (sfVector2f)
        {g->ship->viewrect.left + x + 5, g->ship->viewrect.top + 650});
        sfSprite_setScale(g->items[2]->sprite, (sfVector2f){2, 2});
        sfRenderWindow_drawSprite(g->window->window, g->items[2]->sprite, NULL);
    }
    if (planets->trade[i]->id == 2 && i == 2) {
        sfSprite_setPosition(g->items[2]->sprite, (sfVector2f)
        {g->ship->viewrect.left + x + 5, g->ship->viewrect.top + 735});
        sfSprite_setScale(g->items[2]->sprite, (sfVector2f){2, 2});
        sfRenderWindow_drawSprite(g->window->window, g->items[2]->sprite, NULL);
    }
}

void item_position_trade_card_three(st_global *g, int i, int x, list_planet planets)
{
    if (planets->trade[i]->id == 0 && i == 0) {
        sfSprite_setPosition(g->items[0]->sprite, (sfVector2f)
        {g->ship->viewrect.left + x - 5, g->ship->viewrect.top + 565});
        sfSprite_setScale(g->items[0]->sprite, (sfVector2f){0.4, 0.4});
        sfRenderWindow_drawSprite(g->window->window, g->items[0]->sprite, NULL);
    }
    if (planets->trade[i]->id == 0 && i == 1) {
        sfSprite_setPosition(g->items[0]->sprite, (sfVector2f)
        {g->ship->viewrect.left + x - 5, g->ship->viewrect.top + 650});
        sfSprite_setScale(g->items[0]->sprite, (sfVector2f){0.4, 0.4});
        sfRenderWindow_drawSprite(g->window->window, g->items[0]->sprite, NULL);
    }
    if (planets->trade[i]->id == 0 && i == 2) {
        sfSprite_setPosition(g->items[0]->sprite, (sfVector2f)
        {g->ship->viewrect.left + x - 5, g->ship->viewrect.top + 745});
        sfSprite_setScale(g->items[0]->sprite, (sfVector2f){0.4, 0.4});
        sfRenderWindow_drawSprite(g->window->window, g->items[0]->sprite, NULL);
    }
}

void items_placement_trade_card(st_global *g, int i, int y, list_planet planets)
{
    sfSprite_setScale(g->items[1]->sprite, (sfVector2f){1, 1});
    sfSprite_setScale(g->items[0]->sprite, (sfVector2f){0.22, 0.22});
    sfSprite_setScale(g->items[2]->sprite, (sfVector2f){1.1, 1.1});
    if (planets->trade[i]->nb != 0 && (planets->trade[i]->price >= 20 \
    && planets->trade[i]->price <= 100)) {
        sfText_setString(g->ui->trade_card->text, \
        int_to_str_price(planets->trade[i]->price));
        sfText_setPosition(g->ui->trade_card->text, \
    (sfVector2f){g->ship->viewrect.left + 945, g->ship->viewrect.top + y});
    sfRenderWindow_drawText(g->window->window, \
    g->ui->trade_card->text, NULL);
    }
}