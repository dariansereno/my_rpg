/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** boss_collision
*/

#include "my_rpg.h"

void check_good_collision_boss(st_global *ad)
{
    if ((int)ad->ship->bshippos.x < ad->boss->boss->pos.x &&
    (int)ad->ship->bshippos.y > ad->boss->boss->pos.y) {
        ad->ship->collisionZ = true;
        ad->ship->collisionD = true;
    }
    if ((int)ad->ship->bshippos.x < ad->boss->boss->pos.x &&
    (int)ad->ship->bshippos.y < ad->boss->boss->pos.y) {
        ad->ship->collisionS = true;
        ad->ship->collisionD = true;
    }
    if ((int)ad->ship->bshippos.x > ad->boss->boss->pos.x &&
    (int)ad->ship->bshippos.y > ad->boss->boss->pos.y) {
        ad->ship->collisionZ = true;
        ad->ship->collisionQ = true;
    }
    if ((int)ad->ship->bshippos.x > ad->boss->boss->pos.x &&
    (int)ad->ship->bshippos.y < ad->boss->boss->pos.y) {
        ad->ship->collisionS = true;
        ad->ship->collisionQ = true;
    }
}

int change_radius_if_shield(st_global *ad)
{
    if (ad->boss->shield)
        return (330);
    return (255);
}

void boss_collision(st_global *ad)
{
    renitialise_collisions(ad);
    bool c = false;

    ad->boss->radius_col = change_radius_if_shield(ad);
    if (circle_contains(ad->boss->radius_col, ad->boss->boss->pos, ad->ship->
    bshippos) && !ad->ship->firstcollisionS && !ad->ship->firstcollisionD &&
    !ad->ship-> firstcollisionZ && !ad->ship->firstcollisionQ) {
        SD_collisions(ad);
        ZQ_collisions(ad);
    }
    if (circle_contains(ad->boss->radius_col, ad->boss->boss->pos,
    ad->ship->bshippos)) {
        c = true;
        check_good_collision_boss(ad);
    }
    collision_by_first(c, ad);
}