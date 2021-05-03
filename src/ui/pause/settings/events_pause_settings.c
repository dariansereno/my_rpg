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
    if (g->window->event.type == sfEvtKeyPressed && \
    g->window->event.key.code == sfKeyEnter)
        g->ui->pause_settings->pressed = true;
    if (g->window->event.type == sfEvtKeyReleased && \
    g->window->event.key.code == sfKeyEnter)
        if (g->ui->pause_settings->pressed) {
            switch (g->ui->pause_settings->pos_rect) {
                case 1:
                // cancel
                    g->ui->pause_settings->existing = false;
                    break;
                case 2:
                // save
                    g->ui->pause_settings->existing = false;
                    break;
                default:
                    break;
            }
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
    int x = sfMouse_getPosition(g->window->window).x;
    int y = sfMouse_getPosition(g->window->window).y;

    if (g->window->event.type == sfEvtMouseButtonPressed && \
    g->window->event.mouseButton.button == sfMouseLeft)
        g->ui->pause_settings->pressed = true;
    if (g->window->event.type == sfEvtMouseButtonReleased && \
    g->window->event.mouseButton.button == sfMouseLeft) {
        if (g->ui->pause_settings->existing) {
            if (x >= 782 && y >= 368 && x <= 821 && y <= 400) {
                // - haut
                // enlever 27
                g->ui->pause_settings->ui[2]->rect.width -= 27;
                if (g->ui->pause_settings->ui[2]->rect.width < 14)
                    g->ui->pause_settings->ui[2]->rect.width = 0;
            }
            if (x >= 1116 && y >= 368 && x <= 1155 && y <= 400) {
                if (g->ui->pause_settings->ui[2]->rect.width < 14) {
                    g->ui->pause_settings->ui[2]->rect.width = 14;
                    return;
                }
                g->ui->pause_settings->ui[2]->rect.width += 27;
                //  + haut
                // ajouter 27
            }
            if (x >= 782 && y >= 543 && x <= 821 && y <= 574) {
                //  - bas
                // enlever 27
                if (g->ui->pause_settings->ui[3]->rect.width < 14)
                    g->ui->pause_settings->ui[3]->rect.width = 0;
            }
            if (x >= 1116 && y >= 543 && x <= 1155 && y <= 574) {
                if (g->ui->pause_settings->ui[3]->rect.width < 14) {
                    g->ui->pause_settings->ui[3]->rect.width = 14;
                    return;
                }
                g->ui->pause_settings->ui[2]->rect.width += 27;
                //  + bas
                // ajouter 27
            }
            g->ui->pause_settings->pressed = false;
        }
    }
}