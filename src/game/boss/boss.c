/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** boss
*/

#include "my_rpg.h"

// void display_boss_bg(st_global *ad)
// {
//     if (ad->var_game->is_boss && ad->var_game->boss_generated) {
//         sfSprite_setScale(ad->boss->bg->sprite, (sfVector2f){2.3, 2.3});
//         sfSprite_setPosition(ad->boss->bg->sprite, ad->boss->bg->pos);
//         sfSprite_setOrigin(ad->boss->bg->sprite, (sfVector2f){480, 270});
//         sfRenderWindow_drawSprite(ad->window->window ,ad->boss->bg->sprite, NULL);
//     }
// }

// void display_boss(st_global *ad)
// {
//     sfSprite_setPosition(ad->boss->boss->sprite, ad->boss->boss->pos);
//     sfSprite_setOrigin(ad->boss->boss->sprite, (sfVector2f){24, 24});
//     sfSprite_setScale(ad->boss->boss->sprite, (sfVector2f){15, 15});
//     sfRenderWindow_drawSprite(ad->window->window ,ad->boss->boss->sprite, NULL);
// }

// void display_boss_target(st_global *ad, sfVector2f pos)
// {
//     sfText_setString(ad->ressources[0].text, "BOSS");
//     sfText_setCharacterSize(ad->ressources[0].text, 30);
//     sfText_setPosition(ad->ressources[0].text, target_indicator(ad, pos));
//     sfText_setFillColor(ad->ressources[0].text, sfYellow);
//     sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);
//     sfText_setCharacterSize(ad->ressources[0].text, 25);
//     sfText_setFillColor(ad->ressources[0].text, sfWhite);
// }

// void boss_appear(st_global *ad)
// {
//     if (ad->var_game->is_boss && !ad->var_game->boss_generated) {
//         ad->boss = generate_boss(ad);
//         ad->var_game->boss_generated = true;
//     }
//     if (ad->var_game->is_boss) {
//         display_boss(ad);
//         display_boss_target(ad, ad->boss->boss->pos);
//     }
// }