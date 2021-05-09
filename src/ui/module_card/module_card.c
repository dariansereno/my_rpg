/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** module_card
*/

#include "my_rpg.h"

void rect_module_position(st_global *g)
{
    switch (g->ui->module_card->pos_rect) {
        case 1:
            sfSprite_setPosition(g->ui->module_card->ui[1]->sprite, (sfVector2f)\
            {388, 469});
            break;
        case 2:
            sfSprite_setPosition(g->ui->module_card->ui[1]->sprite, (sfVector2f)\
            {388, 556});
            break;
        case 3:
            sfSprite_setPosition(g->ui->module_card->ui[1]->sprite, (sfVector2f)\
            {388, 641});
            break;
        case 4:
            sfSprite_setPosition(g->ui->module_card->ui[1]->sprite, (sfVector2f)\
            {388, 727});
            break;
        default:
            break;
    }
}

void set_init_position_module(st_global *g)
{
    sfSprite_setPosition(g->ui->module_card->ui[0]->sprite, \
    (sfVector2f){1192, 497});
    sfSprite_setPosition(g->ui->module_card->ui[2]->sprite, \
    (sfVector2f){312, 167});
}

void display_module_card(st_global *g)
{
    if (g->ui->module_card->existing && g->ui->end->existing == false) {
        arrow_events_module(g);
        set_init_position_module(g);
        rect_module_position(g);
        for (int i = 2; i >= 1; i--) {
            sfSprite_setPosition(g->ui->module_card->ui[i]->sprite, (sfVector2f)
            {sfSprite_getPosition(g->ui->module_card->ui[i]->sprite).x +\
            g->ship->viewrect.left, \
            sfSprite_getPosition(g->ui->module_card->ui[i]->sprite).y + \
            g->ship->viewrect.top});
            sfRenderWindow_drawSprite(g->window->window, \
            g->ui->module_card->ui[i]->sprite, \
            NULL);
        }
        display_planet_module_card(g);
    }
}

void display_planet_module_card(st_global *g)
{
    list_planet planets = g->planets->planets;

    while (planets != NULL) {
        if (planets->interact == true) {
            buy_module(g, planets);
            sfSprite_setPosition(planets->planet.sprite, \
            (sfVector2f){g->ship->viewrect.left + 965, \
            g->ship->viewrect.top + 330});
            sfSprite_setScale(planets->planet.sprite, (sfVector2f){3, 3});
            sfRenderWindow_drawSprite(g->window->window, \
            planets->planet.sprite, NULL);
            display_texts_module_card(g, planets);
        }
        planets = planets->next;
    }
}

void display_texts_module_card(st_global *g, list_planet planets)
{
    print_nb(g, planets);
    text_title_credits_module_card(g, planets);
    text_price_module_card(g, planets);
    sfText_setCharacterSize(g->ui->module_card->text, 40);
    sfText_setString(g->ui->module_card->text, "Housing Module");
    sfText_setPosition(g->ui->module_card->text, \
    (sfVector2f){g->ship->viewrect.left + 417, g->ship->viewrect.top + 489});
    sfRenderWindow_drawText(g->window->window, \
    g->ui->module_card->text, NULL);
    sfText_setString(g->ui->module_card->text, "Trading Module");
    sfText_setPosition(g->ui->module_card->text, \
    (sfVector2f){g->ship->viewrect.left + 417, g->ship->viewrect.top + 574});
    sfRenderWindow_drawText(g->window->window, \
    g->ui->module_card->text, NULL);
    display_texts_module_card_bis(g);
}