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
        if (pl->planet.quest == true && !is_on_screen(ad, pl->planet.pos)) {
            questpos = target_indicator(ad, (sfVector2f){(float)pl->planet.pos.x, (float)pl->planet.pos.y});
            sfText_setString(ad->ressources[0].text, "!");
            sfText_setCharacterSize(ad->ressources[0].text, 50);
            sfText_setPosition(ad->ressources[0].text, questpos);
            sfText_setColor(ad->ressources[0].text, sfRed);
            sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);
            sfText_setColor(ad->ressources[0].text, sfWhite);
            sfText_setCharacterSize(ad->ressources[0].text, 25);
        }
        pl = pl->next;
    }
}