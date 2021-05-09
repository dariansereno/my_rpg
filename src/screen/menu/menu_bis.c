/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** menu_bis
*/

#include "my_rpg.h"

void screen_menu(st_global *g)
{
    sfRenderWindow_clear(g->window->window, sfBlue);
    sfRenderWindow_setView(g->window->window, g->ui->menu->view);
    init_ship_by_choosen(g);
    parallax_menu(g);
    items_menu(g);
    events_menu(g);
    sfSprite_setPosition(g->ui->menu->cursor->sprite, \
    (sfVector2f){sfMouse_getPositionRenderWindow(g->window->window).x + 560 +
    g->ship->viewrect.left, sfMouse_getPositionRenderWindow(g->window->window).y
    + g->ship->viewrect.top});
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->menu->cursor->sprite, NULL);
    sfRenderWindow_display(g->window->window);
}

void destroy_menu(st_menu *menu)
{
    destroy_object(menu->cursor);
    destroy_object(menu->items[0]);
    destroy_object(menu->items[1]);
    destroy_object(menu->items[2]);
    destroy_object(menu->items[3]);
    sfView_destroy(menu->view);
}