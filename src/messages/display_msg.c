/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** display_msg
*/

#include "my_rpg.h"

st_text *generate_message(void)
{
    st_text *text = my_malloc(sizeof(*text));

    text->arrow_s = sfSprite_create();
    text->arrow_t = \
    sfTexture_createFromFile("contents/ui/textures/arrow.png", NULL);
    text->whi_r = sfRectangleShape_create();
    text->whi_r2 = sfRectangleShape_create();
    text->text_r1 = sfRectangleShape_create();
    text->text_r2 = sfRectangleShape_create();
    text->text_r3 = sfRectangleShape_create();
    text->text_r4 = sfRectangleShape_create();
    text->white_btm = sfRectangleShape_create();
    text->text = sfText_create();
    text->font = \
    sfFont_createFromFile("contents/fonts/dogica/TTF/dogicapixel.ttf");
    text->clock = sfClock_create();
    text->c = generate_cpy();
    text->existing = false;
    return (text);
}

void display_msg(st_global *g)
{
    int c = 0;

    if (g->text->existing) {
        c = backslash_n_counter(g);
        clock_dialogue_text_line1(g);
        clock_dialogue_text_line2(g);
        clock_dialogue_text_line3(g);
        sfRectangleShape_setPosition(g->text->whi_r, \
        (sfVector2f){((WIDTH - 1180) / 2) +  g->ship->viewrect.left, (HEIGHT - 140)
        + g->ship->viewrect.top});
        sfRectangleShape_setPosition(g->text->whi_r2, \
        (sfVector2f){((WIDTH - 1180) / 2) + g->ship->viewrect.left, \
        (HEIGHT - 140) + g->ship->viewrect.top});
        sfRectangleShape_setPosition(g->text->white_btm, \
        (sfVector2f){((WIDTH - 1180) / 2) + g->ship->viewrect.left, \
        (HEIGHT - 140) + g->ship->viewrect.top});
        sfRectangleShape_setPosition(g->text->text_r1, (sfVector2f)\
        {1545 + g->ship->viewrect.left, 960 + g->ship->viewrect.top});
        sfRectangleShape_setPosition(g->text->text_r2, (sfVector2f)\
        {1545 + g->ship->viewrect.left, 990 + g->ship->viewrect.top});
        sfRectangleShape_setPosition(g->text->text_r3, (sfVector2f)\
        {1545 + g->ship->viewrect.left, 1020 + g->ship->viewrect.top});
        sfRectangleShape_setPosition(g->text->text_r4, (sfVector2f)\
        {1545 + g->ship->viewrect.left, 1050 + g->ship->viewrect.top});
        sfSprite_setPosition(g->text->arrow_s, (sfVector2f)\
        {1528 + g->ship->viewrect.left, 1045 + g->ship->viewrect.top});
        sfText_setPosition(g->text->text, (sfVector2f){385 + g->ship->viewrect.left,
        960 + g->ship->viewrect.top});
        sfRenderWindow_drawRectangleShape(g->window->window, \
        g->text->white_btm, NULL);
        sfRenderWindow_drawText(g->window->window, \
        g->text->text, NULL);
        sfRenderWindow_drawRectangleShape(g->window->window, \
        g->text->text_r1, NULL);
        sfRenderWindow_drawRectangleShape(g->window->window, \
        g->text->text_r2, NULL);
        sfRenderWindow_drawRectangleShape(g->window->window, \
        g->text->text_r3, NULL);
        sfRenderWindow_drawRectangleShape(g->window->window, \
        g->text->text_r4, NULL);
        sfRenderWindow_drawRectangleShape(g->window->window, \
        g->text->whi_r2, NULL);
        sfRenderWindow_drawRectangleShape(g->window->window, \
        g->text->whi_r, NULL);
        if (c >= 3 && sfRectangleShape_getSize(g->text->text_r3).x <= 0)
            sfRenderWindow_drawSprite(g->window->window, g->text->arrow_s, \
            NULL);
    }
}

void clock_dialogue_text_line1(st_global *g)
{
    float seconds = 0;
    sfTime time;

    if (sfRectangleShape_getSize(g->text->text_r1).x <= 0)
        return;
    time = sfClock_getElapsedTime(g->text->clock);
    seconds = time.microseconds / 1000;
    if (seconds > ((g->text->delay / 3) * 10 / 1170)) {
        if (sfRectangleShape_getSize(g->text->text_r1).x < 0)
            sfRectangleShape_setSize(g->text->text_r1, (sfVector2f){0, -40});
        sfRectangleShape_setSize(g->text->text_r1, \
        (sfVector2f){sfRectangleShape_getSize(g->text->text_r1).x - 13, -40});
        sfClock_restart(g->text->clock);
    }
}

void clock_dialogue_text_line2(st_global *g)
{
    float seconds = 0;
    sfTime time;

    if (sfRectangleShape_getSize(g->text->text_r1).x > 0 || \
    sfRectangleShape_getSize(g->text->text_r2).x <= 0)
        return;
    time = sfClock_getElapsedTime(g->text->clock);
    seconds = time.microseconds / 1000;
    if (seconds > ((g->text->delay / 3) * 10 / 1170)) {
        if (sfRectangleShape_getSize(g->text->text_r2).x < 0)
            sfRectangleShape_setSize(g->text->text_r2, (sfVector2f){0, -40});
        sfRectangleShape_setSize(g->text->text_r2, \
        (sfVector2f){sfRectangleShape_getSize(g->text->text_r2).x - 10, -40});
        sfClock_restart(g->text->clock);
    }
}

void clock_dialogue_text_line3(st_global *g)
{
    float seconds = 0;
    sfTime time;

    if (sfRectangleShape_getSize(g->text->text_r2).x  > 0 || \
    sfRectangleShape_getSize(g->text->text_r3).x  <= 0)
        return;
    time = sfClock_getElapsedTime(g->text->clock);
    seconds = time.microseconds / 1000;
    if (seconds > ((g->text->delay / 3) * 10 / 1170)) {
        if (sfRectangleShape_getSize(g->text->text_r3).x < 0)
            sfRectangleShape_setSize(g->text->text_r3, \
            (sfVector2f){0, -40});
        sfRectangleShape_setSize(g->text->text_r3, \
        (sfVector2f){sfRectangleShape_getSize(g->text->text_r3).x - 10, -40});
        sfClock_restart(g->text->clock);
    }
}