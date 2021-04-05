/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** structs
*/

#ifndef STRUCTS_H_
#define STRUCTS_H_

#include "my_rpg.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

typedef struct st_talk_text_s {
    sfRectangleShape *black_outline;
    sfRectangleShape *purple_outline;
    sfRectangleShape *white_rectangle;
    sfText *talk_text;
    sfFont *talk_font;
    sfSprite *speed_text_sprite_line1;
    sfTexture *speed_text_texture_line1;
    sfSprite *speed_text_sprite_line2;
    sfTexture *speed_text_texture_line2;
    sfSprite *speed_text_sprite_line3;
    sfTexture *speed_text_texture_line3;
    sfIntRect speed_text_rect_line1;
    sfIntRect speed_text_rect_line2;
    sfIntRect speed_text_rect_line3;
    sfBool existing;
    sfClock *clock;
} st_talk_text;


typedef struct st_global_s {
    st_talk_text *talk_text;
} st_global;

#endif /* !STRUCTS_H_ */
