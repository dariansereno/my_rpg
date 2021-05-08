/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** text
*/

#include "my_rpg.h"

void destroy_message(st_global *global)
{
    sfSprite_destroy(global->text->arrow_s);
    sfTexture_destroy(global->text->arrow_t);
    sfRectangleShape_destroy(global->text->text_r1);
    sfRectangleShape_destroy(global->text->text_r2);
    sfRectangleShape_destroy(global->text->text_r3);
    sfRectangleShape_destroy(global->text->text_r4);
    sfRectangleShape_destroy(global->text->whi_r);
    sfRectangleShape_destroy(global->text->whi_r2);
    sfRectangleShape_destroy(global->text->white_btm);
    sfClock_destroy(global->text->clock);
    sfText_destroy(global->text->text);
    sfFont_destroy(global->text->font);
    global->text->existing = false;
}