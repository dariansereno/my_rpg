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
    paralax->clock = sfClock_create();
    paralax->nebulapos = (sfVector2f) {0,0};
    paralax->starpos = (sfVector2f) {0,0};
    paralax->i = 0;
    paralax->j = 0;
    paralax->k = 0;
    paralax->l = 0;
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
    window->music = sfMusic_createFromFile("ressources/song.wav");
    return (window);
}

ship_t *ship_ini(void)
{
    ship_t *ship = malloc(sizeof(ship_t));

    ship->bship = sfSprite_create();
    ship->bshipt = sfTexture_createFromFile("contents/ships/ships/blue01.png",
    NULL);
    ship->bshippos = (sfVector2f) {.x = 937.5, .y = 517.5};
    ship->viewrect = (sfFloatRect) {.height = 1080, .left = 0, .top = 0,
    .width = 1920};
    ship->view = sfView_createFromRect(ship->viewrect);
    return (ship);
}

st_global *ini(void)
{
    st_global *all = malloc(sizeof(st_global));

    all->window = all_dat();
    all->paralax = paralax_ini();
    all->ship = ship_ini();
    return (all);
}