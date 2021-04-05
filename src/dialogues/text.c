/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** text
*/

#include "my_rpg.h"

const char *add_backslash_n(char *str, st_global *global)
{
    sfFloatRect bounds;
    char *tocopy = my_malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 0;

    tocopy = my_strcpy(tocopy, str);
    sfText_setString(global->talk_text->talk_text, tocopy);
    bounds = sfText_getGlobalBounds(global->talk_text->talk_text);
    while (bounds.width > 1170) {
        tocopy = my_strcpy(tocopy, str);
        if (i == 0)
            for (; tocopy[i]; i++) {}
        tocopy[i + 1] = '\n';
        i -= 1;
        sfText_setString(global->talk_text->talk_text, tocopy);
        bounds = sfText_getGlobalBounds(global->talk_text->talk_text);
        printf("%f %s\n", bounds.width, tocopy);
    }
    return (tocopy);
}

void dialogue_text_settings(st_global *global, const char *str)
{
    sfFloatRect bounds;

    sfText_setCharacterSize(global->talk_text->talk_text, 18);
    sfText_setFont(global->talk_text->talk_text, global->talk_text->talk_font);
    sfText_setLineSpacing(global->talk_text->talk_text, 2.5);
    sfText_setColor(global->talk_text->talk_text, sfBlack);
    sfText_setString(global->talk_text->talk_text, str);
    bounds = sfText_getGlobalBounds(global->talk_text->talk_text);
    sfText_setPosition(global->talk_text->talk_text, (sfVector2f){385, 955});
    // str = add_backslash_n(str, global);
}

void dialogue_rectangle_settings(st_global *global)
{
    sfRectangleShape_setSize(global->talk_text->white_rectangle, (sfVector2f){1180, 130});
    sfRectangleShape_setSize(global->talk_text->purple_outline, (sfVector2f){1190, 140});
    sfRectangleShape_setSize(global->talk_text->black_outline, (sfVector2f){1200, 150});
    sfRectangleShape_setPosition(global->talk_text->white_rectangle, (sfVector2f){(WIDTH - 1180) / 2, HEIGHT - 140});
    sfRectangleShape_setPosition(global->talk_text->purple_outline, (sfVector2f){(WIDTH - 1190) / 2, HEIGHT - 145});
    sfRectangleShape_setPosition(global->talk_text->black_outline, (sfVector2f){(WIDTH - 1200) / 2, HEIGHT - 150});
    sfRectangleShape_setFillColor(global->talk_text->black_outline, sfBlack);
    sfRectangleShape_setFillColor(global->talk_text->purple_outline, sfColor_fromRGB(77, 17, 84));
    sfRectangleShape_setFillColor(global->talk_text->white_rectangle, sfWhite);
    sfSprite_setPosition(global->talk_text->speed_text_sprite_line1, (sfVector2f){385, 955});
    sfSprite_setPosition(global->talk_text->speed_text_sprite_line2, (sfVector2f){385, 955});
    sfSprite_setPosition(global->talk_text->speed_text_sprite_line3, (sfVector2f){385, 955});
    sfSprite_setTexture(global->talk_text->speed_text_sprite_line1, global->talk_text->speed_text_texture_line1, sfTrue);
    sfSprite_setTexture(global->talk_text->speed_text_sprite_line2, global->talk_text->speed_text_texture_line2, sfTrue);
    sfSprite_setTexture(global->talk_text->speed_text_sprite_line3, global->talk_text->speed_text_texture_line3, sfTrue);
    sfSprite_setTextureRect(global->talk_text->speed_text_sprite_line1, global->talk_text->speed_text_rect_line1);
    sfSprite_setTextureRect(global->talk_text->speed_text_sprite_line2, global->talk_text->speed_text_rect_line2);
    sfSprite_setTextureRect(global->talk_text->speed_text_sprite_line3, global->talk_text->speed_text_rect_line3);
    sfSprite_setRotation(global->talk_text->speed_text_sprite_line1, 180);
    sfSprite_setRotation(global->talk_text->speed_text_sprite_line2, 180);
    sfSprite_setRotation(global->talk_text->speed_text_sprite_line3, 180);
    sfSprite_setPosition(global->talk_text->speed_text_sprite_line1, (sfVector2f){1545, 990});
    sfSprite_setPosition(global->talk_text->speed_text_sprite_line2, (sfVector2f){1545, 1020});
    sfSprite_setPosition(global->talk_text->speed_text_sprite_line3, (sfVector2f){1545, 1050});
    global->talk_text->speed_text_rect_line1.width = 1160;
    global->talk_text->speed_text_rect_line1.height = 40;
    global->talk_text->speed_text_rect_line2.width = 1160;
    global->talk_text->speed_text_rect_line2.height = 40;
    global->talk_text->speed_text_rect_line3.width = 1160;
    global->talk_text->speed_text_rect_line3.height = 40;
}

