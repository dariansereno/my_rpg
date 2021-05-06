/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** limit_player
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

void collision_by_first_lim(bool c, st_global *ad)
{
    if (c == false) {
        ad->ship->firstcollisionZlim = false;
        ad->ship->firstcollisionDlim = false;
        ad->ship->firstcollisionSlim = false;
        ad->ship->firstcollisionQlim = false;
    }
    if (c == true) {
        if (ad->ship->firstcollisionZlim == true)
            ad->ship->collisionZlim = true;
        if (ad->ship->firstcollisionDlim == true)
            ad->ship->collisionDlim = true;
        if (ad->ship->firstcollisionSlim == true)
            ad->ship->collisionSlim = true;
        if (ad->ship->firstcollisionQlim == true)
            ad->ship->collisionQlim = true;
    }
}

void SD_collisions_lim(st_global *ad)
{
    if (ad->key_pressed.S == true) {
        ad->ship->firstcollisionSlim = true;
        ad->ship->collisionSlim = true;
    }
    if (ad->key_pressed.D == true) {
        ad->ship->collisionDlim = true;
        ad->ship->firstcollisionDlim = true;
    }
}

void ZQ_collisions_lim(st_global *ad)
{
    if (ad->key_pressed.Z == true && ad->key_pressed.S == false) {
        ad->ship->collisionZlim = true;
        ad->ship->firstcollisionZlim = true;
    }
    if (ad->key_pressed.Q == true && ad->key_pressed.D == false) {
        ad->ship->collisionQlim = true;
        ad->ship->firstcollisionQlim = true;
    }
}

void renitialise_collisions_lim(st_global *ad)
{
    ad->ship->collisionSlim = false;
    ad->ship->collisionDlim = false;
    ad->ship->collisionQlim = false;
    ad->ship->collisionZlim = false;
}

void collision_limit(st_global *ad)
{

    renitialise_collisions_lim(ad);
    bool c = false;

    if (((ad->ship->bshippos.y >= 80000 || ad->ship->bshippos.y <= 0) ||
    (ad->ship->bshippos.x >= 80000 || ad->ship->bshippos.x <= 0))
    && ad->ship->firstcollisionSlim == false && ad->ship->firstcollisionDlim ==
    false && ad->ship->firstcollisionZlim == false && ad->ship->firstcollisionQlim
    == false) {
        SD_collisions_lim(ad);
        ZQ_collisions_lim(ad);
    }
    if (((ad->ship->bshippos.y >= 80000 || ad->ship->bshippos.y <= 0) ||
    (ad->ship->bshippos.x >= 80000 || ad->ship->bshippos.x <= 0))) {
        c = true;
        check_good_collision_lim(ad);
    }

    collision_by_first_lim(c, ad);
}