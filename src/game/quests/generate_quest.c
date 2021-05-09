/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_quests
*/

#include "my_rpg.h"

bool rand_pl_quest(list_planet pl)
{
    int rand = 0;

    if ((pl->planet.type > LAVA1 && pl->planet.type < ICE) && pl->size == 2) {
        rand = random_piped_two();
        if (rand) {
            pl->planet.quest = true;
            return (true);
        }
    }
    return (false);
}

void generate_random_quest2(list_planet *pl, bool *is_good)
{
    while ((*pl) != NULL) {
        *is_good = rand_pl_quest(*pl);
        if (*is_good)
            break;
        (*pl) = (*pl)->next;
    }
}

void generate_random_quest(list_planet *planet, st_global *ad)
{
    bool is_good = false;
    list_planet pl = *planet;

    while (!is_good) {
        generate_random_quest2(&pl, &is_good);
        if (is_good)
            break;
        pl = *planet;
    }
}