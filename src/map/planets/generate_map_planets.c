/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_map
*/

#include "my_rpg.h"

st_planet_global *generate_all_map(void)
{
    scatter math = {.germ = 469880, .interval = 50000, .kmax = 400, .p = 1288,
    .q = 1664713};
    sfVector2i *pos = scatter_plot(math);
    st_planet_global *planets = malloc(sizeof(st_planet_global *));
    planets->planets = NULL;
    st_planet *stats = general_all_planets(pos, math.kmax);
    planets->textures = malloc(sizeof(*planets->textures));
    planets->textures = generates_planets_textures();

    for (int i = 0; i < math.kmax; i++) {
        stats[i].pos = pos[i];
        stats[i].rect = (sfIntRect){0, 0, 48, 48};
        push_back_planet(&planets->planets, stats[i]);
    }
    set_texture_planets(&planets->planets, planets);
    return (planets);
}