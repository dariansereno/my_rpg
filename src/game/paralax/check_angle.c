/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** get movements
*/

#include "my_rpg.h"

void check_angle(st_global *ad)
{
    if (ad->key->down == 1)
        ad->ship->bshipt = ad->texture->load[4];
    if (ad->key->left == 1)
        ad->ship->bshipt = ad->texture->load[6];
    if (ad->key->right == 1)
        ad->ship->bshipt = ad->texture->load[2];
    if (ad->key->up == 1)
        ad->ship->bshipt = ad->texture->load[0];
    if (ad->key->upleft == 1)
        ad->ship->bshipt = ad->texture->load[7];
    if (ad->key->upright == 1)
        ad->ship->bshipt = ad->texture->load[1];
    if (ad->key->downleft == 1)
        ad->ship->bshipt = ad->texture->load[5];
    if (ad->key->downright == 1)
        ad->ship->bshipt = ad->texture->load[3];
}