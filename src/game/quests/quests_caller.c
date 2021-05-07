/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** quests_caller
*/

#include "my_rpg.h"

void quest_caller(st_global *ad)
{
    // appeller les fonctions des quests et mettre if ad->var_game->quest == 1
    // dans les fonctions direct.

    // QUEST 1
    quest_1_initialise(ad);
    quest_2_initialise(ad);
    // QUEST 2

    // QUEST 3
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
    if (ad->var_game->msg == true)
        start_quest1(ad);
    if (ad->var_game->msg2 == true)
        start_quest2(ad);
}