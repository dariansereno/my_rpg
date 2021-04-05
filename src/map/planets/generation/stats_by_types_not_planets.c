/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** stats_by_types_not_planets
*/

#include "my_rpg.h"

st_planet_stat stats_for_sun(st_planet_stat planet)
{
    int stat = random_between(70, 100);
    int total = 100;

    planet.co2 = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.n2 = stat;
    total -= stat;
    stat = 0;
    planet.h2o = stat;
    total -= stat;
    stat = 0;
    planet.o = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.N = stat;
    total -= stat;
    planet.h = total;
    planet.pressure = random_between(1000, 10000);
    return (planet);
}

st_planet_stat stats_for_tech(st_planet_stat planet)
{
    int stat = random_between(50, 100);
    int total = 100;

    planet.co2 = 0;
    planet.h2o = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.o = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.n2 = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.N = stat;
    total -= stat;
    planet.h = total;
    planet.pressure = random_between(10, 250);
    return (planet);
}

st_planet_stat stats_for_asteroid(st_planet_stat planet)
{
    int stat = random_between(70, 100);
    int total = 100;

    planet.co2 = 0;
    stat = 0;
    stat = 0;
    stat = 0;
    stat = 0;
    planet.h = 0;
    planet.pressure = 0;
    return (planet);
}

st_planet_stat stats_for_blackhole(st_planet_stat planet)
{
    int stat = random_between(70, 100);
    int total = 100;

    planet.co2 = stat;
    total -= stat;
    planet.n2 = 0;
    planet.o = 0;
    planet.h = total;
    planet.h2o = 0;
    planet.N = 0;
    planet.pressure = random_between(100000, 10000000);
    return (planet);
}