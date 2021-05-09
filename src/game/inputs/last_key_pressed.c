/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** last_key_pressed
*/

#include "my_rpg.h"

void last_key_ressed_2(st_global *ad)
{
    if (ad->key_pressed.Q == true && ad->key_pressed.D == false &&
    ad->key_pressed.S == false && ad->key_pressed.Z == false) {
        ad->last_key_pressed.Q = true;
        ad->last_key_pressed.Z = false;
        ad->last_key_pressed.S = false;
        ad->last_key_pressed.D = false;
    }
    if (ad->key_pressed.Z == true && ad->key_pressed.D == false &&
    ad->key_pressed.S == false && ad->key_pressed.Q == false) {
        ad->last_key_pressed.Z = true;
        ad->last_key_pressed.D = false;
        ad->last_key_pressed.S = false;
        ad->last_key_pressed.Q = false;
    }
}

void last_key_pressed(st_global *ad)
{
    if (ad->key_pressed.D == true && ad->key_pressed.S == false &&
    ad->key_pressed.Q == false && ad->key_pressed.Z == false) {
        ad->last_key_pressed.D = true;
        ad->last_key_pressed.Z = false;
        ad->last_key_pressed.S = false;
        ad->last_key_pressed.Q = false;
    }
    if (ad->key_pressed.S == true && ad->key_pressed.D == false &&
    ad->key_pressed.Q == false && ad->key_pressed.Z == false) {
        ad->last_key_pressed.S = true;
        ad->last_key_pressed.Z = false;
        ad->last_key_pressed.D = false;
        ad->last_key_pressed.Q = false;
    }
    last_key_ressed_2(ad);
}