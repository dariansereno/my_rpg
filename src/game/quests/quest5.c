/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_quests
*/

#include "my_rpg.h"

void display_fifth_message(st_global *ad)
{
    if (ad->var_game->created == true) {
        add_message(ad, "MOUSTACHE A EVAN BITE ITALIANO", 6000);
        ad->var_game->created = false;
    }
}

void start_quest5(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    int x = 0;
    
    if (ad->ressources[3].nb == 1)
        ad->var_game->quest5_completed = true;
    if (ad->var_game->quest5_completed && ad->var_game->quests == 5)
        display_big_message("Quest Completed!\n\t    +50 XP", 8, ad, sfYellow);
    if (ad->big_msg == NULL && ad->var_game->quests == 5 &&
    ad->var_game->quest5_completed) {
        ad->var_game->xp += 50;
        ad->var_game->quests = 3;
        ad->quest->is_on_quest = false;
        ad->var_game->msg5 = false;
    }
}

void quest_5_initialise(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    bool is_done = false;

    if (ad->var_game->quests != 5)
        return;
    while (pl != NULL) {
        if (pl->can_interact && pl->planet.quest && ad->key_pressed.X &&
        !ad->quest->is_on_quest) {
            ad->var_game->created = true;
            ad->quest->is_on_quest = true;
            display_fifth_message(ad);
            ad->var_game->msg5 = true;
        }
        pl = pl->next;
    }
}