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
    && ad->ship->collisionZ == false) {
        move_up(ad);
    }
}

void go_down(st_global *ad)
{
    if (ad->key_pressed.S == true && (ad->key_pressed.Q == false &&
    ad->key_pressed.D == false) && ad->paralax->i == 0
    && ad->ship->collisionS == false) {
        move_down(ad);
    }
}

void go_left(st_global *ad)
{
    if ((ad->key_pressed.Q == true) && (ad->key_pressed.Z == false &&
    ad->key_pressed.S == false) && ad->paralax->k == 0
    && ad->ship->collisionQ == false) {
        move_left(ad);
    }
}

void go_right(st_global *ad)
{
    if ((ad->key_pressed.D == true) && (ad->key_pressed.Z == false &&
    ad->key_pressed.S == false) && ad->paralax->l == 0
    && ad->ship->collisionD == false) {
        move_right(ad);
    }
}

void paralax_move(st_global *ad)
{
    go_up(ad);
    go_down(ad);
    go_left(ad);
    go_right(ad);
    go_upright(ad);
    go_upleft(ad);
    go_downleft(ad);
    go_downright(ad);
    if (ad->key_pressed.D == false && ad->key_pressed.Q == false &&
    ad->key_pressed.S == false && ad->key_pressed.Z == false)
        check_angle(ad);
}