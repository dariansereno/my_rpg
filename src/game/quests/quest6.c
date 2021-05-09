/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_quests
*/

#include "my_rpg.h"

void display_sixth_message(st_global *ad)
{
    char *str = "Well done! You have learned quickly and you helped us greatly."
    " We will be forever thankful for what you have done for us. The rest of "
    "the story is yours to write! You can now explore space "
    "freely, it is entirely up to you! Good luck and take this gift as a sign "
    "of gratitude. your last quest will be to get to level 12 but "
    "it is up to you to decide how you want to do this. "
    "Good luck Space Traveler!";

    if (ad->var_game->created && ad->var_game->quests == 6) {
        add_message(ad, str, 6000);
        ad->var_game->created = false;
    }
}

void start_quest6(st_global *ad)
{
    if (ad->var_game->quest6_completed && ad->var_game->quests == 6)
        display_big_message("       Gift Received!\n +100 XP +500 credits"
        , 8, ad, sfYellow);
    if (ad->big_msg == NULL && ad->var_game->quests == 6 &&
    ad->var_game->quest6_completed) {
        ad->money->money += 500;
        ad->var_game->xp += 100;
        ad->var_game->quests = 7;
        ad->quest->is_on_quest = false;
        ad->var_game->msg6 = false;
    }
}

void quest_6_initialise(st_global *ad)
{
    list_planet pl = ad->planets->planets;

    if (ad->var_game->quests != 6)
        return;
    while (pl != NULL) {
        if (pl->can_interact && pl->planet.quest && ad->key_pressed.X &&
        !ad->quest->is_on_quest) {
            ad->var_game->created = true;
            ad->quest->is_on_quest = true;
            display_sixth_message(ad);
            ad->var_game->msg6 = true;
            ad->var_game->quest6_completed = true;
        }
        pl = pl->next;
    }
}