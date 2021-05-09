/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** colonise_planet
*/

#include "my_rpg.h"

int check_can_colonise_text(st_global *ad, list_planet pl, int print)
{
    if (pl->planet.type >= 7 && pl->planet.type <= 20 && pl->
    can_interact && pl->size == 2 && !pl->planet.colonized && \
    ad->ressources[3].nb >= 1)
        print = 210;
    return (print);
}