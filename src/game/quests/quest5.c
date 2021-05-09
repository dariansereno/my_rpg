/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_quests
*/

#include "my_rpg.h"

void display_fifth_message(st_global *ad)
{
    char *str = "Good job! Now that all of your modules are upgraded you should"
    "be able to regenerate health at your base and gain some passive income"
    " aswell as some ressources now and then. Your next objective will be to "
    "get enough ressources to colonise another planet. The ressources needed "
    "for your second colony are 3 of each material and every time you craft a "
    "new colony the price of the next one will increase by one of each material"
    ". Your next objective will be to craft a colony. Gather all the needed "
    "ressources and press the 'J' key to craft a colony. Come back once this is"
    " done.";

    if (ad->var_game->created == true) {
        add_message(ad, str, 6000);
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