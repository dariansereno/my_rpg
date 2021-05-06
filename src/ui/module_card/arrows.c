/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** arrows
*/

#include "my_rpg.h"

void buy_module(st_global *g, list_planet pl)
{
    if (g->key_pressed.Enter)
        g->ui->module_card->buy = true;
    if (!g->key_pressed.Enter && g->ui->module_card->buy) {
        if (g->money->money > pl->planet.mod_price[g->ui->module_card->pos_rect
        - 1]) {
            pl->planet.modules[g->ui->module_card->pos_rect - 1] += 1;
            pl->planet.mod_price[g->ui->module_card->pos_rect - 1] =
            (int)pl->planet.mod_price[g->ui->module_card->pos_rect - 1] * 1.5;
            g->money->money -= pl->planet.mod_price[g->ui->module_card->pos_rect
            - 1];
            g->var_game->xp += random_between(5, 15) * g->var_game->mul_xp;
        }
        if (g->ui->module_card->pos_rect == 4)
            pl->planet.mul_housing += 0.8;
        g->ui->module_card->buy = false;
    }
}

void arrow_events_module(st_global *g)
{
    if (g->window->event.type == sfEvtKeyPressed && \
    g->window->event.key.code == sfKeyDown)
        g->ui->module_card->pressed = true;
    if (g->window->event.type == sfEvtKeyReleased && \
    g->window->event.key.code == sfKeyDown) {
        if (g->ui->module_card->pressed) {
            if (g->ui->module_card->pos_rect <= 4)
                g->ui->module_card->pos_rect += 1;
            if (g->ui->module_card->pos_rect == 5)
                g->ui->module_card->pos_rect = 4;
            g->ui->module_card->pressed = false;
        }
    }
    if (g->window->event.type == sfEvtKeyPressed && \
    g->window->event.key.code == sfKeyUp)
            g->ui->module_card->pressed = true;
    if (g->window->event.type == sfEvtKeyReleased && \
    g->window->event.key.code == sfKeyUp) {
        if (g->ui->module_card->pressed) {
            if (g->ui->module_card->pos_rect >= 1)
                g->ui->module_card->pos_rect -= 1;
            if (g->ui->module_card->pos_rect == 0)
                g->ui->module_card->pos_rect = 1;
            g->ui->module_card->pressed = false;
        }
    }
}