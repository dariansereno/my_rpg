/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** destroy_global_particle
*/

#include "my_rpg.h"

void destroy_global_particles(st_global_particle *g)
{
    sfCircleShape_destroy(g->circle);
    sfClock_destroy(g->clock);
    sfClock_destroy(g->generation);
    destroy_list_particle(&g->particles);
}