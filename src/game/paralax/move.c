/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** get movements
*/

#include "my_rpg.h"

void go_up(st_global *ad)
{
    if (ad->key_pressed.Z == true && (ad->key_pressed.D == false &&
    ad->key_pressed.Q == false) && ad->paralax->j == 0
    && ad->ship->collisionZ == false && ad->ship->collisionZlim == false) {
        move_up(ad);
    }
}

void go_down(st_global *ad)
{
    if (ad->key_pressed.S == true && (ad->key_pressed.Q == false &&
    ad->key_pressed.D == false) && ad->paralax->i == 0
    && ad->ship->collisionS == false && ad->ship->collisionSlim == false) {
        move_down(ad);
    }
}

void go_left(st_global *ad)
{
    if ((ad->key_pressed.Q == true) && (ad->key_pressed.Z == false &&
    ad->key_pressed.S == false) && ad->paralax->k == 0
    && ad->ship->collisionQ == false && ad->ship->collisionQlim == false) {
        move_left(ad);
    }
}

void go_right(st_global *ad)
{
    if ((ad->key_pressed.D == true) && (ad->key_pressed.Z == false &&
    ad->key_pressed.S == false) && ad->paralax->l == 0
    && ad->ship->collisionD == false && ad->ship->collisionDlim == false) {
        move_right(ad);
    }
}

void paralax_move(st_global *ad)
{
    move_ship(ad);
    ad->ship->bshippos.y += ad->ship->velocity.y;
    ad->ship->bshippos.x += ad->ship->velocity.x;
    ad->ship->viewrect.top += ad->ship->velocity.y;
    ad->ship->viewrect.left += ad->ship->velocity.x;
    ad->paralax->starpos.y += ad->ship->velocity.y;
    ad->paralax->starpos.x += ad->ship->velocity.x;
    ad->paralax->nebulapos.y += ad->ship->velocity.y;
    ad->paralax->nebulapos.x += ad->ship->velocity.x;
    ad->ship->velocity.x = 0;
    ad->ship->velocity.y = 0;
    if (ad->key_pressed.D == false && ad->key_pressed.Q == false &&
    ad->key_pressed.S == false && ad->key_pressed.Z == false)
        check_angle(ad);
}