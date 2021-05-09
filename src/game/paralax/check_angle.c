/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** get movements
*/

#include "my_rpg.h"

void move_ship(st_global *ad)
{
    go_up(ad);
    go_down(ad);
    go_left(ad);
    go_right(ad);
    go_upright(ad);
    go_upleft(ad);
    go_downleft(ad);
    go_downright(ad);
}

void check_angle(st_global *ad)
{
    ad->ship->bshipt = ad->texture->load;
}