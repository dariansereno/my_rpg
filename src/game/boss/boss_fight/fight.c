/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** fight
*/

#include "my_rpg.h"

void boss_fight(st_global *ad)
{
    boss_atk(ad);
    atk_queue_boss(ad);
}

void boss_handling(st_global *ad)
{
    if (ad->var_game->boss_generated)
        print_list_shoot_b(&ad->boss->shoot, ad->boss->sprite, ad);
    boss_fight(ad);
    boss_appear(ad);
    boss_red(ad);
}