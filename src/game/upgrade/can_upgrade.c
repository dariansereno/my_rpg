/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** can_upgrade
*/

#include "my_rpg.h"

void can_upgrade(st_global *ad)
{
    if (ad->var_game->xp >= ad->var_game->max_xp)
        ad->upgrade->can_upgrade = true;
    // else
    //     ad->upgrade->can_upgrade = false;
}