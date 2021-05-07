/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_colonise
*/

#include "my_rpg.h"

int random_piped_two(void)
{
    int x = random_between(0, 10);

    if (x < 1)
        return (1);
    else
        return (0);
}

bool rand_pl_colonise(list_planet pl)
{
    int rand = 0;

    if (pl->planet.kind == TERRAN && pl->size == 2) {
        rand = random_piped_two();
        if (rand) {
            pl->planet.colonized = true;
            pl->planet.tradable = true;
            pl->planet.start = true;
            return (true);
        }
    }
    return (false);
}

void set_spawn_point(list_planet pl, st_global *ad)
{
    while (pl != NULL) {
        if (pl->planet.colonized) {
            printf("planet no %d\n", pl->index);
            ad->ship->bshippos = (sfVector2f){pl->planet.pos.x - 300 + (1920 / 2),
            pl->planet.pos.y - 300 + (1080 / 2)};
            ad->paralax->nebulapos = (sfVector2f){pl->planet.pos.x - 300, pl->planet.
            pos.y - 300};
            ad->paralax->starpos = (sfVector2f){pl->planet.pos.x - 300, pl->planet.
            pos.y - 300};
            ad->ship->viewrect.left = pl->planet.pos.x - 300;
            ad->ship->viewrect.top = pl->planet.pos.y - 300;
        }
        pl = pl->next;
    }
}

void generate_random_colonised(list_planet *planet, st_global *ad)
{
    bool is_good = false;
    list_planet pl = *planet;

    while (!is_good) {
        while (pl != NULL) {
            is_good = rand_pl_colonise(pl);
            if (is_good)
                break;
            pl = pl->next;
        }
        if (is_good)
            break;
        pl = *planet;
    }
    set_spawn_point(*planet, ad);
}