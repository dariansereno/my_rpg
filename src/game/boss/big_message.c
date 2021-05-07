/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** big_message
*/

#include "my_rpg.h"

void init_big_msg(st_global *ad)
{
    ad->big_msg = sfClock_create();
    ad->big_msg_generated = true;
}

void draw_big_msg(char *msg, int delay, st_global *ad, sfColor color)
{
    sfText_setString(ad->ressources[0].text, msg);
    sfText_setCharacterSize(ad->ressources[0].text, 150);
    sfText_setColor(ad->ressources[0].text, color);
    sfText_setPosition(ad->ressources[0].text, (sfVector2f){
    ad->ship->viewrect.left + (1920 -
    sfText_getLocalBounds(ad->ressources[0].text).width) / 2,
    ad->ship->viewrect.top + ((1080 - sfText_getLocalBounds(
    ad->ressources[0].text).height) / 2)});
    sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text,
    NULL);
    sfText_setCharacterSize(ad->ressources[0].text, 25);
    sfText_setColor(ad->ressources[0].text, sfWhite);
}

void display_big_message(char *msg, int delay, st_global *ad, sfColor color)
{
    sfTime time;
    float second;

    if (!ad->big_msg_generated)
        init_big_msg(ad);
    if (ad->big_msg_generated) {
        time = sfClock_getElapsedTime(ad->big_msg);
        second = time.microseconds / 1000000.0;
        if (second < delay)
            draw_big_msg(msg, delay, ad, color);
        else {
            sfClock_destroy(ad->big_msg);
            ad->big_msg = NULL;
            ad->big_msg_generated = false;
            return;
        }
    }
}