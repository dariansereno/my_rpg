/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** big_planets
*/

#include "my_rpg.h"

void big_planet_cond_3(st_global *ad, list_planet *li)
{
    if (((ad->key_pressed.Q && ad->key_pressed.S) && (!ad->key_pressed.Z &&
    !ad->key_pressed.D) && (!ad->ship->collisionQlim && !ad->ship->
    collisionSlim) && (!ad->ship->collisionQ && !ad->ship->collisionS))) {
        (*li)->planet.pos.y -= 3;
        (*li)->planet.pos.x += 3;
    }
    else if (((ad->key_pressed.Z && ad->key_pressed.Q) && (!ad->key_pressed.
    S && !ad->key_pressed.D) && (!ad->ship->collisionZlim && !ad->ship->
    collisionQlim) && (!ad->ship->collisionZ && !ad->ship->collisionQ))) {
        (*li)->planet.pos.y += 3;
        (*li)->planet.pos.x += 3;
    }
}

void big_planet_cond_2(st_global *ad, list_planet *li)
{
    if (((ad->key_pressed.Z && ad->key_pressed.D) && (!ad->key_pressed.Q &&
    !ad->key_pressed.S) && (!ad->ship->collisionZlim && !ad->ship->
    collisionDlim) && (!ad->ship->collisionZ && !ad->ship->collisionD))) {
        (*li)->planet.pos.y += 3;
        (*li)->planet.pos.x -= 3;
    }
    else if (((ad->key_pressed.S && ad->key_pressed.D) && (!ad->key_pressed.
    Q && !ad->key_pressed.Z) && (!ad->ship->collisionSlim && !ad->ship->
    collisionDlim) && (!ad->ship->collisionS && !ad->ship->collisionD))) {
        (*li)->planet.pos.y -= 3;
        (*li)->planet.pos.x -= 3;
    }
}

void big_planet_cond_1(st_global *ad, list_planet *li)
{
    if (ad->key_pressed.Z && !ad->key_pressed.D && !ad->key_pressed.Q &&
    !ad->key_pressed.S && !ad->ship->collisionZlim && !ad->ship->collisionZ)
        (*li)->planet.pos.y += 3;
    else if (ad->key_pressed.S && !ad->key_pressed.D && !ad->key_pressed.Q
    && !ad->key_pressed.Z && !ad->ship->collisionSlim &&
    !ad->ship->collisionS)
        (*li)->planet.pos.y -= 3;
    if (ad->key_pressed.D && !ad->key_pressed.Z && !ad->key_pressed.Q &&
    !ad->key_pressed.S && !ad->ship->collisionDlim && !ad->ship->collisionD)
        (*li)->planet.pos.x -= 3;
    else if (ad->key_pressed.Q && !ad->key_pressed.D && !ad->key_pressed.Z
    && !ad->key_pressed.S && !ad->ship->collisionQlim &&
    !ad->ship->collisionQ)
        (*li)->planet.pos.x += 3;
}

void print_planet_big(list_planet li, sfRenderWindow *window, st_global *ad)
{
    if (li->size == 3) {
        sfSprite_setTextureRect(li->planet.sprite, li->planet.rect);
        sfSprite_setScale(li->planet.sprite, (sfVector2f){li->sc, li->sc});
        big_planet_cond_1(ad, &li);
        big_planet_cond_2(ad, &li);
        big_planet_cond_3(ad, &li);
        sfSprite_setPosition(li->planet.sprite,
        (sfVector2f){(float)li->planet.pos.x, (float)li->planet.pos.y});
        sfRenderWindow_drawSprite(window, li->planet.sprite, NULL);
    }
}

void print_planet_list_big(list_planet li, sfRenderWindow *window,
st_global *ad)
{
    while (li != NULL){
        if (li->on_screen == true)
            print_planet_big(li, window, ad);
        li = li->next;
    }
}
