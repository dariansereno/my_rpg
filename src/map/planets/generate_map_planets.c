/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_map
*/

#include "my_rpg.h"

st_planet *general_all_planets_stat(sfVector2i *pos, int size)
{
    st_planet *planets = malloc(sizeof(st_planet) * size);
}

list_planet generate_all_map(void)
{
    scatter math = {.germ = 469880, .interval = 20000, .kmax = 250, .p = 1288,
    .q = 1664713};
    sfVector2i *pos = scatter_plot(math);
    list_planet planets = NULL;

    for (int i = 0; i < math.kmax; i++)
        push_back_planet(&planets, (st_planet){.pos = pos[i]});
}