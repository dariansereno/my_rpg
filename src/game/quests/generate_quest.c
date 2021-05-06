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

    if (pl->planet.tradable == true && pl->size == 2) {
        rand = random_piped_two();
        if (rand) {
            return (true);
        }
    }
    return (false);
}

void generate_random_quest(list_planet *planet, st_global *ad)
{
    bool is_good = false;
    list_planet pl = *planet;

    while (!is_good) {
        while (pl != NULL) {
            is_good = rand_pl_quest(pl);
            printf("%d\n", is_good);
            if (is_good)
                break;
            pl = pl->next;
        }
        if (is_good)
            break;
        pl = *planet;
    }
}