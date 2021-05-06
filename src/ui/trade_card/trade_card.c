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
    // count_items();
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
            sfText_setString(g->ui->trade_card->text, int_to_str_price(planets->trade[i]->nb)); // -> quantité
            sfText_setPosition(g->ui->trade_card->text, \
            (sfVector2f){g->ship->viewrect.left + 683, g->ship->viewrect.top + y});
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
            sfRenderWindow_drawText(g->window->window, g->ui->trade_card->text, NULL);
        }
        sfSprite_setScale(g->items[1]->sprite, (sfVector2f){1, 1});
        sfSprite_setScale(g->items[0]->sprite, (sfVector2f){0.22, 0.22});
        sfSprite_setScale(g->items[2]->sprite, (sfVector2f){1.1, 1.1});
        if (planets->trade[i]->nb != 0 && (planets->trade[i]->price >= 20 && planets->trade[i]->price <= 100)) {
            sfText_setString(g->ui->trade_card->text, int_to_str_price(planets->trade[i]->price)); // -> prix
            sfText_setPosition(g->ui->trade_card->text, \
        (sfVector2f){g->ship->viewrect.left + 945, g->ship->viewrect.top + y});
        sfRenderWindow_drawText(g->window->window, \
        g->ui->trade_card->text, NULL);
        //sfRenderWindow_drawSprite(g->window->window, g->items[planets->trade[i]->id + 1], NULL);
        }
        //ad->ressources[id + 1];
        // récupérer les prix de l'index + les items (si ils existent)
        // items_text_trade_card(g, y);
        y += 87;
    }
}

void check_buy(st_global *g, list_planet planets)
{
    if (g->key_pressed.Enter == true) {
        if (g->ui->trade_card->pos_rect == 0 && g->money->money >= 
        planets->trade[0]->price && planets->trade[0]->nb > 0) {
            g->money->money = g->money->money - planets->trade[0]->price;
            g->ressources[planets->trade[0]->id].nb++;
            planets->trade[0]->nb--;
            g->key_pressed.Enter = false;
        }
        if (g->ui->trade_card->pos_rect == 1 && g->money->money >= 
        planets->trade[1]->price && planets->trade[1]->nb > 0) {
            g->money->money = g->money->money - planets->trade[1]->price;
            g->ressources[planets->trade[1]->id].nb++;
            planets->trade[1]->nb--;
            g->key_pressed.Enter = false;
        }
        if (g->ui->trade_card->pos_rect == 2 && g->money->money >= 
        planets->trade[2]->price && planets->trade[2]->nb > 0) {
            g->money->money = g->money->money - planets->trade[2]->price;
            g->ressources[planets->trade[2]->id].nb++;
            planets->trade[2]->nb--;
            g->key_pressed.Enter = false;
        }
    }
}