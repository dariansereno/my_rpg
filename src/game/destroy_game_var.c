/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** destroy_game_var
*/

#include "my_rpg.h"

void destroy_upgrade(st_upgrade *up)
{
    for (int i = 0; i < 4; i++)
        destroy_object(up->upgrade_icon[i]);
}