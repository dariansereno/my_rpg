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
        events_pause_up_bis(g);
    }
    events_pause_down(g);
    events_redirect_pause(g);
    rect_position_pause(g);
}

void events_pause_down(st_global *g)
{
    if (g->window->event.type == sfEvtKeyPressed && \
    g->window->event.key.code == sfKeyDown)
        g->ui->pause->pressed = true;
    if (g->window->event.type == sfEvtKeyReleased && \
    g->window->event.key.code == sfKeyDown)
        events_pause_down_bis(g);
}

void switch_volume_settings(st_global *g)
{
    g->ui->pause_settings->existing = true;
    g->window->music_volume = sfMusic_getVolume(g->window->music);
    g->window->width_volume_pause = \
    g->ui->pause_settings->ui[2]->rect.width;
    g->window->sfx_volume = \
    sfSound_getVolume(g->window->sfx->click_vol);
    g->window->width_sfx_pause = \
    g->ui->pause_settings->ui[3]->rect.width;
}

void events_redirect_pause(st_global *g)
{
    if (g->key_pressed.Enter) {
        g->ui->pause->pressed = true;
        switch (g->ui->pause->pos_rect) {
            case 1:
                g->ui->pause->existing = false;
                g->window->bool_menu = true;
                g->window->bool_game = true;
                g->ui->pause->pressed = false;
                g->window->screen = 2;
                g->key_pressed.Enter = false;
                switch_screen_five(g);
                return;
            case 2:
                switch_volume_settings(g);
                break;
            case 3:
                sfRenderWindow_close(g->window->window);
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
    sfText_setString(g->ui->pause->text, "menu game");
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