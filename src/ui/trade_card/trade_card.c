/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** trade_card
*/

#include "my_rpg.h"

void rect_trade_position(st_global *g)
{
    switch (g->ui->trade_card->pos_rect) {
        case 0:
            sfSprite_setPosition(g->ui->trade_card->ui[4]->sprite, (sfVector2f)\
            {388, 548});
            break;
        case 1:
            sfSprite_setPosition(g->ui->trade_card->ui[4]->sprite, (sfVector2f)\
            {388, 634});
            break;
        case 2:
            sfSprite_setPosition(g->ui->trade_card->ui[4]->sprite, (sfVector2f)\
            {388, 720});
            break;
        default:
            break;
    }
}

void set_init_position_trade(st_global *g)
{
    sfSprite_setPosition(g->ui->trade_card->ui[0]->sprite, \
    (sfVector2f){1422, 548});
    sfSprite_setPosition(g->ui->trade_card->ui[1]->sprite, \
    (sfVector2f){1422, 548});
    sfSprite_setPosition(g->ui->trade_card->ui[2]->sprite, \
    (sfVector2f){1422, 720});
    sfSprite_setPosition(g->ui->trade_card->ui[3]->sprite, \
    (sfVector2f){1422, 720});
    sfSprite_setPosition(g->ui->trade_card->ui[5]->sprite, \
    (sfVector2f){312, 167});
}

void display_trade_card(st_global *g)
{
    g->ui->trade_card->counter = 3;
    if (g->ui->trade_card->existing) {
        arrow_events_trade(g);
        set_init_position_trade(g);
        rect_trade_position(g);
        for (int i = 5; i >= 0; i--) {
            sfSprite_setPosition(g->ui->trade_card->ui[i]->sprite, (sfVector2f)\
            {sfSprite_getPosition(g->ui->trade_card->ui[i]->sprite).x +\
            g->ship->viewrect.left, \
            sfSprite_getPosition(g->ui->trade_card->ui[i]->sprite).y + \
            g->ship->viewrect.top});
        }
        sfRenderWindow_drawSprite(g->window->window, \
        g->ui->trade_card->ui[5]->sprite, \
        NULL);
        sfRenderWindow_drawSprite(g->window->window, \
        g->ui->trade_card->ui[4]->sprite, \
        NULL);
        display_planet_trade_card(g);
        arrow_texture(g);
    }
}

void display_planet_trade_card(st_global *g)
{
    list_planet planets = g->planets->planets;
    while (planets != NULL) {
        if (planets->interact == true && planets->planet.tradable == true) {
            sfSprite_setPosition(planets->planet.sprite, \
            (sfVector2f){g->ship->viewrect.left + 965, \
            g->ship->viewrect.top + 360});
            sfSprite_setScale(planets->planet.sprite, (sfVector2f){4, 4});
            sfRenderWindow_drawSprite(g->window->window, \
            planets->planet.sprite, NULL);
            display_texts_trade_card(g, planets);
            check_buy(g, planets);
        }
        planets = planets->next;
    }
}

void display_texts_trade_card(st_global *g, list_planet planets)
{
    int y = 555;
    int x = 490;

    text_title_credits_trade_card(g, planets);
    for (int i = 0; planets->trade[i]->price != -1; i++) {
        if (planets->trade[i]->nb > 0 && planets->trade[i]->nb <= 5) {
            sfText_setString(g->ui->trade_card->text, \
            int_to_str_price(planets->trade[i]->nb));
            sfText_setPosition(g->ui->trade_card->text, (sfVector2f)\
            {g->ship->viewrect.left + 683, g->ship->viewrect.top + y});
            item_position_trade_card_one(g, i, x, planets);
            item_position_trade_card_two(g, i, x, planets);
            item_position_trade_card_three(g, i, x, planets);
            sfRenderWindow_drawText(g->window->window, g->ui->trade_card->text,
            NULL);
        }
        items_placement_trade_card(g, i, y, planets);
        //ad->ressources[id + 1];
        y += 87;
    }
}