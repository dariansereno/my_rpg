/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** move background
*/

#include "my_rpg.h"

void setkeyup(st_global *ad)
{
    ad->key->up = 1;
    ad->key->upleft = 0;
    ad->key->upright = 0;
    ad->key->right = 0;
    ad->key->left = 0;
    ad->key->downleft = 0;
    ad->key->downright = 0;
    ad->key->down = 0;
}

void setkeydown(st_global *ad)
{
    ad->key->up = 0;
    ad->key->upleft = 0;
    ad->key->upright = 0;
    ad->key->right = 0;
    ad->key->left = 0;
    ad->key->downleft = 0;
    ad->key->downright = 0;
    ad->key->down = 1;
}

void setkeyleft(st_global *ad)
{
    ad->key->up = 0;
    ad->key->upleft = 0;
    ad->key->upright = 0;
    ad->key->right = 0;
    ad->key->left = 1;
    ad->key->downleft = 0;
    ad->key->downright = 0;
    ad->key->down = 0;
}

void setkeyright(st_global *ad)
{
    ad->key->up = 0;
    ad->key->upleft = 0;
    ad->key->upright = 0;
    ad->key->right = 1;
    ad->key->left = 0;
    ad->key->downleft = 0;
    ad->key->downright = 0;
    ad->key->down = 0;
}