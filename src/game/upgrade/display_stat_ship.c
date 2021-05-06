/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** display_stat_ship
*/

#include "my_rpg.h"

void display_stats_ship(st_global *ad)
{
    sfText_setPosition(ad->ressources[0].text, (sfVector2f){ad->ship->viewrect \
    .left + 36, ad->ship->viewrect.top + 45});
    sfText_setString(ad->ressources[0].text, number_and_string( \
    ad->upgrade->upgrade_tab[0], "Lasers lvl: "));
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);
    sfText_setPosition(ad->ressources[0].text, (sfVector2f){ad->ship->viewrect \
    .left + 20, ad->ship->viewrect.top + 90});
    sfText_setString(ad->ressources[0].text, number_and_string( \
    ad->upgrade->upgrade_tab[1], "Range lvl: "));
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);
    sfText_setPosition(ad->ressources[0].text, (sfVector2f){ad->ship->viewrect \
    .left + 24, ad->ship->viewrect.top + 135});
    sfText_setString(ad->ressources[0].text, number_and_string( \
    ad->upgrade->upgrade_tab[2], "Speed lvl: "));
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);
    sfText_setPosition(ad->ressources[0].text, (sfVector2f){ad->ship->viewrect \
    .left + 36, ad->ship->viewrect.top + 180});
    sfText_setString(ad->ressources[0].text, number_and_string( \
    ad->upgrade->upgrade_tab[3], "Health lvl: "));
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);
}