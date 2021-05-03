/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** fade
*/

#include "my_rpg.h"

st_fade *generate_fade(void)
{
    st_fade *fade = my_malloc(sizeof(*fade));

    fade->fade = true;
    fade->rect[0] = sfRectangleShape_create();
    fade->rect[1] = sfRectangleShape_create();
    sfRectangleShape_setSize(fade->rect[0], (sfVector2f){1920, 540});
    sfRectangleShape_setSize(fade->rect[1], (sfVector2f){1920, -540});
    sfRectangleShape_setPosition(fade->rect[0], (sfVector2f){0, 0});
    sfRectangleShape_setPosition(fade->rect[1], (sfVector2f){0, 1080});
    sfRectangleShape_setFillColor(fade->rect[0], sfBlack);
    sfRectangleShape_setFillColor(fade->rect[1], sfBlack);
    fade->timer.clock = sfClock_create();
    return (fade);
}

void display_fade(st_global *g)
{
    sfRenderWindow_clear(g->window->window, sfWhite);
    while (sfRenderWindow_pollEvent(g->window->window, &g->window->event))
        if (g->window->event.type == sfEvtClosed || (g->window->event.type ==
        sfEvtKeyPressed &&  g->window->event.key.code == sfKeyEscape))
            sfRenderWindow_close(g->window->window);
    clock_fade(g);
    background_space_fade(g);
    if (sfRectangleShape_getSize(g->ui->fade->rect[0]).y <= 0 && \
    sfRectangleShape_getSize(g->ui->fade->rect[1]).y >= 0)
        g->ui->fade->fade = false;
    sfRenderWindow_drawRectangleShape(g->window->window, \
    g->ui->fade->rect[0], NULL);
    sfRenderWindow_drawRectangleShape(g->window->window, \
    g->ui->fade->rect[1], NULL);
    sfRenderWindow_display(g->window->window);
}

void background_space_fade(st_global *g)
{
    sfRenderWindow_setView(g->window->window, g->ship->view);
    sfSprite_setTexture(g->ship->bship, g->ship->bshipt, sfTrue);
    sfSprite_setTexture(g->paralax->nebula, g->paralax->nebulat, sfTrue);
    sfSprite_setTexture(g->paralax->star, g->paralax->start, sfTrue);
    sfSprite_setTextureRect(g->paralax->star, g->paralax->starr);
    sfSprite_setTextureRect(g->paralax->nebula, g->paralax->paralaxr);
    sfSprite_setPosition(g->ship->bship, g->ship->bshippos);
    sfSprite_setPosition(g->paralax->nebula, g->paralax->nebulapos);
    sfSprite_setPosition(g->paralax->star, g->paralax->starpos);
    sfRenderWindow_drawSprite(g->window->window, g->paralax->nebula, NULL);
    sfRenderWindow_drawSprite(g->window->window, g->paralax->star, NULL);
    sfRenderWindow_drawSprite(g->window->window, g->ship->bship, NULL);
}

void clock_fade(st_global *g)
{
    sfTime time;
    float seconds = 0;

    time = sfClock_getElapsedTime(g->ui->fade->timer.clock);
    seconds = time.microseconds / 1000;
    if (seconds > 700 && \
    sfRectangleShape_getSize(g->ui->fade->rect[0]).y == 540 && \
    sfRectangleShape_getSize(g->ui->fade->rect[1]).y == -540)
        fade_update_size(g, 1);
    else if (seconds > 70 && \
    sfRectangleShape_getSize(g->ui->fade->rect[0]).y < 540 && \
    sfRectangleShape_getSize(g->ui->fade->rect[1]).y > -540)
        fade_update_size(g, 10);
}

void destroy_fade(st_fade *fade)
{
    sfRectangleShape_destroy(fade->rect[0]);
    sfRectangleShape_destroy(fade->rect[1]);
    sfClock_destroy(fade->timer.clock);
}