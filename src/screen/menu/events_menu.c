/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** events_menu
*/

#include "my_rpg.h"

void events_menu(st_global *g)
{
    while (sfRenderWindow_pollEvent(g->window->window, &g->window->event)) {
        if (g->window->event.type == sfEvtClosed || (g->window->event.type ==
        sfEvtKeyPressed && g->window->event.key.code == sfKeyEscape))
            sfRenderWindow_close(g->window->window);
        if (g->window->event.type == sfEvtMouseButtonReleased && \
        g->window->event.mouseButton.button == sfMouseLeft)
            get_global_bounds_menu(g);
    }
}

void get_global_bounds_menu(st_global *g)
{
    g->ui->menu->bounds[0] = \
    sfSprite_getGlobalBounds(g->ui->menu->items[0]->sprite);
    g->ui->menu->bounds[1] = \
    sfSprite_getGlobalBounds(g->ui->menu->items[1]->sprite);
    g->ui->menu->bounds[2] = \
    sfSprite_getGlobalBounds(g->ui->menu->items[2]->sprite);
    for (int i = 0; i < 3; i++)
        if (sfFloatRect_contains(&g->ui->menu->bounds[i], \
        g->window->event.mouseButton.x + 560 + g->ship->viewrect.left, \
        g->window->event.mouseButton.y + g->ship->viewrect.top))
            g->ui->menu->menu = i + 1;
    g->ui->menu->menu = menu_choice(g);
}

int menu_choice(st_global *g)
{
    switch (g->ui->menu->menu) {
        case 1:
            sfRenderWindow_close(g->window->window);
            return (0);
        case 2:
            g->window->screen = 3;
            return (0);
        case 3:
            sfClock_restart(g->ui->fade->timer.clock);
            g->window->screen = 4;
            return (0);
        default:
            return (0);
    }
}