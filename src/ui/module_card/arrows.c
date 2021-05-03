/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** arrows
*/

#include "my_rpg.h"

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