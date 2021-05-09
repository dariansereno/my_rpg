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

void selector_colonized_pl(st_planet_global *planets)
{
    planets->texture_colonized = sfTexture_createFromFile( \
    "contents/img/sp/colonised.png", NULL);
    planets->colonized_pl = sfSprite_create();

    sfSprite_setTexture(planets->colonized_pl, \
    planets->texture_colonized , sfTrue);
    sfSprite_setOrigin(planets->colonized_pl, (sfVector2f){26, 26});
}

void selector_quest_pl(st_planet_global *planets)
{
    planets->texture_quest = sfTexture_createFromFile( \
    "contents/img/sp/quest.png", NULL);
    planets->quest_pl = sfSprite_create();

    sfSprite_setTexture(planets->quest_pl, \
    planets->texture_quest , sfTrue);
    sfSprite_setOrigin(planets->quest_pl, (sfVector2f){26, 26});
}

int *generate_mod_price(void)
{
    int *mod_price = my_malloc(sizeof(int) * 4);

    mod_price[0] = 600;
    mod_price[1] = 400;
    mod_price[2] = 600;
    mod_price[3] = 800;
    return (mod_price);
}

st_planet_global *generate_all_map(void)
{
    scatter math = {.germ = 469880, .interval = 80000, .kmax =
    random_between(2000, 2500), .p = 1288, .q = 1664713};
    sfVector2i *pos = scatter_plot(math);
    st_planet_global *planets = generate_planet_global();
    selector_quest_pl(planets);

    generate_list_planets(planets, math, pos);
    set_texture_planets(&planets->planets, planets);
    return (planets);
}