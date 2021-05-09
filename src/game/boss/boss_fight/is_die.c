/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** is_die
*/

#include "my_rpg.h"

int print_list_explo_boss_rect(list_timer *temp, list_timer *li, st_global *ad)
{
    if ((*temp)->timer.seconds > 0.1) {
        ad->shoot->explo_rect.left += 46;
        if (ad->shoot->explo_rect.left >= 460) {
            ad->shoot->explo_rect.left = 0;
            pop_position_timer(li, (*temp)->index);
            reindex_timer(li);
            (*temp) = (*temp)->next;
            return (0);
        }
        sfClock_restart((*temp)->timer.clock);
    }
    return (1);
}

void print_list_explo_boss(list_timer *li, st_global *ad)
{
    list_timer temp = *li;
    list_timer buff = *li;

    if (temp == NULL)
        return ;
    while (temp != NULL) {
        temp->timer.time = sfClock_getElapsedTime(temp->timer.clock);
        temp->timer.seconds = temp->timer.time.microseconds / 1000000.0;
        if (!print_list_explo_boss_rect(&temp, li, ad))
            continue;
        sfSprite_setScale(ad->shoot->explo_sp2, (sfVector2f){20, 20});
        sfSprite_setTextureRect(ad->shoot->explo_sp2, ad->shoot->explo_rect);
        sfSprite_setOrigin(ad->shoot->explo_sp2, (sfVector2f){23, 23});
        sfSprite_setPosition(ad->shoot->explo_sp2, temp->pos);
        sfRenderWindow_drawSprite(ad->window->window, ad->shoot->explo_sp2,
        NULL);
        temp = temp->next;
    }
}

sfVector2f random_circle_point(sfVector2f c, float radius)
{
    float r = radius * sqrt( (((float)rand()/(float)(RAND_MAX/1))) ) ;
    float theta = random() * 2 * M_PI;
    sfVector2f pos;

    pos.x = c.x + r * cos(theta);
    pos.y = c.y + r * sin(theta);
    return (pos);
}

void explo_die_2(st_global *ad, float second)
{
    if (ad->boss->lil_explo == true) {
        if (second > 0.09) {
            push_back_timer(&ad->boss->li_lil_explo,
            random_circle_point(ad->boss->boss->pos, 240), -1);
            ad->boss->it += 1;
            sfClock_restart(ad->boss->clock_g);
        }
        if (ad->boss->it >= 15)
            ad->boss->lil_explo = false;
        ad->var_game->destroy_boss = true;
    }
}

void explo_die(st_global *ad)
{
    sfTime time = sfClock_getElapsedTime(ad->boss->clock_g);
    float second = time.microseconds / 1000000.0;

    if (ad->boss->life_f <= 0 && ad->boss->is_die == false)
        ad->boss->big_explo = true;
    if (ad->boss->big_explo == true) {
        push_back_timer(&ad->boss->li_big_explo, ad->boss->boss->pos, -1);
        ad->boss->is_die = true;
        ad->boss->big_explo = false;
        ad->boss->lil_explo = true;
    }
    explo_die_2(ad, second);
}