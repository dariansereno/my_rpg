/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_key_pressed
*/

#include "my_rpg.h"

void generate_key_pressed(st_global *ad)
{
    ad->key_pressed.D = false;
    ad->key_pressed.Z = false;
    ad->key_pressed.S = false;
    ad->key_pressed.Q = false;
    ad->key_pressed.Enter = false;
    ad->key_pressed.J = false;
    ad->key_pressed.R = false;
    ad->key_pressed.Y = false;
    ad->key_pressed.X = false;
    ad->key_pressed.U = false;
    ad->key_pressed.T = false;
}

void generate_last_key_pressed(st_global *ad)
{
    ad->last_key_pressed.D = false;
    ad->last_key_pressed.Z = false;
    ad->last_key_pressed.S = false;
    ad->last_key_pressed.Q = false;
    ad->last_key_pressed.Enter = false;
    ad->last_key_pressed.J = false;
    ad->last_key_pressed.R = false;
    ad->last_key_pressed.Y = false;
    ad->last_key_pressed.X = false;
    ad->last_key_pressed.U = false;
    ad->last_key_pressed.T = false;
}