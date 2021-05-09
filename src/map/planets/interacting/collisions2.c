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

void good_collision(st_global *ad, bool *c)
{
    if (ad->var_game->boss_generated && !ad->var_game->destroy_boss) {
        ad->boss->radius_col = change_radius_if_shield(ad);
        if (circle_contains(ad->boss->radius_col, ad->boss->boss->pos, ad->ship
        ->bshippos) && !ad->ship->firstcollisionS && !ad->ship->firstcollisionD
        && !ad->ship-> firstcollisionZ && !ad->ship->firstcollisionQ) {
            SD_collisions(ad);
            ZQ_collisions(ad);
        }
        if (circle_contains(ad->boss->radius_col, ad->boss->boss->pos,
        ad->ship->bshippos)) {
            *c = true;
            check_good_collision_boss(ad);
        }
    }
}

void planet_collision_content(st_global *ad, list_planet *planet, bool *c)
{
    if (circle_contains(155, sfSprite_getPosition((*planet)->planet.sprite),
    sfSprite_getPosition(ad->ship->bship)) && ad->ship->firstcollisionS
    == false && ad->ship->firstcollisionD == false && ad->ship->
    firstcollisionZ == false && ad->ship->firstcollisionQ == false
    && (*planet)->size == 2) {
        SD_collisions(ad);
        ZQ_collisions(ad);
    }
    if (circle_contains(155, sfSprite_getPosition((*planet)->planet.sprite),
    sfSprite_getPosition(ad->ship->bship)) && (*planet)->size == 2) {
        *c = true;
        check_good_collision(ad, (*planet));
    }
}