/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** game
*/

#include "my_rpg.h"

st_global *generate_global(void)
{
    st_global *global = malloc(sizeof(*global));
    global->talk_text = malloc(sizeof(*global->talk_text));
    global->talk_text->black_outline = sfRectangleShape_create();
    global->talk_text->purple_outline = sfRectangleShape_create();
    global->talk_text->white_rectangle = sfRectangleShape_create();
    global->talk_text->talk_text = sfText_create();
    global->talk_text->talk_font = sfFont_createFromFile("contents/fonts/dogica/TTF/dogicapixel.ttf");
    global->talk_text->existing = sfFalse;
    global->talk_text->clock = sfClock_create();
    global->talk_text->speed_text_rect_line1 = (sfIntRect){0, 0, 0, 0};
    global->talk_text->speed_text_rect_line2 = (sfIntRect){0, 0, 0, 0};
    global->talk_text->speed_text_rect_line3 = (sfIntRect){0, 0, 0, 0};
    global->talk_text->speed_text_sprite_line1 = sfSprite_create();
    global->talk_text->speed_text_texture_line1 = sfTexture_createFromFile("./contents/white_rect.jpg", NULL);
    global->talk_text->speed_text_sprite_line2 = sfSprite_create();
    global->talk_text->speed_text_texture_line2 = sfTexture_createFromFile("./contents/white_rect.jpg", NULL);
    global->talk_text->speed_text_sprite_line3 = sfSprite_create();
    global->talk_text->speed_text_texture_line3 = sfTexture_createFromFile("./contents/white_rect.jpg", NULL);
    return (global);
}

int game_loop()
{
    sfEvent event;
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};

    window = sfRenderWindow_create(mode, "my_defender", sfResize | sfClose, \
    NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    st_global *global = generate_global();

    if (window != NULL) {
        while (sfRenderWindow_isOpen(window)) {
            sfRenderWindow_clear(window, sfWhite);
            while (sfRenderWindow_pollEvent(window, &event)) {
                if (event.type == sfEvtClosed)
                    sfRenderWindow_close(window);
                else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
                    sfRenderWindow_close(window);
                if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD)
                    dialogue_text(global, "Bonjour à toi jeune entrepreneur, pour ta première quête... Tu vas devoir\ntrouver le joyau qui est disposé être au fond de la chaîne des \nAndesen Amérique Latine", 100);
            }
            clock_dialogue_text_line1(global);
            clock_dialogue_text_line2(global);
            clock_dialogue_text_line3(global);
            display_dialogue_text(window, global);
            sfRenderWindow_display(window);
        }
        sfRenderWindow_destroy(window);
    }
    return (0);
}