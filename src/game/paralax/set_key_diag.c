/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** move background
*/

#include "my_rpg.h"

void setkeyupleft(st_global *ad)
{
    ad->key->up = 0;
    ad->key->upleft = 1;
    ad->key->upright = 0;
    ad->key->right = 0;
    ad->key->left = 0;
    ad->key->downleft = 0;
    ad->key->downright = 0;
    ad->key->down = 0;
}

void setkeyupright(st_global *ad)
{
    ad->key->up = 0;
    ad->key->upleft = 0;
    ad->key->upright = 1;
    ad->key->right = 0;
    ad->key->left = 0;
    ad->key->downleft = 0;
    ad->key->downright = 0;
    ad->key->down = 0;
}

void setkeydownleft(st_global *ad)
{
    ad->key->up = 0;
    ad->key->upleft = 0;
    ad->key->upright = 0;
    ad->key->right = 0;
    ad->key->left = 0;
    ad->key->downleft = 1;
    ad->key->downright = 0;
    ad->key->down = 0;
}

void setkeydownright(st_global *ad)
{
    ad->key->up = 0;
    ad->key->upleft = 0;
    ad->key->upright = 0;
    ad->key->right = 0;
    ad->key->left = 0;
    ad->key->downleft = 0;
    ad->key->downright = 1;
    ad->key->down = 0;
}