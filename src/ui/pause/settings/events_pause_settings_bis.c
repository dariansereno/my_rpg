/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** events_pause_settings_bis
*/

#include "my_rpg.h"

void events_pause_settings_right_bis(st_global *g)
{
    if (g->ui->pause_settings->pressed) {
        if (g->ui->pause_settings->pos_rect <= 2)
            g->ui->pause_settings->pos_rect += 1;
        if (g->ui->pause_settings->pos_rect == 3)
            g->ui->pause_settings->pos_rect = 2;
        g->ui->pause_settings->pressed = false;
    }
}

void events_pause_settings_left_bis(st_global *g)
{
    if (g->ui->pause_settings->pressed) {
        if (g->ui->pause_settings->pos_rect >= 1)
            g->ui->pause_settings->pos_rect -= 1;
        if (g->ui->pause_settings->pos_rect == 0)
            g->ui->pause_settings->pos_rect = 1;
        g->ui->pause_settings->pressed = false;
    }
}