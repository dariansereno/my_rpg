/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** particle
*/

#include "my_rpg.h"

st_global_particle *generate_particle(void)
{
    st_global_particle *particle = my_malloc(sizeof(*particle));

    particle->clock = sfClock_create();
    particle->generation = sfClock_create();
    particle->circle = sfCircleShape_create();
    particle->particles = NULL;
    return (particle);
}

void add_particles(st_global *ad)
{
    sfTime time = sfClock_getElapsedTime(ad->particle->generation);
    float second = time.microseconds / 1000000.0;
    sfVector2f pos;

    if (second > 0.01) {
        pos.x = random_between(-50, 150) * 19.2 + ad->ship->viewrect.left;
        pos.y = random_between(-50, 150) * 10.8 + ad->ship->viewrect.top;
        push_back_particle(&ad->particle->particles, ad->particle, pos);
        sfClock_restart(ad->particle->generation);
    }
}