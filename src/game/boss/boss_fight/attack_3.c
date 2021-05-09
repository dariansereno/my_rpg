/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** attack_3
*/

#include "my_rpg.h"

sfVector2f generate_point_on_circle(st_global *ad, float radius, float value,
sfVector2f pos)
{
    float angle = 0;
    float x = 0;
    float y = 0;

    angle = value * M_PI * 2;
    x = cos(angle) * radius + pos.x;
    y = (sin(angle) * radius) + pos.y;

    return ((sfVector2f){x, y});
}

void attack_3_action_push_shoot(st_global *ad)
{
    push_back_timer_b(&ad->boss->shoot, calculate_target_vector(ad->boss->
    boss->pos, generate_point_on_circle(ad, 100, ad->boss->incr_speed_atk,
    ad->boss->boss->pos), 5), ad->boss->boss->pos);
    push_back_timer_b(&ad->boss->shoot, calculate_target_vector(ad->boss->
    boss->pos, generate_point_on_circle(ad, 100, ad->boss->decr_speed_atk,
    ad->boss->boss->pos), 5), ad->boss->boss->pos);
    if (ad->boss->incr_speed_atk >= 1) {
        ad->boss->incr_speed_atk = 0;
        if (ad->boss->decr_speed_atk <= 0)
            ad->boss->decr_speed_atk = 1;
        sfClock_restart(ad->boss->reload);
    }
}

void attack_3_action(st_global *ad)
{
    sfTime time = sfClock_getElapsedTime(ad->boss->reload);
    float second = time.microseconds / 1000000.0;
    sfTime time_s = sfClock_getElapsedTime(ad->boss->clock_g);
    float second_s = time_s.microseconds / 1000000.0;

    if (second_s > 0.03) {
        ad->boss->incr_speed_atk += 0.01;
        ad->boss->decr_speed_atk -= 0.01;
        sfClock_restart(ad->boss->clock_g);
    }
    if (second > 0.05)
        attack_3_action_push_shoot(ad);
}

void attack_3(st_global *ad)
{
    sfTime time;
    float second;

    if (ad->boss->current == NULL || ad->boss->current->type != 3)
        return;
    time = sfClock_getElapsedTime(ad->boss->duration->clock);
    second = time.microseconds / 1000000.0;
    if (second < ad->boss->current->duration) {
        attack_3_action(ad);
        sfClock_restart(ad->boss->clock->clock);
    }
    else
        ad->boss->current = NULL;
}