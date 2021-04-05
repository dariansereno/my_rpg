/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** collisions2
*/

#include "my_rpg.h"

void collision_by_first(bool c, st_global *ad)
{
    if (c == false) {
        ad->ship->firstcollisionZ = false;
        ad->ship->firstcollisionD = false;
        ad->ship->firstcollisionS = false;
        ad->ship->firstcollisionQ = false;
    }
    if (c == true) {
        if (ad->ship->firstcollisionZ == true)
            ad->ship->collisionZ = true;
        if (ad->ship->firstcollisionD == true)
            ad->ship->collisionD = true;
        if (ad->ship->firstcollisionS == true)
            ad->ship->collisionS = true;
        if (ad->ship->firstcollisionQ == true)
            ad->ship->collisionQ = true;
    }
}

int circle_contains(int r, sfVector2f p, sfVector2f s)
{
    if (((s.x - p.x) * (s.x - p.x)) + ((s.y - p.y) * (s.y - p.y)) < (r * r))
        return (1);
    return (0);
}