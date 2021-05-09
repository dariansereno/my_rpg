/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** limit_player_2
*/

#include "my_rpg.h"

void check_good_collision_lim(st_global *ad)
{
    if ((int)ad->ship->bshippos.x < 0 &&
    (int)ad->ship->bshippos.y > 80000) {
        ad->ship->collisionZlim = true;
        ad->ship->collisionDlim = true;
    }
    if ((int)ad->ship->bshippos.x < 0 &&
    (int)ad->ship->bshippos.y < 0) {
        ad->ship->collisionSlim = true;
        ad->ship->collisionDlim = true;
    }
    if ((int)ad->ship->bshippos.x > 80000 &&
    (int)ad->ship->bshippos.y > 80000) {
        ad->ship->collisionZlim = true;
        ad->ship->collisionQlim = true;
    }
    if ((int)ad->ship->bshippos.x > 80000 &&
    (int)ad->ship->bshippos.y < 0) {
        ad->ship->collisionSlim = true;
        ad->ship->collisionQlim = true;
    }
}