/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** boss_collision
*/

#include "my_rpg.h"

void check_good_collision_boss_2(st_global *ad)
{
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
    check_good_collision_boss_2(ad);
}

int change_radius_if_shield(st_global *ad)
{
    if (ad->boss->shield)
        return (330);
    return (255);
}