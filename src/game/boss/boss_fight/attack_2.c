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
        sfSprite_setOrigin(ad->boss->red_sp, (sfVector2f){24, 24});
        sfSprite_setScale(ad->boss->red_sp, (sfVector2f){10, 10});
        sfSprite_setPosition(ad->boss->red_sp, ad->boss->boss->pos);
        sfRenderWindow_drawSprite(ad->window->window, ad->boss->red_sp, NULL);
    }
}

void attack_2_red(st_global *ad)
{
    sfTime time = sfClock_getElapsedTime(ad->boss->reload);
    float second = time.microseconds / 1000000.0;

    if (second < 3) {
        ad->boss->take_dmg = 2;
        ad->boss->red = true;
    }
    else {
        ad->boss->take_dmg = 1;
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

    if (ad->boss->duration->seconds > 0.1) {
        if (circle_intersect(ad->boss->boss->pos, ad->ship->bshippos, 20,
        ad->boss->radius))
            ad->var_game->life -= ad->boss->damage;
        sfClock_restart(ad->boss->duration->clock);

    }
    attack_2_circle_2(ad, second);
}

void attack_2_shaking(st_global *ad)
{
    if (ad->boss->duration->seconds > 0.05) {
        ad->boss->boss->pos.x += ad->boss->shake;
        if (ad->boss->shake == 4)
            ad->boss->shake = 8;
        ad->boss->shake *= -1;
        sfClock_restart(ad->boss->duration->clock);
    }
}

void attack_2(st_global *ad)
{
    if ( ad->boss->current == NULL || ad->boss->current->type != 2)
        return;
    ad->boss->duration->time = sfClock_getElapsedTime
    (ad->boss->duration->clock);
    ad->boss->duration->seconds = ad->boss->duration->time.microseconds \
    / 1000000.0;
    ad->boss->clock->time = sfClock_getElapsedTime(ad->boss->clock->clock);
    ad->boss->clock->seconds = ad->boss->clock->time.microseconds / 1000000.0;
    if (ad->boss->clock->seconds < 3)
        attack_2_shaking(ad);
    else if (ad->boss->circle)
        attack_2_circle(ad);
    else
        attack_2_red(ad);
}