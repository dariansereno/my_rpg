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
    pop_back_planet(planets->planets);
    planets->planets = NULL;
    for (int i = 0; i < 32; i++)
        sfTexture_destroy(planets->textures[i]);
    sfSprite_destroy(planets->colonized_pl);
    sfClock_destroy(planets->com);
    sfClock_destroy(planets->extract);
    sfClock_destroy(planets->health_mod->clock);
    sfTexture_destroy(planets->texture_quest);
    for (int i = 0; i < 4; i++)
        sfVertexArray_destroy(planets->limit[i]);
    sfText_destroy(planets->mark);
    sfFont_destroy(planets->mark_font);
    sfSprite_destroy(planets->quest_pl);
    sfTexture_destroy(planets->texture_colonized);
}