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

int circle_intersect(sfVector2f c1, sfVector2f c2, int d1, int d2) {
    float a = (float)d2;
    float b = (float)d1;
    float c = sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));
    float A = acos((b*b+c*c-a*a)/(2*b*c));
    float theta = atan2(c2.y-c1.y,c2.x-c1.x);
    float phi1 = theta+A;
    float phi2 = theta-A;
    float x3;
    float y3; 
    float x4;
    float y4;

    if(d1 < 0 || d2 < 0)
        return (0);

    x3 = d1 * cos(phi1) + c1.x;
    y3 = d1 * sin(phi1) + c1.y;
    x4 = d1 * cos(phi2) + c1.x;
    y4 = d1 * sin(phi2) + c1.y;
    if (isnan(x3) && isnan(y3) && isnan(x4) && isnan(y4))
        return (0);
    return (1);
}



void attack_2_circle(st_global *ad)
{
    sfTime time = sfClock_getElapsedTime(ad->boss->reload);
    float second = time.microseconds / 1000000.0;

    if (ad->boss->current->time->seconds > 0.1) {
        if (circle_intersect(ad->boss->boss->pos, ad->ship->bshippos, 20,
        ad->boss->radius))
            ad->var_game->life -= ad->boss->damage;
        sfClock_restart(ad->boss->current->time->clock);

    }
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
    if (ad->boss->current->time->seconds > 0.05) {
        ad->boss->boss->pos.x += ad->boss->shake;
        if (ad->boss->shake == 4)
            ad->boss->shake = 8;
        ad->boss->shake *= -1;
        sfClock_restart(ad->boss->current->time->clock);
    }
}

void attack_2(st_global *ad)
{
    if ( ad->boss->current == NULL || ad->boss->current->type != 2)
        return;
    ad->boss->current->time->time = sfClock_getElapsedTime(ad->boss->current->time->clock);
    ad->boss->current->time->seconds = ad->boss->current->time->time.microseconds / 1000000.0;
    ad->boss->clock->time = sfClock_getElapsedTime(ad->boss->clock->clock);
    ad->boss->clock->seconds = ad->boss->clock->time.microseconds / 1000000.0;
    if (ad->boss->clock->seconds < 3)
        attack_2_shaking(ad);
    else if (ad->boss->circle)
        attack_2_circle(ad);
    else
        attack_2_red(ad);
}