/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** arrows
*/

#include "my_rpg.h"

void arrow_events_trade(st_global *g)
{
    if (g->window->event.type == sfEvtKeyPressed && \
    g->window->event.key.code == sfKeyDown)
        g->ui->trade_card->pressed = true;
    if (g->window->event.type == sfEvtKeyReleased && \
    g->window->event.key.code == sfKeyDown) {
        if (g->ui->trade_card->pressed) {
            if (g->ui->trade_card->pos_rect <= 2)
                g->ui->trade_card->pos_rect += 1;
            if (g->ui->trade_card->pos_rect == 3)
                g->ui->trade_card->pos_rect = 2;
            g->ui->trade_card->pressed = false;
        }
    }
    if (g->window->event.type == sfEvtKeyPressed && \
    g->window->event.key.code == sfKeyUp)
        g->ui->trade_card->pressed = true;
    if (g->window->event.type == sfEvtKeyReleased && \
    g->window->event.key.code == sfKeyUp) {
        if (g->ui->trade_card->pressed) {
            if (g->ui->trade_card->pos_rect >= 0)
                g->ui->trade_card->pos_rect -= 1;
            if (g->ui->trade_card->pos_rect < 0)
                g->ui->trade_card->pos_rect = 0;
            g->ui->trade_card->pressed = false;
        }
    }
}

void arrow_texture(st_global *g)
{
    if (g->ui->trade_card->counter <= 3) {
        sfRenderWindow_drawSprite(g->window->window, \
        g->ui->trade_card->ui[0]->sprite, NULL);
        sfRenderWindow_drawSprite(g->window->window, \
        g->ui->trade_card->ui[2]->sprite, NULL);
    } else {
        if (g->ui->trade_card->counter - g->ui->trade_card->first_cell >= 3)
            sfRenderWindow_drawSprite(g->window->window, \
            g->ui->trade_card->ui[3]->sprite, NULL);
        else
            sfRenderWindow_drawSprite(g->window->window, \
            g->ui->trade_card->ui[2]->sprite, NULL);
        if (g->ui->trade_card->first_cell > 1)
            sfRenderWindow_drawSprite(g->window->window, \
            g->ui->trade_card->ui[1]->sprite, NULL);
        else
            sfRenderWindow_drawSprite(g->window->window, \
            g->ui->trade_card->ui[0]->sprite, NULL);
    }
}