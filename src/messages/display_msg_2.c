/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** display_msg_2
*/

#include "my_rpg.h"

void display_msg_3(st_global *g)
{
    sfRectangleShape_setPosition(g->text->text_r4, (sfVector2f)\
    {1545 + g->ship->viewrect.left, 1050 + g->ship->viewrect.top});
    sfSprite_setPosition(g->text->arrow_s, (sfVector2f)\
    {1528 + g->ship->viewrect.left, 1045 + g->ship->viewrect.top});
    sfText_setPosition(g->text->text, (sfVector2f){385 +
    g->ship->viewrect.left, 960 + g->ship->viewrect.top});
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
}

void display_msg_2(st_global *g)
{
    clock_dialogue_text_line1(g);
    clock_dialogue_text_line2(g);
    clock_dialogue_text_line3(g);
    sfRectangleShape_setPosition(g->text->whi_r, \
    (sfVector2f){((WIDTH - 1180) / 2) +  g->ship->viewrect.left,
    (HEIGHT - 140) + g->ship->viewrect.top});
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
}

void display_msg(st_global *g)
{
    int c = 0;

    if (g->text->existing) {
        c = backslash_n_counter(g);
        display_msg_2(g);
        display_msg_3(g);
        sfRenderWindow_drawRectangleShape(g->window->window, \
        g->text->whi_r2, NULL);
        sfRenderWindow_drawRectangleShape(g->window->window, \
        g->text->whi_r, NULL);
        if (c >= 3 && sfRectangleShape_getSize(g->text->text_r3).x <= 0)
            sfRenderWindow_drawSprite(g->window->window, g->text->arrow_s, \
            NULL);
    }
}