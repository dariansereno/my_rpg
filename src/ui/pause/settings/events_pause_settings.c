/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** events_pause_settings
*/

#include "my_rpg.h"

void text_rect_pause_settings(st_global *g)
{
    sfText_setCharacterSize(g->ui->pause->text, 45);
    sfText_setColor(g->ui->pause->text, sfColor_fromRGB(179, 130, 188));
    sfText_setString(g->ui->pause->text, "cancel");
    sfText_setPosition(g->ui->pause->text, \
    (sfVector2f){g->ship->viewrect.left + 795, g->ship->viewrect.top + 755});
    sfRenderWindow_drawText(g->window->window, g->ui->pause->text, NULL);
    sfText_setString(g->ui->pause->text, "save");
    sfText_setPosition(g->ui->pause->text, \
    (sfVector2f){g->ship->viewrect.left + 1015, g->ship->viewrect.top + 755});
    sfRenderWindow_drawText(g->window->window, g->ui->pause->text, NULL);
}

void events_pause_settings(st_global *g)
{
    if (g->window->event.type == sfEvtKeyPressed && g->window->event.key.code
    == sfKeyReturn)
        g->ui->pause_settings->pressed = true;
    if (g->window->event.type == sfEvtKeyReleased && g->window->event.key.code
    == sfKeyReturn && g->ui->pause_settings->pressed) {
        switch_pause_settings(g);
        g->ui->pause_settings->pressed = false;
    }
}

void events_pause_settings_left(st_global *g)
{
    if (g->window->event.type == sfEvtKeyPressed && \
    g->window->event.key.code == sfKeyLeft)
        g->ui->pause_settings->pressed = true;
    if (g->window->event.type == sfEvtKeyReleased && \
    g->window->event.key.code == sfKeyLeft) {
        if (g->ui->pause_settings->pressed) {
            if (g->ui->pause_settings->pos_rect >= 1)
                g->ui->pause_settings->pos_rect -= 1;
            if (g->ui->pause_settings->pos_rect == 0)
                g->ui->pause_settings->pos_rect = 1;
            g->ui->pause_settings->pressed = false;
        }
    }
}

void events_pause_settings_right(st_global *g)
{
    if (g->window->event.type == sfEvtKeyPressed && \
    g->window->event.key.code == sfKeyRight)
        g->ui->pause_settings->pressed = true;
    if (g->window->event.type == sfEvtKeyReleased && \
    g->window->event.key.code == sfKeyRight) {
        if (g->ui->pause_settings->pressed) {
            if (g->ui->pause_settings->pos_rect <= 2)
                g->ui->pause_settings->pos_rect += 1;
            if (g->ui->pause_settings->pos_rect == 3)
                g->ui->pause_settings->pos_rect = 2;
            g->ui->pause_settings->pressed = false;
        }
    }
}

void set_width_volume_pause_settings(st_global *g)
{
    int x = 0;
    int y = 0;

    if (g->window->event.type == sfEvtMouseButtonPressed && \
    g->window->event.mouseButton.button == sfMouseLeft)
        g->ui->pause_settings->pressed = true;
    if (g->window->event.type == sfEvtMouseButtonReleased && \
    g->window->event.mouseButton.button == sfMouseLeft) {
        x = g->window->event.mouseButton.x;
        y = g->window->event.mouseButton.y;
        if (g->ui->pause_settings->pressed) {
            volume_top_less(g, x, y);
            volume_top_more(g, x, y);
            volume_bottom_less(g, x, y);
            volume_bottom_more(g, x, y);
            g->ui->pause_settings->pressed = false;
        }
    }
}