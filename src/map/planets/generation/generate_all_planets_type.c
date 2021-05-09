/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_all_planets_type
*/

#include "my_rpg.h"

st_planet *generate_all_planets_3(sfVector2i *pos, int size, st_planet *planets)
{
    for (int i = (size / 8) * 6; i < size; i++) {
        planets[i].type = random_between(21, 23);
        planets[i].climate = climate_from_type(planets[i].type);
        planets[i].animated = animation_from_type(planets[i].type);
        planets[i].stats = generate_planet_stat(planets[i]);
        planets[i].kind = generate_kind(planets[i].type);
        planets[i].tradable = false;
        planets[i].colonized = false;
        planets[i].quest = false;
    }
    return (planets);
}

st_planet *generate_all_planets_2(sfVector2i *pos, int size, st_planet *planets)
{
    for (int i = (size / 8) * 4 ; i < (size / 8) * 6; i++) {
        planets[i].type = random_between(16, 19);
        planets[i].climate = climate_from_type(planets[i].type);
        planets[i].animated = animation_from_type(planets[i].type);
        planets[i].stats = generate_planet_stat(planets[i]);
        planets[i].kind = generate_kind(planets[i].type);
        planets[i].tradable = random_between(0, 1);
        planets[i].colonized = false;
        planets[i].quest = false;
    }
    return (generate_all_planets_3(pos, size, planets));
}

st_planet *general_all_planets(sfVector2i *pos, int size)
{
    st_planet *planets = my_malloc(sizeof(st_planet) * size);

    for (int i = 0; i  < (size / 8) * 4; i++) {
        planets[i].type = random_between(0, 31);
        planets[i].climate = climate_from_type(planets[i].type);
        planets[i].animated = animation_from_type(planets[i].type);
        planets[i].stats = generate_planet_stat(planets[i]);
        planets[i].kind = generate_kind(planets[i].type);
        if (planets[i].type >= 7 && planets[i].type <= 20)
            planets[i].tradable = random_between(0, 1);
        else
            planets[i].tradable = false;
        planets[i].colonized = false;
        planets[i].quest = false;
    }
    planets = generate_all_planets_2(pos, size, planets);
    return (planets);
}

st_planet_global *generate_planet_global(void)
{
    st_planet_global *planets = my_malloc(sizeof(*planets));

    planets->planets = NULL;
    planets->textures = my_malloc(sizeof(*planets->textures));
    planets->textures = generates_planets_textures();
    planets->limit = init_limit_map();
    planets->col_lim = false;
    planets->gen_mod = my_malloc(sizeof(st_timer *));
    planets->com = sfClock_create();
    planets->extract = sfClock_create();
    planets->health_mod = my_malloc(sizeof(st_timer *));
    planets->ext_mod = my_malloc(sizeof(st_timer *));
    planets->gen_mod->clock = sfClock_create();
    planets->health_mod->clock = sfClock_create();
    planets->ext_mod->clock = sfClock_create();
    planets->mark_font = sfFont_createFromFile("contents/fonts/ex.ttf");
    planets->mark = sfText_create();
    sfText_setFont(planets->mark, planets->mark_font);
    selector_colonized_pl(planets);
    return (planets);
}

void *generate_list_planets(st_planet_global *planets, scatter math,
sfVector2i *pos)
{
    st_planet *stats = general_all_planets(pos, math.kmax);

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
}