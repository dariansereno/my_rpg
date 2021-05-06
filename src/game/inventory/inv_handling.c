/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** inv_handling
*/

#include "my_rpg.h"

void is_craftable(st_global *ad)
{
    bool is_good = false;

    for (int i = 0; i < 3; i++) {
        if (ad->ressources[i].nb >= 3)
            is_good = true;
        else {
            is_good = false;
            break;
        }
    }
    if (is_good == false)
        ad->var_game->craft = false;
    else
        ad->var_game->craft = true;
}

void craft_settler(st_global *ad)
{
    if (ad->key_pressed.J && ad->var_game->craft && ad->var_game->clicked) {
        ad->var_game->clicked = false;
        for (int i = 0; i < 3; i++)
            ad->ressources[i].nb -= 3;
        ad->ressources[3].nb += 1;
    }
    if (ad->key_pressed.J == false)
        ad->var_game->clicked = true;
}