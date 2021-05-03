/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** collisions
*/

#include "my_rpg.h"

void ZQ_collisions(st_global *ad)
{
    if (ad->key_pressed.Z == true && ad->key_pressed.S == false) {
        ad->ship->collisionZ = true;
        ad->ship->firstcollisionZ = true;
    }
    if (ad->key_pressed.Q == true && ad->key_pressed.D == false) {
        ad->ship->collisionQ = true;
        ad->ship->firstcollisionQ = true;
    }
}

void SD_collisions(st_global *ad)
{
    if (ad->key_pressed.S == true) {
        ad->ship->firstcollisionS = true;
        ad->ship->collisionS = true;
    }
    if (ad->key_pressed.D == true) {
        ad->ship->collisionD = true;
        ad->ship->firstcollisionD = true;
    }
}

void renitialise_collisions(st_global *ad)
{
    ad->ship->collisionS = false;
    ad->ship->collisionD = false;
    ad->ship->collisionQ = false;
    ad->ship->collisionZ = false;
}

void check_good_collision(st_global *ad, list_planet planet)
{
    if ((int)ad->ship->bshippos.x < planet->planet.pos.x &&
    (int)ad->ship->bshippos.y > planet->planet.pos.y) {
        ad->ship->collisionZ = true;
        ad->ship->collisionD = true;
    }
    if ((int)ad->ship->bshippos.x < planet->planet.pos.x &&
    (int)ad->ship->bshippos.y < planet->planet.pos.y) {
        ad->ship->collisionS = true;
        ad->ship->collisionD = true;
    }
    if ((int)ad->ship->bshippos.x > planet->planet.pos.x &&
    (int)ad->ship->bshippos.y > planet->planet.pos.y) {
        ad->ship->collisionZ = true;
        ad->ship->collisionQ = true;
    }
    if ((int)ad->ship->bshippos.x > planet->planet.pos.x &&
    (int)ad->ship->bshippos.y < planet->planet.pos.y) {
        ad->ship->collisionS = true;
        ad->ship->collisionQ = true;
    }
}

void planet_collision(st_global *ad)
{
    list_planet planet = ad->planets->planets;
    renitialise_collisions(ad);
    bool c = false;

    while (planet != NULL) {
        if (circle_contains(155, sfSprite_getPosition(planet->planet.sprite),
        sfSprite_getPosition(ad->ship->bship)) && ad->ship->firstcollisionS
        == false && ad->ship->firstcollisionD == false && ad->ship->
        firstcollisionZ == false && ad->ship->firstcollisionQ == false
        && planet->size == 2) {
            SD_collisions(ad);
            ZQ_collisions(ad);
        }
        if (circle_contains(155, sfSprite_getPosition(planet->planet.sprite),
        sfSprite_getPosition(ad->ship->bship)) && planet->size == 2) {
            c = true;
            check_good_collision(ad, planet);
        }
        planet = planet->next;
    }
    collision_by_first(c, ad);
}