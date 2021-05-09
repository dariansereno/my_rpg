/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** pause
*/

#include "my_rpg.h"

void rect_position_pause(st_global *g)
{
    switch (g->ui->pause->pos_rect) {
        case 1:
            sfSprite_setPosition(g->ui->pause->ui[1]->sprite, (sfVector2f)\
            {808, 315});
            break;
        case 2:
            sfSprite_setPosition(g->ui->pause->ui[1]->sprite, (sfVector2f)\
            {808, 504});
            break;
        case 3:
            sfSprite_setPosition(g->ui->pause->ui[1]->sprite, (sfVector2f)\
            {808, 679});
            break;
        default:
            break;
    }
    sfSprite_setPosition(g->ui->pause->ui[0]->sprite, \
    (sfVector2f){691, 166});
}

void display_pause(st_global *g)
{
    if (g->ui->pause->existing && g->ui->end->existing == false) {
        if (g->ui->pause_settings->existing)
            return;
        sfRenderWindow_setMouseCursorVisible(g->window->window, sfTrue);
        hover(g);
        events_pause_up(g);
        for (int i = 0; i < 2; i++) {
            sfSprite_setPosition(g->ui->pause->ui[i]->sprite, (sfVector2f) \
            {sfSprite_getPosition(g->ui->pause->ui[i]->sprite).x + \
            g->ship->viewrect.left, \
            sfSprite_getPosition(g->ui->pause->ui[i]->sprite).y + \
            g->ship->viewrect.top});
            sfRenderWindow_drawSprite(g->window->window, \
            g->ui->pause->ui[i]->sprite, \
            NULL);
        }
        text_pause(g);
    }
}