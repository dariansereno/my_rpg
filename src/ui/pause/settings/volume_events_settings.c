/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** volume_event_settings
*/

#include "my_rpg.h"

void switch_pause_settings(st_global *g)
{
    switch (g->ui->pause_settings->pos_rect) {
        case 1:
            sfMusic_setVolume(g->window->music, g->window->music_volume);
            set_volume_sfx(g, g->window->sfx_volume);
            g->ui->pause_settings->ui[2]->rect.width = \
            g->window->width_volume_pause;
            g->ui->pause_settings->ui[3]->rect.width = \
            g->window->width_sfx_pause;
            g->ui->pause_settings->existing = false;
            break;
        case 2:
            g->ui->pause_settings->existing = false;
            break;
        default:
            break;
    }
}

void volume_top_less(st_global *g, int x, int y)
{
    if (x >= 762 && y >= 354 && x <= 826 && y <= 402 && \
    g->ui->pause_settings->ui[2]->rect.width <= 253) {
        sfSound_play(g->window->sfx->click_vol);
        g->ui->pause_settings->ui[2]->rect.width -= 26;
        sfMusic_setVolume(g->window->music, \
        sfMusic_getVolume(g->window->music) - 10);
        if (g->ui->pause_settings->ui[2]->rect.width < 14) {
            g->ui->pause_settings->ui[2]->rect.width = 0;
            sfMusic_setVolume(g->window->music, 0);
        }
    }
}

void volume_top_more(st_global *g, int x, int y)
{
    if (x >= 1084 && y >= 348 && x <= 1155 && y <= 400 && \
    g->ui->pause_settings->ui[2]->rect.width <= 253) {
        sfSound_play(g->window->sfx->click_vol);
        if (g->ui->pause_settings->ui[2]->rect.width < 13) {
            g->ui->pause_settings->ui[2]->rect.width = 13;
            sfMusic_setVolume(g->window->music, 10);
            g->ui->pause_settings->pressed = false;
            return;
        }
        g->ui->pause_settings->ui[2]->rect.width += 27;
        if (g->ui->pause_settings->ui[2]->rect.width > 253)
            g->ui->pause_settings->ui[2]->rect.width = 253;
        sfMusic_setVolume(g->window->music, \
        sfMusic_getVolume(g->window->music) + 10);
    }
}

void volume_bottom_less(st_global *g, int x, int y)
{
    if (x >= 761 && y >= 511 && x <= 821 && y <= 574 && \
    g->ui->pause_settings->ui[3]->rect.width <= 253) {
        sfSound_play(g->window->sfx->click_vol);
        g->ui->pause_settings->ui[3]->rect.width -= 26;
        set_volume_sfx(g, \
        sfSound_getVolume(g->window->sfx->click_vol) - 10);
        if (g->ui->pause_settings->ui[3]->rect.width < 14) {
            g->ui->pause_settings->ui[3]->rect.width = 0;
            set_volume_sfx(g, 0);
        }
    }
}

void volume_bottom_more(st_global *g, int x, int y)
{
    if (x >= 1086 && y >= 511 && x <= 1155 && y <= 578 && \
    g->ui->pause_settings->ui[3]->rect.width <= 253) {
        sfSound_play(g->window->sfx->click_vol);
        if (g->ui->pause_settings->ui[3]->rect.width < 13) {
            g->ui->pause_settings->ui[3]->rect.width = 13;
            set_volume_sfx(g, 10);
            g->ui->pause_settings->pressed = false;
            return;
        }
        g->ui->pause_settings->ui[3]->rect.width += 27;
        if (g->ui->pause_settings->ui[3]->rect.width > 253)
            g->ui->pause_settings->ui[3]->rect.width = 253;
        set_volume_sfx(g, \
        sfSound_getVolume(g->window->sfx->click_vol) + 10);
    }
}