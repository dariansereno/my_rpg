/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** fight
*/

#include "my_rpg.h"

void boss_fight(st_global *ad)
{
    boss_atk(ad);
    atk_queue_boss(ad);
}

void where_ennemies_go(list_ennemies li, st_global *ad)
{
    if (circle_contains(1200, (sfVector2f){(float)ad->boss->boss->pos.x,
    (float)ad->boss->boss->pos.y}, li->ennemies.pos) && circle_contains(1200,
    (sfVector2f){(float)ad->boss->boss->pos.x,
    (float)ad->boss->boss->pos.y}, ad->ship->bshippos)) {
        clock_move_ennemies(li, ad);
        if (li->shootcl->seconds > 1) {
            push_back_timer(&li->li_shoot, li->ennemies.pos, li->ennemies.dir);
            sfClock_restart(li->shootcl->clock);
        }
    print_list_shoot_enn(&li->li_shoot, ad->shoot->sprite_enn, ad);
    }
    else
        clock_move_ennemies_to_base(li, ad);
}

void print_ennemies_list_boss(list_ennemies li, sfRenderWindow *window,
st_global *ad)
{
    if (li == NULL)
        return ;
    while (li != NULL) {
        li->shootcl->time = sfClock_getElapsedTime(li->shootcl->clock);
        li->shootcl->seconds = li->shootcl->time.microseconds / 1000000.0;
        where_ennemies_go(li, ad);
        sfSprite_setTextureRect(li->ennemies.sprite, li->ennemies.rect);
        sfSprite_setPosition(li->ennemies.sprite,
        (sfVector2f){(float)li->ennemies.pos.x, (float)li->ennemies.pos.y});
        sfSprite_setOrigin(li->ennemies.sprite, (sfVector2f){24, 24});
        sfRenderWindow_drawSprite(window, li->ennemies.sprite, NULL);
        li = li->next;
    }
}

void boss_handling(st_global *ad)
{
    if (ad->var_game->boss_generated) {
        explo_die(ad);
        if (ad->var_game->destroy_boss)
            return;
        print_list_shoot_b(&ad->boss->shoot, ad->boss->sprite, ad);
    }
    boss_fight(ad);
    boss_appear(ad);
    boss_life(ad);
    if (ad->var_game->boss_generated && ad->boss->current != NULL &&
    ad->boss->shield)
        attack_5_shield(ad);
    if (ad->var_game->boss_generated && ad->boss->current != NULL &
    ad->boss->enn != NULL)
        print_ennemies_list_boss(ad->boss->enn, ad->window->window, ad);
    if (ad->var_game->is_boss && ad->var_game->boss_generated &&
    ad->boss->current != NULL)
        boss_red(ad);
}