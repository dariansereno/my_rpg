/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** screen
*/

#include "my_rpg.h"

void screen(st_global *g)
{
    sfVideoMode mode = {800, 1080, 32};

    switch (g->window->screen) {
        case 1:
            switch_screen_one(g, mode);
            break;
        case 2:
            switch_screen_two(g);
            screen_menu(g);
            break;
        case 3:
            screen_settings(g);
            break;
        case 4:
            switch_screen_four(g);
            screen_game(g);
            break;
        default:
            break;
    }
}

void screen_game(st_global *ad)
{
    ad->ship->view = sfView_createFromRect(ad->ship->viewrect);
    if (ad->ui->fade->fade == false) {
        planet_collision(ad);
        display_on_view(ad);
        display_on_view_spaceobj(ad);
        interaction(ad);
        check_status(ad);
        if (ad->ui->planet_card->existing == false && \
        ad->ui->trade_card->existing == false && \
        ad->ui->module_card->existing == false && \
        ad->ui->pause->existing == false && ad->ui->end->existing == false)
            paralax_move(ad);
    } else
        display_fade(ad);
}

void fade_update_size(st_global *g, int nb)
{
    sfRectangleShape_setSize(g->ui->fade->rect[0], \
    (sfVector2f){sfRectangleShape_getSize(g->ui->fade->rect[0]).x, \
    sfRectangleShape_getSize(g->ui->fade->rect[0]).y - nb});
    sfRectangleShape_setSize(g->ui->fade->rect[1], \
    (sfVector2f){sfRectangleShape_getSize(g->ui->fade->rect[1]).x, \
    sfRectangleShape_getSize(g->ui->fade->rect[1]).y + nb});
    sfClock_restart(g->ui->fade->timer.clock);
}