/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** events_bis
*/

#include "my_rpg.h"

void events_pause_up_bis(st_global *g)
{
    if (g->ui->pause->pressed) {
        if (g->ui->pause->pos_rect >= 1)
            g->ui->pause->pos_rect -= 1;
        if (g->ui->pause->pos_rect == 0)
            g->ui->pause->pos_rect = 1;
        g->ui->pause->pressed = false;
    }
}

void events_pause_down_bis(st_global *g)
{
    if (g->ui->pause->pressed) {
        if (g->ui->pause->pos_rect <= 3)
            g->ui->pause->pos_rect += 1;
        if (g->ui->pause->pos_rect == 4)
            g->ui->pause->pos_rect = 3;
        g->ui->pause->pressed = false;
    }
}