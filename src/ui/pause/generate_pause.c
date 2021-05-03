/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** generate_pause
*/

#include "my_rpg.h"

pause_s *generate_pause(void)
{
    pause_s *pause = my_malloc(sizeof(*pause));

    pause->text = sfText_create();
    pause->font = sfFont_createFromFile("contents/fonts/myfont.otf");
    pause->ui[0] = generate_object((sfVector2f){691, 166}, \
    (sfIntRect){0, 0, 538, 747}, "contents/ui/pause/bg.png");
    pause->ui[1] = generate_object((sfVector2f){808, 315}, \
    (sfIntRect){0, 0, 304, 72}, "contents/ui/pause/rect.png");
    pause->pos_rect = 1;
    pause->existing = false;
    pause->pressed = false;
    sfText_setFont(pause->text, pause->font);
    return (pause);
}

void destroy_pause(pause_s *pause)
{
    for (int i = 0; i < 2; i++)
        destroy_object(pause->ui[i]);
    sfText_destroy(pause->text);
    sfFont_destroy(pause->font);
}