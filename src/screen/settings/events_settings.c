/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** events_settings
*/

#include "my_rpg.h"

void events_settings(st_global *g)
{
    sfRenderWindow_clear(g->window->window, sfWhite);
    while (sfRenderWindow_pollEvent(g->window->window, &g->window->event)) {
        if (g->window->event.type == sfEvtClosed || (g->window->event.type ==
        sfEvtKeyPressed &&  g->window->event.key.code == sfKeyEscape))
            sfRenderWindow_close(g->window->window);
        if (g->window->event.type == sfEvtMouseButtonReleased && \
        g->window->event.mouseButton.button == sfMouseLeft) {
            get_global_bounds_settings(g);
            control_volumes_settings(g);
        }
        if (g->window->event.type == sfEvtMouseButtonPressed && \
        g->window->event.mouseButton.button == sfMouseLeft)
            animate_buttons_settings(g);
    }
}

void get_global_bounds_settings(st_global *g)
{
    g->ui->settings->bounds[0] = \
    sfSprite_getGlobalBounds(g->ui->settings->cancel->sprite);
    g->ui->settings->bounds[1] = \
    sfSprite_getGlobalBounds(g->ui->settings->save->sprite);
    g->ui->settings->bounds[2] = \
    sfSprite_getGlobalBounds(g->ui->settings->cross->sprite);
    for (int i = 0; i < 3; i++)
        if (sfFloatRect_contains(&g->ui->settings->bounds[i], \
        g->window->event.mouseButton.x + 560 + g->ship->viewrect.left,
        g->window->event.mouseButton.y + g->ship->viewrect.top)) {
            if (i == 0)
                g->ui->settings->cancel->rect.left = 0;
            else if (i == 1)
                g->ui->settings->save->rect.left = 0;
            g->ui->settings->settings = i + 1;
        }
    sfSprite_setTextureRect(g->ui->settings->cancel->sprite, \
    g->ui->settings->cancel->rect);
    sfSprite_setTextureRect(g->ui->settings->save->sprite, \
    g->ui->settings->save->rect);
    g->ui->settings->settings = settings_choice(g);
}

int settings_choice(st_global *g)
{
    switch (g->ui->settings->settings) {
        case 1:
            sfMusic_setVolume(g->window->music, g->window->music_volume);
            g->ui->settings->music->rect.width = \
            (sfMusic_getVolume(g->window->music) * 15 / 100) * 32;
            set_volume_sfx(g, g->window->sfx_volume);
            g->ui->settings->sfx->rect.width = \
            (sfSound_getVolume(g->window->sfx->explosion) * 15 / 100) * 32;
            g->window->screen = 2;
            return (0);
        case 2:
            g->window->music_volume = sfMusic_getVolume(g->window->music);
            g->ui->settings->music->rect.width = g->window->width_volume;
            g->window->sfx_volume = \
            sfSound_getVolume(g->window->sfx->explosion);
            g->ui->settings->sfx->rect.width = g->window->width_sfx;
            g->window->screen = 2;
            return (0);
        case 3:
            sfRenderWindow_close(g->window->window);
            return (0);
        default:
            return (0);
    }
}

void control_volumes_settings(st_global *g)
{
    int x = g->window->event.mouseButton.x;
    int y = g->window->event.mouseButton.y;

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
        if (g->ui->settings->sfx->rect.width >= 58)
            g->ui->settings->sfx->rect.width -= 32; {
            set_volume_sfx(g, \
            sfSound_getVolume(g->window->sfx->explosion) - 6.66);
            }
    if (x >= 670 && y >= 676 && x <= 715 && y <= 720)
        if (g->ui->settings->sfx->rect.width <= 474) {
            g->ui->settings->sfx->rect.width += 32;
            set_volume_sfx(g, \
            sfSound_getVolume(g->window->sfx->explosion) + 6.66);
        }
    sfSprite_setTextureRect(g->ui->settings->music->sprite, \
    g->ui->settings->music->rect);
    sfSprite_setTextureRect(g->ui->settings->sfx->sprite, \
    g->ui->settings->sfx->rect);
}

void animate_buttons_settings(st_global *g)
{
    g->ui->settings->bounds[0] = \
    sfSprite_getGlobalBounds(g->ui->settings->cancel->sprite);
    g->ui->settings->bounds[1] = \
    sfSprite_getGlobalBounds(g->ui->settings->save->sprite);
    for (int i = 0; i < 2; i++)
        if (sfFloatRect_contains(&g->ui->settings->bounds[i], \
        g->window->event.mouseButton.x + 560 + g->ship->viewrect.left, 
        g->window->event.mouseButton.y + g->ship->viewrect.top)) {
            if (i == 0)
                g->ui->settings->cancel->rect.left = 141;
            else if (i == 1)
                g->ui->settings->save->rect.left = 141;
        }
    sfSprite_setTextureRect(g->ui->settings->cancel->sprite, \
    g->ui->settings->cancel->rect);
    sfSprite_setTextureRect(g->ui->settings->save->sprite, \
    g->ui->settings->save->rect);
}