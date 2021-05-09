/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_quests
*/

#include "my_rpg.h"

void target_quest2(st_global *ad, list_planet *pl, sfVector2f *questpos)
{
    *questpos = target_indicator(ad, (sfVector2f)
    {(float)(*pl)->planet.pos.x, (float)(*pl)->planet.pos.y});
    sfText_setString(ad->ressources[0].text, "!");
    sfText_setCharacterSize(ad->ressources[0].text, 50);
    sfText_setPosition(ad->ressources[0].text, *questpos);
    sfText_setColor(ad->ressources[0].text, sfRed);
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text,
    NULL);
    sfText_setColor(ad->ressources[0].text, sfWhite);
    sfText_setCharacterSize(ad->ressources[0].text, 25);
}

void target_quest3(st_global *ad, list_planet *pl)
{
    sfSprite_setPosition(ad->planets->quest_pl, (sfVector2f){(float)
    (*pl)->planet.pos.x, (float)(*pl)->planet.pos.y});
    sfSprite_setScale(ad->planets->quest_pl, (sfVector2f){5.0, 5.0});
    sfRenderWindow_drawSprite(ad->window->window, ad->planets->quest_pl,
    NULL);
    sfText_setString(ad->ressources[0].text, "!");
    sfText_setCharacterSize(ad->ressources[0].text, 150);
    sfText_setPosition(ad->ressources[0].text, (sfVector2f){(float)
    (*pl)->planet.pos.x - 10, (float)(*pl)->planet.pos.y - 350});
    sfText_setOutlineColor(ad->ressources[0].text, sfWhite);
    sfText_setColor(ad->ressources[0].text, sfRed);
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text,
    NULL);
    sfText_setColor(ad->ressources[0].text, sfWhite);
    sfText_setOutlineColor(ad->ressources[0].text, sfBlack),
    sfText_setCharacterSize(ad->ressources[0].text, 25);
}

void target_quest(st_global *ad)
{
    list_planet pl = ad->planets->planets;
    sfVector2f questpos = {0, 0};

    while (pl != NULL) {
        if (pl->planet.quest == true && !is_on_screen(ad, pl->planet.pos) &&
        ad->quest->is_on_quest == false && ad->var_game->quests < 7)
            target_quest2(ad, &pl, &questpos);
        if (pl->planet.quest == true && is_on_screen(ad, pl->planet.pos))
            target_quest3(ad, &pl);
        pl = pl->next;
    }
}