/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_quests
*/

#include "my_rpg.h"

void display_second_message(st_global *ad)
{
    char *str = "Thank you for helping us out! Our enemies will take a while to"
    " recover from the blow you dealt them! We don't have much to give you but "
    "we will give you some advice. When you are close to a colonised planet and"
    " you press the 'F' key, you can open the module interface and buy "
    "different kind of modules. You can buy the trading module which will give "
    "you 30 credits every 10 seconds at level one. You can also buy the "
    "extraction module which will give you one random ressource every 60 "
    "seconds at level 1. The third module is the Healing module. If you have a "
    "healing module and you stay in the circle around your planet you will "
    "regenerate some health. The last module you can buy is the population "
    "module. This module will reduce the time needed by all other modules to "
    "complete their actions. Every module can be upgraded infinitely to improve"
    " it's efficiency. Your next task will be to upgrade all of the four "
    "modules to level one on your starting planet. "
    "Come back once this is done.";

    if (ad->var_game->created == true && ad->var_game->quests == 2) {
        add_message(ad, str, 6000);
        ad->var_game->created = false;
    }
}

void start_quest2(st_global *ad)
{
    list_planet pl = ad->planets->planets;

    while (pl != NULL && ad->var_game->quest2_completed == false &&
    ad->var_game->quests == 2) {
        if (pl->planet.start && pl->planet.modules[0] >= 1 &&
        pl->planet.modules[1] >= 1 && pl->planet.modules[2]
        >= 1 && pl->planet.modules[3] >= 1) {
            ad->var_game->quest2_completed = true;
        }
        pl = pl->next;
    }
    if (ad->var_game->quest2_completed && ad->var_game->quests == 2)
        display_big_message("Quest Completed!\n\t    +50 XP", 8, ad, sfYellow);
    if (ad->big_msg == NULL && ad->var_game->quests == 2 &&
    ad->var_game->quest2_completed) {
        ad->var_game->xp += 50;
        ad->var_game->quests = 5;
        ad->quest->is_on_quest = false;
        ad->var_game->msg2 = false;
    }
}

void quest_2_initialise(st_global *ad)
{
    list_planet pl = ad->planets->planets;

    if (ad->var_game->quests != 2)
        return;
    while (pl != NULL) {
        if (pl->can_interact && pl->planet.quest && ad->key_pressed.X &&
        !ad->quest->is_on_quest) {
            ad->var_game->created = true;
            ad->quest->is_on_quest = true;
            display_second_message(ad);
            ad->var_game->msg2 = true;
        }
        pl = pl->next;
    }
}