/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** planets_stats
*/

#include "my_rpg.h"

st_planet_stat generate_planet_stat_4(st_planet planet)
{
    if (planet.type == 20)
        return (stats_for_ice(planet.stats));
    else if (planet.type >= 24 && planet.type <= 28)
        return (stats_for_asteroid(planet.stats));
    else
        return (stats_for_blackhole(planet.stats));
}

st_planet_stat generate_planet_stat_3(st_planet planet)
{
    if (planet.type >= 16 && planet.type <= 19)
        return (stats_for_terran(planet.stats));

    else if (planet.type >= 21 && planet.type <= 23)
        return (stats_for_tech(planet.stats));

    else
        return (generate_planet_stat_4(planet));
}

st_planet_stat generate_planet_stat_2(st_planet planet)
{
    if (planet.type >= 10 && planet.type <= 13)
        return (stats_for_gas(planet.stats));
    else if (planet.type >= 14 && planet.type <= 15)
        return (stats_for_ocean(planet.stats));
    else
        return (generate_planet_stat_3(planet));
}

st_planet_stat generate_planet_stat(st_planet planet)
{
    if (planet.type >= 0 && planet.type <= 6)
        return (stats_for_sun(planet.stats));
    else if (planet.type >= 7 && planet.type <= 9)
        return (stats_for_lava(planet.stats));
    else
        return (generate_planet_stat_2(planet));
}