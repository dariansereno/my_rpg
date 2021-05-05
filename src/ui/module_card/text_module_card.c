/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** text_module_card
*/

#include "my_rpg.h"

void print_nb(st_global *g, list_planet pl)
{
    for (int i = 0; i < 4; i++) {
        sfText_setString(g->ressources[0].text, itoa(pl->planet.modules[i],
        g->nb_inv, 10));
        sfText_setCharacterSize(g->ressources[0].text, 40);
        sfText_setPosition(g->ressources[0].text, (sfVector2f){g->ship->
        viewrect.left + 1210, g->ship->viewrect.top + 490 + (i * 87)});
        sfRenderWindow_drawText(g->window->window, g->ressources[0].text, NULL);
    }
}

// void buy_apparence(st_global *g)
// {
//     switch (g->ui->module_card->pos_rect) {
//         // if buy de pos_rect == true alors buy en gris
//         case 1:
//             break;
//         case 2:
//             break;
//         case 3:
//             break;
//         case 4:
//             break;
//         default:
//             break;
//     }
// }

void text_title_credits_module_card(st_global *g, list_planet planets)
{
    sfText_setCharacterSize(g->ui->module_card->text, 64);
    sfText_setString(g->ui->module_card->text, create_planet_string(planets
    ->index));
    sfText_setPosition(g->ui->module_card->text, \
    (sfVector2f){g->ship->viewrect.left + 1189, g->ship->viewrect.top + 227});
    sfRenderWindow_drawText(g->window->window, g->ui->module_card->text, NULL);
    sfText_setString(g->ui->module_card->text, int_to_str_credits(g->money
    ->money));
    sfText_setPosition(g->ui->module_card->text, \
    (sfVector2f){g->ship->viewrect.left + 415, g->ship->viewrect.top + 285});
    sfRenderWindow_drawText(g->window->window, g->ui->module_card->text, NULL);
}

void text_price_module_card(st_global *g, list_planet pl)
{
    sfText_setCharacterSize(g->ui->module_card->text, 64);
    sfText_setString(g->ui->module_card->text, int_to_str_price(pl->
    planet.mod_price[0]));
    sfText_setPosition(g->ui->module_card->text, \
    (sfVector2f){g->ship->viewrect.left + 941, g->ship->viewrect.top + 466});
    sfRenderWindow_drawText(g->window->window, \
    g->ui->module_card->text, NULL);
    sfText_setString(g->ui->module_card->text, int_to_str_price(pl->
    planet.mod_price[1]));
    sfText_setPosition(g->ui->module_card->text, \
    (sfVector2f){g->ship->viewrect.left + 941, g->ship->viewrect.top + 552});
    sfRenderWindow_drawText(g->window->window, \
    g->ui->module_card->text, NULL);
    sfText_setString(g->ui->module_card->text, int_to_str_price(pl->
    planet.mod_price[2]));
    sfText_setPosition(g->ui->module_card->text, \
    (sfVector2f){g->ship->viewrect.left + 941, g->ship->viewrect.top + 637});
    sfRenderWindow_drawText(g->window->window, \
    g->ui->module_card->text, NULL);
    sfText_setString(g->ui->module_card->text, int_to_str_price(pl->
    planet.mod_price[3]));
    sfText_setPosition(g->ui->module_card->text, \
    (sfVector2f){g->ship->viewrect.left + 941, g->ship->viewrect.top + 726});
    sfRenderWindow_drawText(g->window->window, \
    g->ui->module_card->text, NULL);
}