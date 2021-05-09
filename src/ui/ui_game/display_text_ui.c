/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** display_text_ui
*/

#include "my_rpg.h"

void display_lvl(st_global *ad)
{
    sfText_setPosition(ad->ressources[0].text, (sfVector2f){ad->ship->viewrect.
    left + 270 + 100, ad->ship->viewrect.top + 110});
    sfText_setString(ad->ressources[0].text, number_and_string( \
    ad->var_game->life,  "health: "));
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);
    sfText_setPosition(ad->ressources[0].text, (sfVector2f){ad->ship->viewrect.
    left + 270 + 100, ad->ship->viewrect.top + 130});
    sfText_setString(ad->ressources[0].text, number_and_string(ad->money->money,
    "credits: "));
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);
    sfText_setPosition(ad->ressources[0].text, (sfVector2f){ad->ship->viewrect.
    left + 270 + 100, ad->ship->viewrect.top + 150});
    sfText_setString(ad->ressources[0].text, number_and_string( \
    ad->var_game->lvl,  "lvl: "));
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);
}

void set_position_ui_game(st_global *g)
{
    sfRectangleShape_setPosition(g->ui->ui->life,
    (sfVector2f){217 + 100, 63});
    sfRectangleShape_setPosition(g->ui->ui->credits,
    (sfVector2f){217 + 100, 77});
    sfRectangleShape_setPosition(g->ui->ui->xp, (sfVector2f){217 + 100, 93});
    sfRectangleShape_setPosition(g->ui->ui->life_outline,
    (sfVector2f){217 + 100, 63});
    sfRectangleShape_setPosition(g->ui->ui->credits_outline,
    (sfVector2f){217 + 100, 77});
    sfRectangleShape_setPosition(g->ui->ui->xp_outline,
    (sfVector2f){217 + 100, 91});
    sfSprite_setPosition(g->ui->ui->map->sprite, (sfVector2f){75 + 100, 41});
    sfSprite_setPosition(g->ui->ui->craft[0]->sprite, (sfVector2f){1685, 0});
    sfSprite_setPosition(g->ui->ui->craft[1]->sprite, (sfVector2f){1758, 123});
    sfSprite_setPosition(g->ui->ui->item->sprite,
    (sfVector2f){751 + ((417 / 2) / 2), 944 + 53});
    rectangle_display_ui_game(g);
    item_craft_ui_game(g);
}