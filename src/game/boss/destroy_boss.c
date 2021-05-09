/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** destroy_boss
*/

#include "my_rpg.h"

void destroy_boss_fight2(st_global *ad)
{
    sfClock_destroy(ad->boss->reload);
    sfSprite_destroy(ad->boss->sprite);
    sfSprite_destroy(ad->boss->red_sp);
    sfSprite_destroy(ad->boss->shield_sp);
    sfTexture_destroy(ad->boss->texture);
    sfTexture_destroy(ad->boss->shield_tex);
    sfTexture_destroy(ad->boss->red_tex);
}

void destroy_boss_fight(st_global *ad)
{
    destroy_object(ad->boss->bg);
    destroy_object(ad->boss->boss);
    sfRectangleShape_destroy(ad->boss->outline);
    sfRectangleShape_destroy(ad->boss->life);
    sfClock_destroy(ad->boss->clock_g);
    if (ad->boss->current != NULL)
        sfClock_destroy(ad->boss->duration->clock);
    sfClock_destroy(ad->boss->clock->clock);
    sfClock_destroy(ad->boss->atk_timer->clock);
    destroy_list_boss(&ad->boss->atk_li);
    destroy_li_shoot_boss(&ad->boss->shoot);
    destroy_list_timer(&ad->boss->li_big_explo);
    destroy_list_timer(&ad->boss->li_lil_explo);
    destroy_ennemies_list(&ad->boss->enn);
}