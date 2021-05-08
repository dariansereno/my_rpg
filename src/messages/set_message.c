/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** set_message
*/

#include "my_rpg.h"

void dialogue_text_settings(st_global *g)
{
    automatically_set_text_max(g);
    sfText_setCharacterSize(g->text->text, 18);
    sfText_setFont(g->text->text, g->text->font);
    sfText_setLineSpacing(g->text->text, 2.5);
    sfText_setColor(g->text->text, sfBlack);
    sfText_setString(g->text->text, g->text->str);
}

void dialogue_rectangle_settings(st_global *g)
{
    sfRectangleShape_setSize(g->text->whi_r, (sfVector2f){1180, 130});
    sfRectangleShape_setSize(g->text->whi_r2, (sfVector2f){1180, 130});
    sfRectangleShape_setSize(g->text->white_btm, (sfVector2f){1180, 130});
    sfRectangleShape_setFillColor(g->text->white_btm, sfWhite);
    sfRectangleShape_setFillColor(g->text->whi_r, \
    sfColor_fromRGBA(255, 255, 255, 0));
    sfRectangleShape_setOutlineColor(g->text->whi_r, \
    sfColor_fromRGB(77, 17, 84));
    sfRectangleShape_setOutlineThickness(g->text->whi_r, 5);
    sfRectangleShape_setFillColor(g->text->whi_r2, \
    sfColor_fromRGBA(255, 255, 255, 0));
    dialogue_rectangle_settings_bis(g);
}

void dialogue_rectangle_settings_bis(st_global *g)
{
    sfRectangleShape_setOutlineColor(g->text->whi_r2, sfBlack);
    sfRectangleShape_setOutlineThickness(g->text->whi_r2, 10);
    sfRectangleShape_setSize(g->text->text_r1, (sfVector2f){1160, -40});
    sfRectangleShape_setSize(g->text->text_r2, (sfVector2f){1160, -40});
    sfRectangleShape_setSize(g->text->text_r3, (sfVector2f){1160, -40});
    sfRectangleShape_setSize(g->text->text_r4, (sfVector2f){1160, -40});
    sfRectangleShape_setRotation(g->text->text_r1, 180);
    sfRectangleShape_setRotation(g->text->text_r2, 180);
    sfRectangleShape_setRotation(g->text->text_r3, 180);
    sfRectangleShape_setRotation(g->text->text_r4, 180);
}

void dialogue_text(st_global *global)
{
    dialogue_text_settings(global);
    dialogue_rectangle_settings(global);
    global->text->existing = true;
}

void add_message(st_global *g, char *str, int delay)
{
    g->text->c->begin = 0;
    g->text->c->end = 0;
    g->text->c->len = 0;
    sfSprite_setTexture(g->text->arrow_s, g->text->arrow_t, sfTrue);
    g->text->str = str;
    g->text->delay = delay;
    dialogue_text(g);
}