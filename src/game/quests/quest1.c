/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_quests
*/

#include "my_rpg.h"

void display_message(st_global *ad)
{
    if (ad->var_game->created == true) {
        printf("ma grosse tebi\n");
        add_message(ad, "Hello dear Space traveller, we have been under attack for the past two weeks. Most of our forces have been killed trying to defend our planet and we desperatly need help... Could you please kill 10 enemy ships, it would help us a lot and give us some time to gather our strength back...", 20);
        ad->var_game->created = false;
    }
    //add_message(ad, "Could you please kill 10 enemy ships, it would help us a lot and give us some time to gather our strength back...", 20);
}

void quest_1_initialise(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    bool is_done = false;

    if (ad->var_game->quests != 1)
        return;
    while (pl != NULL) {
        if (pl->can_interact == true && ad->key_pressed.X) {
            ad->var_game->created = true;
            display_message(ad);
            ad->var_game->msg = true;
        }
        pl = pl->next;
    }
    pl = ad->planets->planets;
}