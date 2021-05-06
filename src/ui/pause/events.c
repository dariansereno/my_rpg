/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** events_pause
*/

#include "my_rpg.h"

void events_pause_up(st_global *g)
{
    if (g->window->event.type == sfEvtKeyPressed && \
    g->window->event.key.code == sfKeyUp)
            g->ui->pause->pressed = true;
    if (g->window->event.type == sfEvtKeyReleased && \
    g->window->event.key.code == sfKeyUp) {
        if (g->ui->pause->pressed) {
            if (g->ui->pause->pos_rect >= 1)
                g->ui->pause->pos_rect -= 1;
            if (g->ui->pause->pos_rect == 0)
                g->ui->pause->pos_rect = 1;
            g->ui->pause->pressed = false;
        }
    }
}

void events_pause_down(st_global *g)
{
    if (g->window->event.type == sfEvtKeyPressed && \
    g->window->event.key.code == sfKeyDown)
        g->ui->pause->pressed = true;
    if (g->window->event.type == sfEvtKeyReleased && \
    g->window->event.key.code == sfKeyDown) {
        if (g->ui->pause->pressed) {
            if (g->ui->pause->pos_rect <= 3)
                g->ui->pause->pos_rect += 1;
            if (g->ui->pause->pos_rect == 4)
                g->ui->pause->pos_rect = 3;
            g->ui->pause->pressed = false;
        }
    }
}

void events_redirect_pause(st_global *g)
{
    if (g->key_pressed.Enter) {
        g->ui->pause->pressed = true;
        switch (g->ui->pause->pos_rect) {
            case 1:
                g->ui->pause->existing = false;
                break;
            case 2:
                g->ui->pause_settings->existing = true;
                g->window->music_volume = sfMusic_getVolume(g->window->music);
                g->window->width_volume = \
                g->ui->pause_settings->ui[2]->rect.width;
                break;
            case 3:
                screen_game(g);
                g->ui->pause->existing = false;
                break;
            default:
                break;
        }
        g->ui->pause->pressed = false;
    }
}

void text_pause(st_global *g)
{
    sfText_setCharacterSize(g->ui->pause->text, 50);
    sfText_setColor(g->ui->pause->text, sfColor_fromRGB(179, 130, 188));
    sfText_setString(g->ui->pause->text, "play game");
    sfText_setPosition(g->ui->pause->text, \
    (sfVector2f){g->ship->viewrect.left + 844, g->ship->viewrect.top + 312});
    sfRenderWindow_drawText(g->window->window, g->ui->pause->text, NULL);
    sfText_setString(g->ui->pause->text, "settings");
    sfText_setPosition(g->ui->pause->text, \
    (sfVector2f){g->ship->viewrect.left + 861, g->ship->viewrect.top + 504});
    sfRenderWindow_drawText(g->window->window, g->ui->pause->text, NULL);
    sfText_setString(g->ui->pause->text, "quit game");
    sfText_setPosition(g->ui->pause->text, \
    (sfVector2f){g->ship->viewrect.left + 844, g->ship->viewrect.top + 677});
    sfRenderWindow_drawText(g->window->window, g->ui->pause->text, NULL);
}