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
        if (g->window->event.type == sfEvtClosed)
            sfRenderWindow_close(g->window->window);
        if (g->window->event.type == sfEvtMouseButtonReleased && \
        g->window->event.mouseButton.button == sfMouseLeft) {
            get_global_bounds_settings(g);
            sfSprite_setTextureRect(g->ui->settings->cancel->sprite, \
            g->ui->settings->cancel->rect);
            sfSprite_setTextureRect(g->ui->settings->save->sprite, \
            g->ui->settings->save->rect);
            g->ui->settings->settings = settings_choice(g);
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
            more_settings_event(g, i);
            g->ui->settings->settings = i + 1;
        }
}

int settings_choice(st_global *g)
{
    switch (g->ui->settings->settings) {
        case 1:
            switch_settings_one(g);
            return (0);
        case 2:
            switch_settings_two(g);
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

    condition_volume_settings(g, x, y);
    if (x >= 670 && y >= 676 && x <= 715 && y <= 720)
        if (g->ui->settings->sfx->rect.width <= 474) {
            g->ui->settings->sfx->rect.width += 32;
            set_volume_sfx(g, \
            sfSound_getVolume(g->window->sfx->click_vol) + 6.66);
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
        g->window->event.mouseButton.y + g->ship->viewrect.top))
            more_button_pressed_event(g, i);
    sfSprite_setTextureRect(g->ui->settings->cancel->sprite, \
    g->ui->settings->cancel->rect);
    sfSprite_setTextureRect(g->ui->settings->save->sprite, \
    g->ui->settings->save->rect);
}