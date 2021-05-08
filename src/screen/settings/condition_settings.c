/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** condition_settings
*/

#include "my_rpg.h"

void condition_volume_settings(st_global *g, int x, int y)
{
    if (x >= 83 && y >= 516 && x <= 127 && y <= 560)
        if (g->ui->settings->music->rect.width >= 58) {
            g->ui->settings->music->rect.width -= 32;
            sfMusic_setVolume(g->window->music, \
            sfMusic_getVolume(g->window->music) - 6.66);
        }
    if (x >= 671 && y >= 517 && x <= 715 && y <= 562)
        if (g->ui->settings->music->rect.width <= 474) {
            g->ui->settings->music->rect.width += 32;
            sfMusic_setVolume(g->window->music, \
            sfMusic_getVolume(g->window->music) + 6.66);
        }
    if (x >= 82 && y >= 676 && x <= 127 && y <= 721)
        if (g->ui->settings->sfx->rect.width >= 58) {
            g->ui->settings->sfx->rect.width -= 32;
            set_volume_sfx(g, \
            sfSound_getVolume(g->window->sfx->click_vol) - 6.66);
        }
}

void switch_settings_one(st_global *g)
{
    sfMusic_setVolume(g->window->music, g->window->music_volume);
    g->ui->settings->music->rect.width = \
    (sfMusic_getVolume(g->window->music) * 15 / 100) * 32;
    set_volume_sfx(g, g->window->sfx_volume);
    g->ui->settings->sfx->rect.width = \
    (sfSound_getVolume(g->window->sfx->click_vol) * 15 / 100) * 32;
    g->window->screen = 2;
}

void switch_settings_two(st_global *g)
{
    g->window->music_volume = sfMusic_getVolume(g->window->music);
    g->ui->settings->music->rect.width = g->window->width_volume;
    g->window->sfx_volume = \
    sfSound_getVolume(g->window->sfx->click_vol);
    g->ui->settings->sfx->rect.width = g->window->width_sfx;
    g->window->screen = 2;
}