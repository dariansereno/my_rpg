/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** events_pause
*/

#include "my_rpg.h"

void check_pressed_enter_menu(st_global *g)
{
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
}