/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** text_trade_card
*/

#include "my_rpg.h"

char *int_to_str_credits(int money)
{
    char *credits = my_malloc(sizeof(char) * 8);
    char *nb = NULL;
    int j = 0;

    for (int i = 0; i < 7; i++)
        credits[i] = 'o';
    if (money > 9999999) {
        for (int i = 0; i < 7; i++)
            credits[i] = '9';
    }
    else {
        nb = int_to_str(money);
        j = my_strlen(nb) - 1;
        for (int i = 0; i < my_strlen(nb); i++)
            credits[i] = nb[j--];
    }
    credits[7] = 0;
    return (my_revstr(credits));
}

char *int_to_str_price(int money)
{
    char *credits = my_malloc(sizeof(char) * 5);
    char *nb = NULL;
    int j = 0;

    for (int i = 0; i < 4; i++)
        credits[i] = 'o';
    if (money > 9999) {
        for (int i = 0; i < 4; i++)
            credits[i] = '9';
    }
    else {
        nb = int_to_str(money);
        j = my_strlen(nb) - 1;
        for (int i = 0; i < my_strlen(nb); i++)
            credits[i] = nb[j--];
    }
    credits[4] = 0;
    return (my_revstr(credits));
}

void text_title_credits_trade_card(st_global *g, list_planet planets)
{
    sfText_setCharacterSize(g->ui->trade_card->text, 64);
    sfText_setString(g->ui->trade_card->text,
    create_planet_string(planets->index));
    sfText_setPosition(g->ui->trade_card->text, \
    (sfVector2f){g->ship->viewrect.left + 1189, g->ship->viewrect.top + 227});
    sfRenderWindow_drawText(g->window->window, g->ui->trade_card->text, NULL);
    sfText_setString(g->ui->trade_card->text, int_to_str_credits(g->money->money
    ));
    sfText_setPosition(g->ui->trade_card->text, \
    (sfVector2f){g->ship->viewrect.left + 415, g->ship->viewrect.top + 285});
    sfRenderWindow_drawText(g->window->window, g->ui->trade_card->text, NULL);
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
        check_buy_bis(g, planets);
    }
}

void check_buy_bis(st_global *g, list_planet planets)
{
    if (g->ui->trade_card->pos_rect == 2 && g->money->money >= 
    planets->trade[2]->price && planets->trade[2]->nb > 0) {
        g->money->money = g->money->money - planets->trade[2]->price;
        g->ressources[planets->trade[2]->id].nb++;
        planets->trade[2]->nb--;
        g->key_pressed.Enter = false;
    }
}