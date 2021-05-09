/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** little_planet
*/

#include "my_rpg.h"

void planet_little_cond_1(st_global *ad, list_planet *li)
{
    if (ad->key_pressed.Z && !ad->key_pressed.D && !ad->key_pressed.Q &&
    !ad->key_pressed.S && !ad->ship->collisionZlim && !ad->ship->collisionZ)
        (*li)->planet.pos.y -= 1;
    else if (ad->key_pressed.S && !ad->key_pressed.D && !ad->key_pressed.Q &&
    !ad->key_pressed.Z && !ad->ship->collisionSlim && !ad->ship->collisionS)
        (*li)->planet.pos.y += 1;
    if (ad->key_pressed.D && !ad->key_pressed.Z && !ad->key_pressed.Q &&
    !ad->key_pressed.S && !ad->ship->collisionDlim && !ad->ship->collisionD)
        (*li)->planet.pos.x += 1;
    else if (ad->key_pressed.Q && !ad->key_pressed.D && !ad->key_pressed.Z &&
    !ad->key_pressed.S && !ad->ship->collisionQlim && !ad->ship->collisionQ)
        (*li)->planet.pos.x -= 1;
}

void planet_little_cond_2(st_global *ad, list_planet *li)
{
    if (((ad->key_pressed.Z && ad->key_pressed.D) && (!ad->key_pressed.Q &&
    !ad->key_pressed.S) && (!ad->ship->collisionZlim && !ad->ship->
    collisionDlim) && (!ad->ship->collisionZ && !ad->ship->collisionD))) {
        (*li)->planet.pos.y -= 1;
        (*li)->planet.pos.x += 1;
    }
    else if (((ad->key_pressed.S && ad->key_pressed.D) && (!ad->key_pressed.Q
    && !ad->key_pressed.Z) && (!ad->ship->collisionSlim && !ad->ship->
    collisionDlim) && (!ad->ship->collisionS && !ad->ship->collisionD))) {
        (*li)->planet.pos.y += 1;
        (*li)->planet.pos.x += 1;
    }
}

void planet_little_cond_3(st_global *ad, list_planet *li)
{
    if (((ad->key_pressed.Q && ad->key_pressed.S) && (!ad->key_pressed.Z &&
    !ad->key_pressed.D) && (!ad->ship->collisionQlim && !ad->ship->
    collisionSlim) && (!ad->ship->collisionQ && !ad->ship->collisionS))) {
        (*li)->planet.pos.y += 1;
        (*li)->planet.pos.x -= 1;
    }
    else if (((ad->key_pressed.Z && ad->key_pressed.Q) && (!ad->key_pressed.S
    && !ad->key_pressed.D) && (!ad->ship->collisionZlim && !ad->ship->
    collisionQlim) && (!ad->ship->collisionZ && !ad->ship->collisionQ))) {
        (*li)->planet.pos.y -= 1;
        (*li)->planet.pos.x -= 1;
    }
}

void print_planet_lil(list_planet li, sfRenderWindow *window, st_global *ad)
{
    int rand = random_between(0, 1);

    if (li->size == 1) {
        sfSprite_setTextureRect(li->planet.sprite, li->planet.rect);
        sfSprite_setScale(li->planet.sprite, (sfVector2f){(float)(li->sc * 2) /
        10.0, (float)(li->sc * 2) / 10.0});
        planet_little_cond_1(ad, &li);
        planet_little_cond_2(ad, &li);
        planet_little_cond_3(ad, &li);
        sfSprite_setPosition(li->planet.sprite,
        (sfVector2f){(float)li->planet.pos.x, (float)li->planet.pos.y});
        sfRenderWindow_drawSprite(window, li->planet.sprite, NULL);
    }
}

void print_planet_list_little(list_planet li, sfRenderWindow *window,
st_global *ad)
{
    while (li != NULL){
        if (li->on_screen == true)
            print_planet_lil(li, window, ad);
        li = li->next;
    }
}