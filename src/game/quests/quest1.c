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

void  start_quest1(st_global *ad)
{
    if (ad->var_game->kills >= 1) {
        ad->var_game->xp += 50;
        sfText_setString(ad->quest->quest_advancement,
        "Quest Completed!\n\t   +50 XP");
        sfText_setFont(ad->quest->quest_advancement, ad->font_inv);
        sfText_setColor(ad->quest->quest_advancement, sfGreen);
        sfText_setCharacterSize(ad->quest->quest_advancement, 150);
        sfText_setPosition(ad->quest->quest_advancement, (sfVector2f){ad->ship->
        viewrect.left + 350, ad->ship->viewrect.top + 350});
        sfRenderWindow_drawText(ad->window->window, ad->quest->quest_advancement
        , NULL);
    }
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