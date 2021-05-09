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