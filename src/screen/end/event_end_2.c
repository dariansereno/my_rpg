/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** event_end_2
*/

#include "my_rpg.h"

void end_rect_left_2(st_global *g)
{
    if (g->ui->end->pressed) {
        if (g->ui->end->pos_rect >= 1)
            g->ui->end->pos_rect -= 1;
        if (g->ui->end->pos_rect == 0)
            g->ui->end->pos_rect = 1;
        g->ui->end->pressed = false;
    }
}

void end_rect_right_2(st_global *g)
{
    if (g->ui->end->pressed) {
        if (g->ui->end->pos_rect <= 2)
            g->ui->end->pos_rect += 1;
        if (g->ui->end->pos_rect == 3)
            g->ui->end->pos_rect = 2;
        g->ui->end->pressed = false;
    }
}

void position_end_2(st_global *g)
{
    switch (g->ui->end->pos_rect) {
        case 1:
            sfRenderWindow_close(g->window->window);
            g->ui->end->existing = false;
            break;
        case 2:
            switch_screen_five(g);
            return;
        default:
            break;
    }
}
