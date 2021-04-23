/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** destroy_global_planets
*/

#include "my_rpg.h"

void destroy_global_planet(st_planet_global *planets)
{
    while (planets->planets->next != NULL)
        pop_back_planet(planets->planets);
    destroy_planet(planets->planets);
    planets->planets = NULL;
    for (int i = 0; i < 32; i++)
        sfTexture_destroy(planets->textures[i]);
}

void destroy_planet(list_elem_planet *planet)
{
    sfClock_destroy(planet->timer.clock);
    sfSprite_destroy(planet->planet.sprite);
}