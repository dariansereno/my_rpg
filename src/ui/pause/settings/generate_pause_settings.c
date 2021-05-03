/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** generate_pause_settings
*/

#include "my_rpg.h"

pause_set_s *generate_pause_settings(void)
{
    pause_set_s *settings = my_malloc(sizeof(*settings));

    settings->font = sfFont_createFromFile("contents/fonts/myfont.otf");
    settings->text = sfText_create();
    settings->ui[0] = generate_object((sfVector2f){691, 166}, \
    (sfIntRect){0, 0, 538, 747}, "contents/UI/pause/settings/bg.png");
    settings->ui[1] = generate_object((sfVector2f){987, 749}, \
    (sfIntRect){0, 0, 149, 82}, "contents/UI/pause/settings/rect.png");
    settings->ui[2] = generate_object((sfVector2f){844, 368}, \
    (sfIntRect){0, 0, 253, 32}, "contents/UI/pause/settings/music.png");
    settings->ui[3] = generate_object((sfVector2f){844, 542}, \
    (sfIntRect){0, 0, 253, 32}, "contents/UI/pause/settings/sfx.png");
    settings->pos_rect = 2;
    settings->existing = false;
    settings->pressed = false;
    sfText_setFont(settings->text, settings->font);
    return (settings);
}

void destroy_pause_settings(pause_set_s *settings)
{
    for (int i = 0; i < 4; i++)
        destroy_object(settings->ui[i]);
    sfText_destroy(settings->text);
    sfFont_destroy(settings->font);
}