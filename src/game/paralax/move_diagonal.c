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

    if (x <= 2 && ad->key_pressed.S == true && ad->key_pressed.Q == true
    && ad->ship->collisionS == false && ad->ship->collisionQ == false)
        move_downleft(ad);
}

void go_upright(st_global *ad)
{
    int x = ad->paralax->i + ad->paralax->j + ad->paralax->k + ad->paralax->l;

    if (x <= 2 && ad->key_pressed.Z == true && ad->key_pressed.D == true
    && ad->ship->collisionZ == false && ad->ship->collisionD == false)
        move_upright(ad);
}

void go_upleft(st_global *ad)
{
    int x = ad->paralax->i + ad->paralax->j + ad->paralax->k + ad->paralax->l;

    if (x <= 2 && ad->key_pressed.Q == true && ad->key_pressed.Z == true
    && ad->ship->collisionQ == false && ad->ship->collisionZ == false)
        move_upleft(ad);
}

void go_downright(st_global *ad)
{
    int x = ad->paralax->i + ad->paralax->j + ad->paralax->k + ad->paralax->l;

    if (x <= 2 && ad->key_pressed.S == true && ad->key_pressed.D == true
    && ad->ship->collisionS == false && ad->ship->collisionD == false)
        move_downright(ad);
}