void dialogue_text(st_global *global, const char *str, int delay)
{
    dialogue_text_settings(global, str);
    dialogue_rectangle_settings(global);
    global->talk_text->existing = sfTrue;
    // sfText_setPosition(global->talk_text->talk_text, (sfVector2f){(WIDTH - (bounds.width + 100)) / 2, HEIGHT - (bounds.height + 40)});
    // sfRectangleShape_setSize(global->talk_text->purple_outline, (sfVector2f){832, bounds.height + 50});
    // sfRectangleShape_setPosition(global->talk_text->purple_outline, (sfVector2f){((WIDTH - (bounds.width + 100)) / 2), HEIGHT - (bounds.height + 40)});
}

void display_dialogue_text(sfRenderWindow *window, st_global *global)
{
    if (global->talk_text->existing == sfTrue) {
        sfRenderWindow_drawRectangleShape(window, global->talk_text->black_outline, NULL);
        sfRenderWindow_drawRectangleShape(window, global->talk_text->purple_outline, NULL);
        sfRenderWindow_drawRectangleShape(window, global->talk_text->white_rectangle, NULL);
        sfRenderWindow_drawText(window, global->talk_text->talk_text, NULL);
        sfSprite_setTextureRect(global->talk_text->speed_text_sprite_line1, global->talk_text->speed_text_rect_line1);
        sfSprite_setTextureRect(global->talk_text->speed_text_sprite_line2, global->talk_text->speed_text_rect_line2);
        sfSprite_setTextureRect(global->talk_text->speed_text_sprite_line3, global->talk_text->speed_text_rect_line3);
        sfRenderWindow_drawSprite(window, global->talk_text->speed_text_sprite_line1, NULL);
        sfRenderWindow_drawSprite(window, global->talk_text->speed_text_sprite_line2, NULL);
        sfRenderWindow_drawSprite(window, global->talk_text->speed_text_sprite_line3, NULL);
    }
}

void clock_dialogue_text_line1(st_global *global)
{
    float seconds = 0;
    sfTime time;

    if (global->talk_text->speed_text_rect_line1.width <= 0)
        return;
    if (global->talk_text->existing == sfTrue) {
        time = sfClock_getElapsedTime(global->talk_text->clock);
        seconds = time.microseconds / 1000;
        if (seconds > 5) {
            if (global->talk_text->speed_text_rect_line1.width < 0)
                global->talk_text->speed_text_rect_line1.width = 0;
            global->talk_text->speed_text_rect_line1.width -= 10;
            sfClock_restart(global->talk_text->clock);
        }
    }
}

void clock_dialogue_text_line2(st_global *global)
{
    float seconds = 0;
    sfTime time;

    if (global->talk_text->speed_text_rect_line1.width > 0 || \
    global->talk_text->speed_text_rect_line2.width <= 0)
        return;
    if (global->talk_text->existing == sfTrue) {
        time = sfClock_getElapsedTime(global->talk_text->clock);
        seconds = time.microseconds / 1000;
        if (seconds > 5) {
            if (global->talk_text->speed_text_rect_line2.width < 0)
                global->talk_text->speed_text_rect_line2.width = 0;
            global->talk_text->speed_text_rect_line2.width -= 10;
            sfClock_restart(global->talk_text->clock);
        }
    }
}

void clock_dialogue_text_line3(st_global *global)
{
    float seconds = 0;
    sfTime time;

    if (global->talk_text->speed_text_rect_line2.width > 0 || \
    global->talk_text->speed_text_rect_line3.width <= 0)
        return;
    if (global->talk_text->existing == sfTrue) {
        time = sfClock_getElapsedTime(global->talk_text->clock);
        seconds = time.microseconds / 1000;
        if (seconds > 5) {
        printf("%d %f\n", global->talk_text->speed_text_rect_line3.width, seconds);
            if (global->talk_text->speed_text_rect_line3.width < 0)
                global->talk_text->speed_text_rect_line3.width = 0;
            global->talk_text->speed_text_rect_line3.width -= 10;
            sfClock_restart(global->talk_text->clock);
        }
    }
}

void destroy_dialogue_text()
{

}