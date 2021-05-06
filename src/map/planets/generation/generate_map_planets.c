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

int *generate_mod_price()
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
    st_planet_global *planets = my_malloc(sizeof(*planets));
    planets->planets = NULL;
    st_planet *stats = general_all_planets(pos, math.kmax);
    planets->textures = my_malloc(sizeof(*planets->textures));
    planets->textures = generates_planets_textures();
    planets->limit = init_limit_map();
    planets->col_lim = false;
    planets->gen_mod = my_malloc(sizeof(st_timer *));
    planets->health_mod = my_malloc(sizeof(st_timer *));
    planets->ext_mod = my_malloc(sizeof(st_timer *));
    planets->gen_mod->clock = sfClock_create();
    planets->health_mod->clock = sfClock_create();
    planets->ext_mod->clock = sfClock_create();
    selector_colonized_pl(planets);
    selector_quest_pl(planets);

    for (int i = 0; i < math.kmax; i++) {
        stats[i].pos = pos[i];
        stats[i].rect = (sfIntRect){0, 0, 48, 48};
        stats[i].ennemies = NULL;
        stats[i].mod_price = generate_mod_price();
        stats[i].modules = my_malloc(sizeof(int) * 4);
        stats[i].mul_housing = 1;
        for (int j = 0; j < 4; j++)
            stats[i].modules[j] = 0;
        if (stats[i].type < 7)
            stats[i].rect = (sfIntRect){0, 0, 64, 64};
        push_back_planet(&planets->planets, stats[i]);
    }
    set_texture_planets(&planets->planets, planets);
    printf("%d\n", size_list_planet(planets->planets));
    return (planets);
}