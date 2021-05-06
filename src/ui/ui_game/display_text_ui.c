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
    left + 270, ad->ship->viewrect.top + 110});
    sfText_setString(ad->ressources[0].text, number_and_string(ad->ship->life, 
    "health: "));
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);

    sfText_setPosition(ad->ressources[0].text, (sfVector2f){ad->ship->viewrect.
    left + 270, ad->ship->viewrect.top + 130});
    sfText_setString(ad->ressources[0].text, number_and_string(ad->money->money, 
    "credits: "));
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);

    sfText_setPosition(ad->ressources[0].text, (sfVector2f){ad->ship->viewrect.
    left + 270, ad->ship->viewrect.top + 150});
    sfText_setString(ad->ressources[0].text, number_and_string(ad->ship->lvl, 
    "lvl: "));
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);
}