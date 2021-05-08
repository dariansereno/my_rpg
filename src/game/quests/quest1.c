/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_quests
*/

#include "my_rpg.h"

void display_message(st_global *ad)
{
    if (ad->var_game->created == true)
        add_message(ad, "Hello dear Space traveller, we have been under attack \
for the past two weeks. Most of our forces have been killed trying to \
defend our planet and we desperatly need help...\
Could you please kill 10 enemy ships, it would help us a lot\
and give us some time to prepare our troops...", 6000);
        ad->var_game->created = false;
}

void  start_quest1(st_global *ad)
{
    if (ad->var_game->kills >= 1) {
        ad->var_game->xp += 50;
        display_big_message("Quest Completed!\n\t    +50 XP", 8, ad, sfGreen);
        if (ad->big_msg == NULL) {
            ad->var_game->kills = 0;
            ad->var_game->quests = 2;
        }
        ad->quest->is_on_quest = false;
    }
}

void quest_1_initialise(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    bool is_done = false;

    if (ad->var_game->quests != 1)
        return;
    while (pl != NULL) {
        if (pl->can_interact && pl->planet.quest && ad->key_pressed.X &&
        !ad->quest->is_on_quest) {
            ad->quest->is_on_quest = true;
            ad->var_game->created = true;
            display_message(ad);
            ad->var_game->msg = true;
        }
        pl = pl->next;
    }
}