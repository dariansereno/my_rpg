/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** display_msg
*/

#include "my_rpg.h"

void display_msg(sfRenderWindow *window, st_global *global)
{
    int c = 0;

    if (global->var_game->msg && global->text->existing == sfTrue) {
        c = backslash_n_counter(global);
        clock_dialogue_text_line1(global);
        clock_dialogue_text_line2(global);
        clock_dialogue_text_line3(global);
        sfRenderWindow_drawText(window, global->text->text, NULL);
        sfRenderWindow_drawRectangleShape(window, global->text->text_r1, NULL);
        sfRenderWindow_drawRectangleShape(window, global->text->text_r2, NULL);
        sfRenderWindow_drawRectangleShape(window, global->text->text_r3, NULL);
        sfRenderWindow_drawRectangleShape(window, global->text->text_r4, NULL);
        sfRenderWindow_drawRectangleShape(window, global->text->whi_r2, NULL);
        sfRenderWindow_drawRectangleShape(window, global->text->whi_r, NULL);
        if (c >= 3 && sfRectangleShape_getSize(global->text->text_r3).x <= 0)
            sfRenderWindow_drawSprite(window, global->text->arrow_s, NULL);
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