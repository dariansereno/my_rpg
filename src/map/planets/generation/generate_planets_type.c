/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_planets
*/

#include "my_rpg.h"

st_planet_stat generate_planet_stat2(st_planet planet)
{
    int i = 6;
    switch (i) {
    case 6: if (planet.type >= 21 && planet.type <= 23)
                return (stats_for_tech(planet.stats));
            i++;
    case 7: if (planet.type == 20)
                return (stats_for_ice(planet.stats));
            i++;
    case 8: if (planet.type >= 24 && planet.type <= 28)
                return (stats_for_asteroid(planet.stats));
            i++;
    case 9: if (planet.type >= 29)
                return (stats_for_blackhole(planet.stats));
            i++;
    }
    return (planet.stats);
}

st_planet_stat generate_planet_stat(st_planet planet)
{
    int i = 1;
    planet.stats = (st_planet_stat){0, 0, 0, 0, 0, 0, 0};

    switch (i) {
    case 1: if (planet.type >= 0 && planet.type <= 6)
                return (stats_for_sun(planet.stats));
            i++;
    case 2: if (planet.type >= 7 && planet.type <= 9)
                return (stats_for_lava(planet.stats));
            i++;
    case 3: if (planet.type >= 10 && planet.type <= 13)
                return (stats_for_gas(planet.stats));
            i++;
    case 4: if (planet.type >= 14 && planet.type <= 15)
                return (stats_for_ocean(planet.stats));
            i++;
    case 5: if (planet.type >= 16 && planet.type <= 19)
                return (stats_for_terran(planet.stats));
            i++;
    }
    return (generate_planet_stat2(planet));
}

planet_climate climate_from_type(planet_type planet)
{
    int i = 1;

    switch (i) {
    case 1: if (planet >= 0 && planet <= 6)
                return (ARDENT);
            i++;
    case 2: if (planet >= 7 && planet <= 13)
                return (WARM);
            i++;
    case 3: if ((planet >= 14 && planet <= 19) ||
            (planet >= 21 && planet <= 23))
                return (NORMAL);
            i++;
    case 4: if ((planet >= 24 && planet <= 28) || planet == 20)
                return (COLD);
            i++;
    case 5: if (planet >= 29)
                return (FROSTEN);
            break;
    }
    return (NORMAL);
}

planet_animation animation_from_type(planet_type planet)
{
    if (planet >= 7 && planet <= 20)
        return (ANIMATED);
    return (NON_ANIMATED);
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
    }
    for (int i = (size / 8) * 4 ; i < (size / 8) * 6; i++) {
        planets[i].type = random_between(16, 19);
        planets[i].climate = climate_from_type(planets[i].type);
        planets[i].animated = animation_from_type(planets[i].type);
        planets[i].stats = generate_planet_stat(planets[i]);
        planets[i].kind = generate_kind(planets[i].type);
        planets[i].tradable = random_between(0, 1);
        planets[i].colonized = false;
    }
    for (int i = (size / 8) * 6; i < size; i++) {
        planets[i].type = random_between(21, 23);
        planets[i].climate = climate_from_type(planets[i].type);
        planets[i].animated = animation_from_type(planets[i].type);
        planets[i].stats = generate_planet_stat(planets[i]);
        planets[i].kind = generate_kind(planets[i].type);
        planets[i].tradable = false;
        planets[i].colonized = false;
    }
    return (planets);
}