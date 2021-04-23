/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** loading
*/

#include "my_rpg.h"

st_loading *generate_loading_board(void)
{
    st_loading *loading = my_malloc(sizeof(*loading));

    loading->planet = generate_object((sfVector2f){828, 329}, \
    (sfIntRect){0, 0, 48, 48}, "contents/img/sp/terran_c1.png");
    loading->rect[0] = generate_object((sfVector2f){800, 654}, \
    (sfIntRect){0, 0, 320, 10}, "contents/UI/textures/rect_w.png");
    loading->rect[1] = generate_object((sfVector2f){800, 654}, \
    (sfIntRect){0, 0, 0, 10}, "contents/UI/textures/rect_b.png");
    sfSprite_setScale(loading->planet->sprite, (sfVector2f){5.5, 5.5});
    sfSprite_setPosition(loading->planet->sprite, \
    (sfVector2f){loading->planet->pos.x, loading->planet->pos.y});
    sfSprite_setPosition(loading->rect[0]->sprite, \
    (sfVector2f){loading->rect[0]->pos.x, loading->rect[0]->pos.y});
    sfSprite_setPosition(loading->rect[1]->sprite, \
    (sfVector2f){loading->rect[1]->pos.x, loading->rect[1]->pos.y});
    loading->close = false;
    return (loading);
}

void screen_loading(st_global *g)
{
    sfRenderWindow_clear(g->window->window, sfWhite);
    while (sfRenderWindow_pollEvent(g->window->window, &g->window->event)) {
        if (g->window->event.type == sfEvtClosed || (g->window->event.type ==
        sfEvtKeyPressed && g->window->event.key.code == sfKeyEscape))
        sfRenderWindow_close(g->window->window);
    }
    clock_loading_bar(g);
    clock_planet_loading(g);
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->loading_board->planet->sprite, NULL);
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->loading_board->rect[0]->sprite, NULL);
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->loading_board->rect[1]->sprite, NULL);
    if (g->ui->loading_board->close) {
        g->window->screen = 2;
        destroy_loading(g);
        return;
    }
    sfRenderWindow_display(g->window->window);
}

void clock_loading_bar(st_global *g)
{
    sfTime time;
    float seconds = 0;

    sfRenderWindow_setView(g->window->window, g->ui->menu->view);
    time = sfClock_getElapsedTime(g->ui->loading_board->rect[1]->timer->clock);
    seconds = time.microseconds / 1000;
    if (seconds > random_between(100, 500) && \
    g->ui->loading_board->rect[1]->rect.width < 320) {
        g->ui->loading_board->rect[1]->rect.width += random_between(2, 30);
        if (g->ui->loading_board->rect[1]->rect.width >= 320)
            g->ui->loading_board->rect[1]->rect.width = 320;
        sfClock_restart(g->ui->loading_board->rect[1]->timer->clock);
    } else if (seconds > 1200 && \
    g->ui->loading_board->rect[1]->rect.width >= 320) {
        sfClock_restart(g->ui->loading_board->rect[1]->timer->clock);
        g->ui->loading_board->close = true;
    }
    sfSprite_setTextureRect(g->ui->loading_board->rect[1]->sprite, \
    g->ui->loading_board->rect[1]->rect);
}

void clock_planet_loading(st_global *g)
{
    sfTime time;
    float seconds = 0;

    time = sfClock_getElapsedTime(g->ui->loading_board->planet->timer->clock);
    seconds = time.microseconds / 1000;
    if (seconds > 80) {
        g->ui->loading_board->planet->rect.left += 48;
        if (g->ui->loading_board->planet->rect.left > 5712) {
            g->ui->loading_board->planet->rect.left = 0;
            sfClock_restart(g->ui->loading_board->planet->timer->clock);
        } else
            sfClock_restart(g->ui->loading_board->planet->timer->clock);
    }
    sfSprite_setTextureRect(g->ui->loading_board->planet->sprite, \
    g->ui->loading_board->planet->rect);
}

void destroy_loading(st_global *g)
{
    destroy_object(g->ui->loading_board->planet);
    destroy_object(g->ui->loading_board->rect[0]);
    destroy_object(g->ui->loading_board->rect[1]);
}