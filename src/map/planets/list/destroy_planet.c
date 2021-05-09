/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** destroy_planet
*/

#include "my_rpg.h"

void destroy_planet(list_planet pl)
{
    sfClock_destroy(pl->move.clock);
    destroy_ennemies_list(&pl->planet.ennemies);
    sfSprite_destroy(pl->planet.sprite);
    sfClock_destroy(pl->spawning.clock);
    sfClock_destroy(pl->timer.clock);
}