/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_trade
*/

#include "my_rpg.h"

void generate_trade(st_global *ad, list_planet *planets)
{
    list_planet pl = *planets;

    while (pl != NULL) {
        if (pl->planet.tradable == true)
            pl->trade = trade(ad);
        pl = pl->next;
    }
}