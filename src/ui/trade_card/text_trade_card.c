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

void items_text_trade_card(st_global *g, int y)
{
    // switch (g->ressources) {
    //     case 0:
    //         sfText_setString(g->ui->trade_card->text, "ARDENT");
    //         break;
    //     case 1:
    //         sfText_setString(g->ui->trade_card->text, "WARM");
    //         break;
    //     case 2:
    //         sfText_setString(g->ui->trade_card->text, "NORMAL");
    //         break;
    //     case 3:
    //         sfText_setString(g->ui->trade_card->text, "COLD");
    //         break;
    //     case 4:
    //         sfText_setString(g->ui->trade_card->text, "FROSTEN");
    //         break;
    // }
    // sfText_setPosition(g->ui->trade_card->text, \
    (sfVector2f){g->ship->viewrect.left + 382, g->ship->viewrect.top + y});
    // sfRenderWindow_drawText(g->window->window, g->ui->trade_card->text, NULL);
}

void text_title_credits_trade_card(st_global *g, list_planet planets)
{
    sfText_setCharacterSize(g->ui->trade_card->text, 64);
    sfText_setString(g->ui->trade_card->text, create_planet_string(planets->index));
    sfText_setPosition(g->ui->trade_card->text, \
    (sfVector2f){g->ship->viewrect.left + 1189, g->ship->viewrect.top + 227});
    sfRenderWindow_drawText(g->window->window, g->ui->trade_card->text, NULL);
    sfText_setString(g->ui->trade_card->text, int_to_str_credits(99999999));
    sfText_setPosition(g->ui->trade_card->text, \
    (sfVector2f){g->ship->viewrect.left + 415, g->ship->viewrect.top + 285});
    sfRenderWindow_drawText(g->window->window, g->ui->trade_card->text, NULL);
}