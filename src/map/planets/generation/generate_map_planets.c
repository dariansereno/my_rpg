/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_map
*/

#include "my_rpg.h"

planet_kind generate_kind(int type)
{
    if (type >= 0 && type <= 6)
        return (SUN);
    if (type >= 7 && type <= 9)
        return (LAVA);
    if (type >= 10 && type <= 13)
        return (GAS);
    if (type == 14 || type == 15)
        return (OCEAN);
    if (type >= 16 && type <= 19)
        return (TERRAN);
    if (type == 20)
        return (ICEP);
    if (type >= 21 && type <= 23)
        return (TECH);
    if (type >= 24 && type <= 28)
        return (ASTEROID);
    if (type >= 29)
        return (BLACKHOLE);
    return (TERRAN);
}

st_planet_global *generate_all_map(void)
{
    scatter math = {.germ = 469880, .interval = 50000, .kmax =
    random_between(400, 800), .p = 1288, .q = 1664713};
    sfVector2i *pos = scatter_plot(math);
    st_planet_global *planets = my_malloc(sizeof(*planets));
    planets->planets = NULL;
    st_planet *stats = general_all_planets(pos, math.kmax);
    planets->textures = my_malloc(sizeof(*planets->textures));
    planets->textures = generates_planets_textures();

    for (int i = 0; i < math.kmax; i++) {
        stats[i].pos = pos[i];
        stats[i].rect = (sfIntRect){0, 0, 48, 48};
        stats[i].ennemies = NULL;
        if (stats[i].type < 7)
            stats[i].rect = (sfIntRect){0, 0, 64, 64};
        push_back_planet(&planets->planets, stats[i]);
    }
    set_texture_planets(&planets->planets, planets);
    return (planets);
}