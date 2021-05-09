/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_action2
*/

#include "my_rpg.h"

void paralax_spaceobj_diagonal_2(st_global *ad, list_spaceobj *li)
{
    if (((ad->key_pressed.Q && ad->key_pressed.S) && (!ad->key_pressed.Z &&
    !ad->key_pressed.D) && (!ad->ship->collisionQlim && !ad->ship->
    collisionSlim) && (!ad->ship->collisionQ && !ad->ship->collisionS))) {
        (*li)->pos.y += 2;
        (*li)->pos.x -= 2;
    }
    else if (((ad->key_pressed.Z && ad->key_pressed.Q) && (!ad->key_pressed
    .S && !ad->key_pressed.D) && (!ad->ship->collisionZlim && !ad->ship->
    collisionQlim) && (!ad->ship->collisionZ && !ad->ship->collisionQ))) {
        (*li)->pos.y -= 2;
        (*li)->pos.x -= 2;
    }
}

void paralax_spaceobj_diagonal_1(st_global *ad, list_spaceobj *li)
{
    if (((ad->key_pressed.Z && ad->key_pressed.D) && (!ad->key_pressed.Q
    && !ad->key_pressed.S) && (!ad->ship->collisionZlim && !ad->ship->
    collisionDlim) && (!ad->ship->collisionZ && !ad->ship->collisionD))) {
        (*li)->pos.y -= 2;
        (*li)->pos.x += 2;
    }
    else if (((ad->key_pressed.S && ad->key_pressed.D) && (!ad->key_pressed.
    Z && !ad->key_pressed.Q) && (!ad->ship->collisionSlim && !ad->ship->
    collisionDlim) && (!ad->ship->collisionS && !ad->ship->collisionD))) {
        (*li)->pos.y += 2;
        (*li)->pos.x += 2;
    }
}

void paralax_spaceobj(st_global *ad, list_spaceobj *li)
{
    if (ad->key_pressed.Z && !ad->key_pressed.D && !ad->key_pressed.Q
        && !ad->key_pressed.S && !ad->ship->collisionZlim &&
    !ad->ship->collisionZ)
        (*li)->pos.y -= 2;
    else if (ad->key_pressed.S && !ad->key_pressed.D && !ad->key_pressed.Q
    && !ad->key_pressed.Z && !ad->ship->collisionSlim &&
    !ad->ship->collisionS)
        (*li)->pos.y += 2;
    if (ad->key_pressed.D && !ad->key_pressed.Z && !ad->key_pressed.Q &&
    !ad->key_pressed.S && !ad->ship->collisionDlim &&
    !ad->ship->collisionD)
        (*li)->pos.x += 2;
    else if (ad->key_pressed.Q && !ad->key_pressed.D && !ad->key_pressed.Z
    && !ad->key_pressed.S && !ad->ship->collisionQlim &&
    !ad->ship->collisionQ)
        (*li)->pos.x -= 2;
}

void check_size(list_spaceobj *li)
{
    sfSprite_setScale((*li)->sprite, (sfVector2f){10, 10});
    if ((*li)->id >= 4 && (*li)->id <= 7)
        sfSprite_setScale((*li)->sprite, (sfVector2f){1, 1});
}

void print_spaceobj_list(list_spaceobj li, sfRenderWindow *window,
st_global *ad)
{
    while (li != NULL){
        if (li->on_screen == true) {
            check_size(&li);
            paralax_spaceobj(ad, &li);
            paralax_spaceobj_diagonal_1(ad, &li);
            paralax_spaceobj_diagonal_2(ad, &li);
            sfSprite_setPosition(li->sprite,
            (sfVector2f){(float)li->pos.x, (float)li->pos.y});
            sfRenderWindow_drawSprite(window, li->sprite, NULL);
        }
        li = li->next;
    }
}