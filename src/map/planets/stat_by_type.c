/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** stat_by_type
*/

#include "my_rpg.h"

st_planet_stat stats_for_gas(void)
{
    int stat = random_between(50, 100);
    st_planet_stat planet;
    int total = 100;

    planet.h = stat; 
    total -= stat;
    stat = random_between(0, total);
    planet.N = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.co2 = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.o = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.h2o = stat;
    total -= stat;
    planet.n2 = total;
    planet.pressure = random_between(500, 1000);
    return (planet);
}

st_planet_stat stats_for_ocean(void)
{
    int stat = random_between(70, 100);
    int total = 100;
    st_planet_stat planet;

    planet.h2o = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.n2 = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.o = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.h = stat; 
    total -= stat;
    stat = random_between(0, total);
    planet.co2 = stat;
    total -= stat;
    planet.N = total;
    planet.pressure = random_between(100, 500);
    return (planet);
}

st_planet_stat stats_for_terran(void)
{
    int stat = random_between(50, 100);
    int total = 100;
    st_planet_stat planet;

    planet.n2 = stat; 
    total -= stat;
    stat = random_between(0, total);
    planet.o = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.h2o = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.N = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.co2 = stat;
    total -= stat;
    planet.h = total;
    planet.pressure = random_between(100, 500);
    return (planet);
}

st_planet_stat stats_for_lava(void)
{
    int stat = random_between(70, 100);
    int total = 100;
    st_planet_stat planet;

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
    planet.pressure = random_between(500, 1000);
    return (planet);
}

st_planet_stat stats_for_ice(void)
{
    int stat = random_between(70, 100);
    int total = 100;
    st_planet_stat planet;

    planet.h2o = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.n2 = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.o = stat;
    total -= stat;
    stat = random_between(0, total);
    planet.h = stat; 
    total -= stat;
    stat = random_between(0, total);
    planet.co2 = stat;
    total -= stat;
    planet.N = total;
    planet.pressure = random_between(10, 500);
    return (planet);
}
