/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_quests
*/

#include "my_rpg.h"

void display_second_message(st_global *ad)
{
    if (ad->var_game->created == true) {
        add_message(ad, "Thanks you for helping us out! Our enemies will take a\
        while to recover from the blow you dealt them! We don't have much to\
        give you but we will give you some advice. Your next objective will be\
        to upgrade all of your first planet's modules to level 1. The\
        commercial module will give you 30 credits every 15 seconds. The\
        healing module will slowly regenerate your life when you are in the\
        module's reach. The extraction module will give you a random ressource\
        every 15 seconds which will be useful for your next objective and,\
        finaly, the population module will decrease the time needed for all\
        other modules to complete their operations. Come back to us once all\
        of your modules are upgraded", 20);
        ad->var_game->created = false;
    }
}

void  start_quest1(st_global *ad)
{
    list_planet pl = ad->planets->planets;

    while (pl != NULL) {
        if (pl->planet.start && pl->planet.modules[0] == 1 &&
        pl->planet.modules[1] == 1 && pl->planet.modules[2]
        == 1 && pl->planet.modules[3] == 1) {
            ad->var_game->xp += 50;
            display_big_message("Quest Completed!\n\t    +50 XP", 8, ad, sfRed);
            if (ad->big_msg == NULL) {
                ad->var_game->quests = 3;
            }
            pl = pl->next;
        }
    }
    ad->quest->is_on_quest = false;
}

void quest_2_initialise(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    bool is_done = false;

    if (ad->var_game->quests != 2)
        return;
    while (pl != NULL) {
        if (pl->can_interact && pl->planet.quest && ad->key_pressed.X &&
        !ad->quest->is_on_quest) {
            ad->var_game->created = true;
            ad->quest->is_on_quest = true;
            display_second_message(ad);
        }
        pl = pl->next;
    }
}