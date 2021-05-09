/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_quests
*/

#include "my_rpg.h"

void display_fourth_message(st_global *ad)
{
    char *str = "Great job! you now know of quite a few ways to gain XP, you "
    "can kill ennemies, colonise planets, buy modules on your colonised "
    "planets or complete quests. Your next job will be to get enough XP to "
    "levelup to level 5. Don't forget to upgrade your stats once you have "
    "enough XP because your XP will be reset once you upgrade one of your "
    "stats.";

    if (ad->var_game->created == true && ad->var_game->quests == 4) {
        add_message(ad, str, 6000);
        ad->var_game->created = false;
    }
}

void start_quest4(st_global *ad)
{
    if (ad->var_game->lvl == 5)
        ad->var_game->quest4_completed = true;
    if (ad->var_game->quest4_completed && ad->var_game->quests == 4)
        display_big_message("Quest Completed!\n\t    +50 XP", 8, ad, sfYellow);
    if (ad->big_msg == NULL && ad->var_game->quests == 4 &&
    ad->var_game->quest4_completed) {
        ad->var_game->xp += 50;
        ad->var_game->quests = 6;
        ad->quest->is_on_quest = false;
        ad->var_game->msg4 = false;
    }
}

void quest_4_initialise(st_global *ad)
{
    list_planet pl = ad->planets->planets;

    if (ad->var_game->quests != 4)
        return;
    while (pl != NULL) {
        if (pl->can_interact && pl->planet.quest && ad->key_pressed.X &&
        !ad->quest->is_on_quest) {
            ad->var_game->created = true;
            ad->quest->is_on_quest = true;
            display_fourth_message(ad);
            ad->var_game->msg4 = true;
        }
        pl = pl->next;
    }
}