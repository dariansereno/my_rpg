/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** pause_settings
*/

#include "my_rpg.h"

void rect_set_position_pause_settings(st_global *g)
{
    switch (g->ui->pause_settings->pos_rect) {
        case 1:
            sfSprite_setPosition(g->ui->pause_settings->ui[1]->sprite, \
            (sfVector2f){783, 749});
            break;
        case 2:
            sfSprite_setPosition(g->ui->pause_settings->ui[1]->sprite, \
            (sfVector2f){987, 749});
            break;
        default:
            break;
    }
    sfSprite_setPosition(g->ui->pause_settings->ui[0]->sprite, \
    (sfVector2f){691, 166});
    sfSprite_setPosition(g->ui->pause_settings->ui[2]->sprite, \
    (sfVector2f){844, 368});
    sfSprite_setPosition(g->ui->pause_settings->ui[3]->sprite, \
    (sfVector2f){844, 542});
}

void display_pause_settings(st_global *g)
{
    if (g->ui->pause_settings->existing) {
        rect_set_position_pause_settings(g);
        events_pause_settings_left(g);
        events_pause_settings_right(g);
        set_width_volume_pause_settings(g);
        set_rect_texture_pause_settings(g);
        for (int i = 0; i < 4; i++) {
            sfSprite_setPosition(g->ui->pause_settings->ui[i]->sprite, \
            (sfVector2f) \
            {sfSprite_getPosition(g->ui->pause_settings->ui[i]->sprite).x + \
            g->ship->viewrect.left, \
            sfSprite_getPosition(g->ui->pause_settings->ui[i]->sprite).y + \
            g->ship->viewrect.top});
            sfRenderWindow_drawSprite(g->window->window, \
            g->ui->pause_settings->ui[i]->sprite, \
            NULL);
        }
        text_rect_pause_settings(g);
    }
}

void set_rect_texture_pause_settings(st_global *g)
{
    sfSprite_setTextureRect(g->ui->pause_settings->ui[2]->sprite, \
    g->ui->pause_settings->ui[2]->rect);
    sfSprite_setTextureRect(g->ui->pause_settings->ui[3]->sprite, \
    g->ui->pause_settings->ui[3]->rect);
}