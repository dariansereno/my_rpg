/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** move_diagonal
*/

#include "my_rpg.h"


void go_downleft(st_global *ad)
{
    int x = ad->paralax->i + ad->paralax->j + ad->paralax->k + ad->paralax->l;
    if (x <= 2 && ad->key_pressed.S == true && ad->key_pressed.Q == true)
        move_downleft(ad);
}

void go_upright(st_global *ad)
{
    int x = ad->paralax->i + ad->paralax->j + ad->paralax->k + ad->paralax->l;

    if (x <= 2 && ad->key_pressed.Z == true && ad->key_pressed.D == true)
        move_upright(ad);
}

void go_upleft(st_global *ad)
{
    int x = ad->paralax->i + ad->paralax->j + ad->paralax->k + ad->paralax->l;

    if (x <= 2 && ad->key_pressed.Q == true && ad->key_pressed.Z == true)
        move_upleft(ad);
}

void go_downright(st_global *ad)
{
    int x = ad->paralax->i + ad->paralax->j + ad->paralax->k + ad->paralax->l;

    if (x <= 2 && ad->key_pressed.S == true && ad->key_pressed.D == true)
        move_downright(ad);
}