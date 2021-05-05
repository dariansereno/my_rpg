/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** display_on_screen
*/

#include "my_rpg.h"

void display_on_view_spaceobj(st_global *ad)
{
    list_spaceobj obj = ad->space_obj->li;

    while (obj != NULL) {
        if (obj->pos.x >= ad->ship->viewrect.left - 1200 &&
        obj->pos.x <= ad->ship->viewrect.left + 1920 + 1200
        && obj->pos.y >= ad->ship->viewrect.top - 1200 &&
        obj->pos.y <= ad->ship->viewrect.top + 1080 + 1200)
            obj->on_screen = true;
        else
            obj->on_screen = false;
        obj = obj->next;
    }
}