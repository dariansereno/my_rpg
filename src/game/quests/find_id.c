/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_quests
*/

#include "my_rpg.h"

void target_quest(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    sfVector2f questpos = {0, 0};

    while (pl != NULL) {
        if (pl->planet.quest == true) {
            questpos = target_indicator(ad, (sfVector2f){(float)pl->planet.pos.x, (float)pl->planet.pos.y});
            sfText_setString(ad->ressources[0].text, "QUEST");
            sfText_setPosition(ad->ressources[0].text, questpos);
            sfText_setColor(ad->ressources[0].text, sfRed);
            sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);
        }
        pl = pl->next;
    }
}