/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_map
*/

#include "my_rpg.h"

sfTexture **generates_planets_textures()
{
    sfTexture **texture = malloc(sizeof(sfTexture *) * 34)
}

list_planet generate_all_map(void)
{
    scatter math = {.germ = 469880, .interval = 20000, .kmax = 250, .p = 1288,
    .q = 1664713};
    sfVector2i *pos = scatter_plot(math);
    list_planet planets = NULL;
    st_planet *stats = general_all_planets(pos, math.kmax);

    for (int i = 0; i < math.kmax; i++) {
        stats[i].pos = pos[i];
        push_back_planet(&planets, stats[i]);
    }
}