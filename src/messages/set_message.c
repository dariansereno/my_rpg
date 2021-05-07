/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** set_message
*/

#include "my_rpg.h"

void dialogue_text_settings(st_global *g)
{
    g->text->str = automatically_set_text_max(g);
    sfText_setCharacterSize(g->text->text, 18);
    sfText_setFont(g->text->text, g->text->font);
    sfText_setLineSpacing(g->text->text, 2.5);
    sfText_setColor(g->text->text, sfBlack);
    sfText_setString(g->text->text, g->text->str);
    sfText_setPosition(g->text->text, (sfVector2f){385 + g->ship->viewrect.left,
    960 + g->ship->viewrect.top});
}

void dialogue_rectangle_settings(st_global *g)
{
    sfRectangleShape_setSize(g->text->whi_r, (sfVector2f){1180, 130});
    sfRectangleShape_setSize(g->text->whi_r2, (sfVector2f){1180, 130});
    sfRectangleShape_setPosition(g->text->whi_r, \
    (sfVector2f){((WIDTH - 1180) / 2) +  g->ship->viewrect.left, (HEIGHT - 140)
    + g->ship->viewrect.top});
    sfRectangleShape_setPosition(g->text->whi_r2, \
    (sfVector2f){((WIDTH - 1180) / 2) + g->ship->viewrect.left, \
    (HEIGHT - 140) + g->ship->viewrect.top});
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
    sfRectangleShape_setPosition(g->text->text_r1, (sfVector2f)\
    {1545 + g->ship->viewrect.left, 960 + g->ship->viewrect.top});
    sfRectangleShape_setPosition(g->text->text_r2, (sfVector2f)\
    {1545 + g->ship->viewrect.left, 990 + g->ship->viewrect.top});
    sfRectangleShape_setPosition(g->text->text_r3, (sfVector2f)\
    {1545 + g->ship->viewrect.left, 1020 + g->ship->viewrect.top});
    sfRectangleShape_setPosition(g->text->text_r4, (sfVector2f)\
    {1545 + g->ship->viewrect.left, 1050 + g->ship->viewrect.top});
}

void dialogue_text(st_global *global)
{
    dialogue_text_settings(global);
    dialogue_rectangle_settings(global);
    global->text->existing = sfTrue;
}

void add_message(st_global *global, char *str, int delay)
{
    global->text = my_malloc(sizeof(*global->text));
    global->text->arrow_s = sfSprite_create();
    global->text->arrow_t = \
    sfTexture_createFromFile("contents/ui/textures/arrow.png", NULL);
    sfSprite_setTexture(global->text->arrow_s, global->text->arrow_t, sfTrue);
    sfSprite_setPosition(global->text->arrow_s, (sfVector2f)\
    {1528 + global->ship->viewrect.left, 1045 + global->ship->viewrect.top});
    global->text->whi_r = sfRectangleShape_create();
    global->text->whi_r2 = sfRectangleShape_create();
    global->text->text_r1 = sfRectangleShape_create();
    global->text->text_r2 = sfRectangleShape_create();
    global->text->text_r3 = sfRectangleShape_create();
    global->text->text_r4 = sfRectangleShape_create();
    global->text->text = sfText_create();
    global->text->font = \
    sfFont_createFromFile("contents/fonts/myfont.otf");
    global->text->clock = sfClock_create();
    global->text->c = generate_cpy();
    global->text->str = str;
    global->text->delay = delay;
    dialogue_text(global);
}