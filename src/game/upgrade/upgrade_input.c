/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** upgrade_input
*/

#include "my_rpg.h"

void upgrade_damage(st_global *ad)
{
    if (ad->key_pressed.R && ad->upgrade->can_upgrade && \
    ad->upgrade->upgrade_tab[0] < 3) {
        ad->var_game->lvl += 1;
        ad->var_game->xp = 0.0;
        ad->var_game->max_xp *= 1.3;
        ad->var_game->attack *= 1.5;
        ad->upgrade->upgrade_tab[0] += 1;
        if (ad->upgrade->upgrade_tab[0] == 3)
            ad->var_game->special_atk = true;
        ad->upgrade->can_upgrade = false;
        ad->enn_damage *= 1.2;
        ad->var_game->mul_xp += 0.2;
    }
}

void upgrade_reload(st_global *ad)
{
    if (ad->key_pressed.T && ad->upgrade->can_upgrade && \
    ad->upgrade->upgrade_tab[1] < 3) {
        ad->var_game->lvl += 1;
        ad->var_game->xp = 0.0;
        ad->var_game->max_xp *= 1.3;
        ad->var_game->reload_time -= 0.03;
        ad->upgrade->upgrade_tab[1] += 1;
        ad->upgrade->can_upgrade = false;
        ad->enn_damage *= 1.2;
        ad->var_game->mul_xp += 0.2;
    }
}

void upgrade_speed(st_global *ad)
{
    if (ad->key_pressed.Y && ad->upgrade->can_upgrade && \
    ad->upgrade->upgrade_tab[2] < 3) {
        ad->var_game->lvl += 1;
        ad->var_game->xp = 0.0;
        ad->var_game->max_xp *= 1.3;
        ad->var_game->speed = (int)ad->var_game->speed * 1.1;
        ad->upgrade->upgrade_tab[2] += 1;
        ad->upgrade->can_upgrade = false;
        ad->enn_damage *= 1.4;
        ad->var_game->mul_xp += 0.2;
    }
}

void upgrade_health(st_global *ad)
{
    if (ad->key_pressed.U && ad->upgrade->can_upgrade && \
    ad->upgrade->upgrade_tab[3] < 3) {
        ad->var_game->lvl += 1;
        ad->var_game->xp = 0.0;
        ad->var_game->max_xp *= 1.3;
        ad->var_game->max_health *= 1.3;
        ad->upgrade->upgrade_tab[3] += 1;
        ad->upgrade->can_upgrade = false;
        ad->enn_damage *= 1.2;
        ad->var_game->mul_xp += 0.2;
    }
}

void choose_upgrade(st_global *ad)
{
    upgrade_damage(ad);
    upgrade_reload(ad);
    upgrade_speed(ad);
    upgrade_health(ad);
}