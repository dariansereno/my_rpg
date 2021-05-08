/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** quests_caller
*/

#include "my_rpg.h"

void quest_caller(st_global *ad)
{
    quest_1_initialise(ad);
    quest_2_initialise(ad);
    quest_3_initialise(ad);
    quest_4_initialise(ad);
    quest_5_initialise(ad);
    return;
}

void check_quest(st_global *ad)
{
    list_planet pl = ad->planets->planets;

    while (pl != NULL) {
        if (pl->planet.quest == true && ad->key_pressed.X) {
            quest_caller(ad);
        }
        pl = pl->next;
    }
    if (ad->var_game->msg)
        start_quest1(ad);
    if (ad->var_game->msg2)
        start_quest2(ad);
    if (ad->var_game->msg3)
        start_quest3(ad);
    if (ad->var_game->msg4)
        start_quest4(ad);
    if (ad->var_game->msg5)
        start_quest5(ad);
}