/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** hover
*/

#include "my_rpg.h"

void hover(st_global *g)
{
    int x = sfMouse_getPosition(g->window->window).x;
    int y = sfMouse_getPosition(g->window->window).y;

    if (x >= 808 && y >= 315 && x <= 1112 && y <= 387)
        g->ui->pause->pos_rect = 1;
    if (x >= 808 && y >= 504 && x <= 1112 && y <= 576)
        g->ui->pause->pos_rect = 2;
    if (x >= 808 && y >= 679 && x <= 1112 && y <= 751)
        g->ui->pause->pos_rect = 3;
}