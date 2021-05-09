/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** destroy_ship
*/

#include "my_rpg.h"

void destroy_ship(ship_t *ship)
{
    sfSprite_destroy(ship->bship);
    sfTexture_destroy(ship->bshipt);
    sfClock_destroy(ship->reload->clock);
    sfView_destroy(ship->view);
}

void destroy_spaceobj(st_global_spaceobj *obj)
{
    for (int i = 0; i < 16; i++) {
        sfTexture_destroy(obj->textures[i]);
    }
}