/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_quests
*/

#include "my_rpg.h"

void display_third_message(st_global *ad)
{
    char *str = "Good job! You should now be able to see that you have one "
    "colony in your inventory represented by a small house. In order to deploy "
    "your colony you must approach a colony suited for life and press the 'C' "
    "key. This will be your next objective. Come back to us once you have "
    "completed this task.";

    if (ad->var_game->created == true && ad->var_game->quests == 3) {
        add_message(ad, str, 6000);
        ad->var_game->created = false;
    }
}

void start_quest3(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    int x = 0;

    while (pl != NULL && ad->var_game->quest3_completed == false &&
    ad->var_game->quests == 3) {
        if (pl->planet.colonized)
            x++;
        if (pl->planet.start && x >= 2)
            ad->var_game->quest3_completed = true;
        pl = pl->next;
    }
    if (ad->var_game->quest3_completed && ad->var_game->quests == 3)
        display_big_message("Quest Completed!\n\t    +50 XP", 8, ad, sfYellow);
    if (ad->big_msg == NULL && ad->var_game->quests == 3 &&
    ad->var_game->quest3_completed) {
        ad->var_game->xp += 50;
        ad->var_game->quests = 4;
        ad->quest->is_on_quest = false;
        ad->var_game->msg3 = false;
    }
}

void quest_3_initialise(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    bool is_done = false;

    if (ad->var_game->quests != 3)
        return;
    while (pl != NULL) {
        if (pl->can_interact && pl->planet.quest && ad->key_pressed.X &&
        !ad->quest->is_on_quest) {
            ad->var_game->created = true;
            ad->quest->is_on_quest = true;
            display_third_message(ad);
            ad->var_game->msg3 = true;
        }
        pl = pl->next;
    }
}