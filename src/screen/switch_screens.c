/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** switch_screens
*/

#include "my_rpg.h"

void switch_screen_one(st_global *g, sfVideoMode mode)
{
    if (g->window->bool_load == true) {
        sfRenderWindow_destroy(g->window->window);
        g->window->window = sfRenderWindow_create(mode, "Space Civ",
        sfTitlebar | sfClose | sfResize, NULL);
        sfRenderWindow_setFramerateLimit(g->window->window, 120);
        sfRenderWindow_setMouseCursorVisible(g->window->window, sfFalse);
        g->window->bool_load = false;
    }
    screen_loading(g);
}

void switch_screen_two(st_global *g)
{
    if (g->window->bool_menu) {
        sfView_destroy(g->ui->menu->view);
        g->ui->menu->view = sfView_createFromRect((sfFloatRect)\
        {g->ship->viewrect.left + 560, \
        g->ship->viewrect.top, 800, 1080});
        g->window->bool_menu = false;
    }
}

void switch_screen_four(st_global *g)
{
    if (g->window->bool_game) {
        sfRenderWindow_destroy(g->window->window);
        g->window->window = sfRenderWindow_create(g->window->mode, "Space Civ",
        sfTitlebar | sfClose | sfResize, NULL);
        sfRenderWindow_setFramerateLimit(g->window->window, 120);
        sfRenderWindow_setMouseCursorVisible(g->window->window, sfFalse);
        g->window->bool_game = false;
    }
}

void switch_screen_five(st_global *g)
{
    sfVideoMode mode = {800, 1080, 32};

    g->ui->end->existing = false;
    g->window->bool_menu = true;
    g->window->bool_game = true;
    g->ui->end->pressed = false;
    g->window->screen = 2;
    if (g->window->bool_menu) {
        sfRenderWindow_destroy(g->window->window);
        g->window->window = sfRenderWindow_create(mode, "Space Civ",
        sfTitlebar | sfClose | sfResize, NULL);
        sfRenderWindow_setMouseCursorVisible(g->window->window, sfFalse);
        g->ui->menu->view = sfView_createFromRect((sfFloatRect)\
        {g->ship->viewrect.left + 560, \
        g->ship->viewrect.top, 800, 1080});
        g->window->bool_menu = false;
    }
}