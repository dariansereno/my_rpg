/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** display_inventory
*/

#include "my_rpg.h"

void display_item(st_global *ad, st_ressources item, sfVector2f pos)
{
    sfSprite_setPosition(ad->items[item.id]->sprite, pos);
    sfText_setString(item.text, itoa(item.nb, ad->nb_inv, 10));
    sfText_setFillColor(item.text, sfWhite);
    sfText_setCharacterSize(item.text, 25);
    sfText_setPosition(item.text, (sfVector2f){pos.x + 25 + ((item.id - 4) * -1) * 3, pos.y + 20});
    sfRenderWindow_drawSprite(ad->window->window, ad->items[item.id]->sprite,
    NULL);
    sfRenderWindow_drawText(ad->window->window, item.text, NULL);
    return;
}

void display_items_inventory(st_global *ad)
{
    for (int i = 0; i < 4; i++) {
        display_item(ad, ad->ressources[i], (sfVector2f){
            ad->ship->viewrect.left + 870 + (i * 70), ad->ship->viewrect.top + 1010});
    }
}