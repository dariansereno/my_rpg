/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** attack_2
*/

#include "my_rpg.h"

void boss_red(st_global *ad)
{
    if (ad->boss->red) {
        printf("lol\n");
        sfCircleShape_setOrigin(ad->circle, (sfVector2f){240, 240});
        sfCircleShape_setPosition(ad->circle, ad->boss->boss->pos);
        sfCircleShape_setFillColor(ad->circle, (sfColor){255,0,0, 100});
        sfCircleShape_setOutlineThickness(ad->circle, 0);
        sfCircleShape_setRadius(ad->circle, 240);
        sfRenderWindow_drawCircleShape(ad->window->window, ad->circle, NULL);
    }
}

void attack_2_red(st_global *ad)
{
    sfTime time = sfClock_getElapsedTime(ad->boss->reload);
    float second = time.microseconds / 1000000.0;

    if (second < 3)
        ad->boss->red = true;
    else {
        ad->boss->red = false;
        ad->boss->circle = true;
        ad->boss->current = NULL;
        return;
    }
}

void attack_2_circle(st_global *ad)
{
    sfTime time = sfClock_getElapsedTime(ad->boss->reload);
    float second = time.microseconds / 1000000.0;

    if (second > 0.007) {
        sfCircleShape_setRadius(ad->circle, ad->boss->radius);
        sfCircleShape_setOrigin(ad->circle, (sfVector2f){(float)ad->boss->radius, (float)ad->boss->radius});
        sfCircleShape_setPosition(ad->circle, ad->boss->boss->pos);
        ad->boss->radius += 5;
        sfClock_restart(ad->boss->reload);
    }
    sfRenderWindow_drawCircleShape(ad->window->window, ad->circle, NULL);
    if (ad->boss->radius >= 1000) {
        ad->boss->shake = 4;
        ad->boss->radius = 230;
        ad->boss->circle = false;
        return;
    }
}

void attack_2_shaking(st_global *ad)
{
    if (ad->boss->clock->seconds > 0.05) {
        ad->boss->boss->pos.x += ad->boss->shake;
        if (ad->boss->shake == 4)
            ad->boss->shake = 8;
        ad->boss->shake *= -1;
        sfClock_restart(ad->boss->clock->clock);
    }
}

void attack_2(st_global *ad)
{
    sfTime time;
    float second;

    if ( ad->boss->current == NULL || ad->boss->current->type != 2)
        return;
    time = sfClock_getElapsedTime(ad->boss->current->time->clock);
    second = time.microseconds / 1000000.0;
    if (second < 3)
        attack_2_shaking(ad);
    else if (ad->boss->circle)
        attack_2_circle(ad);
    else
        attack_2_red(ad);
    // else {
    //     ad->boss->current = NULL;
    // }
}