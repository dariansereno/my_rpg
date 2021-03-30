/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** structs
*/

#include "../../include/my_rpg.h"

paralax_t *paralax_ini(void)
{
    paralax_t *paralax = malloc(sizeof(paralax_t));

    paralax->nebula = sfSprite_create();
    paralax->nebulat = sfTexture_createFromFile("ressources/space.png", NULL);
    paralax->paralaxr = (sfIntRect) {.height = 1080, .left = 1920, .top = 1080,
    .width = 1920};
    paralax->paralo = sfClock_create();
    paralax->star = sfSprite_create();
    paralax->start = sfTexture_createFromFile("ressources/stars.png", NULL);
    paralax->starr = (sfIntRect) {.height = 1080, .left = 1920, .top = 1080,
    .width = 1920};
    paralax->staro = sfClock_create();
    return (paralax);
}

structs_t *all_dat(void)
{
    structs_t *window = malloc(sizeof(structs_t));

    window->mode.width = WIDTH;
    window->mode.height = HEIGHT;
    window->mode.bitsPerPixel = 32;
    window->window = sfRenderWindow_create(window->mode, "my_rpg",
    sfDefaultStyle, NULL);
    return (window);
}

st_global *ini(void)
{
    st_global *all = malloc(sizeof(st_global));

    all->window = all_dat();
    all->paralax = paralax_ini();
    return (all);
}