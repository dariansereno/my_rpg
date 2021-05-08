/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_quests
*/

#include "my_rpg.h"

void display_third_message(st_global *ad)
{
    if (ad->var_game->created == true) {
        add_message(ad, "Good job! you have upgraded all of your modules to \
level 1 and you should now be able to regenerate health at your base and gain \
some passive income aswell as some ressources now and then. Your next job will \
be to colonise another planet in order to be able to gain more ressources \
faster. You must first get 3 Deep space ingots, 3 crystals and 3 black matter \
samples and then press the 'J' key to craft a colony. once this is done you \
must head to a colonisable planet and press the 'C' key to deploy your colony \
on it. Colonising a planet also gives Come back to us once this is done", 1000);
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