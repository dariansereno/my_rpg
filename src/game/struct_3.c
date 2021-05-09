/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** struct_3
*/

#include "my_rpg.h"

paralax_t *paralax_ini(void)
{
    paralax_t *paralax = malloc(sizeof(paralax_t));

    paralax->nebula = sfSprite_create();
    paralax->nebulat = sfTexture_createFromFile("ressources/space.png", NULL);
    paralax->paralaxr = (sfIntRect) {.height = HEIGHT, .left = WIDTH,
    .top = HEIGHT, .width = WIDTH};
    paralax->paralo = sfClock_create();
    paralax->star = sfSprite_create();
    paralax->start = sfTexture_createFromFile("ressources/stars.png", NULL);
    paralax->starr = (sfIntRect) {.height = HEIGHT, .left = WIDTH,
    .top = HEIGHT, .width = WIDTH};
    paralax->staro = sfClock_create();
    paralax->clock = sfClock_create();
    paralax->nebulapos = (sfVector2f) {0, 0};
    paralax->starpos = (sfVector2f) {0, 0};
    paralax->i = 0;
    paralax->j = 0;
    paralax->k = 0;
    paralax->l = 0;
    return (paralax);
}

void generate_paths(ship_t *ship)
{
    ship->path = my_malloc(sizeof(char *) * 5);
    ship->path_t = my_malloc(sizeof(char *) * 5);

    ship->path[0] = "contents/ships_game/blue.png";
    ship->path[1] = "contents/ships_game/orange.png";
    ship->path[2] = "contents/ships_game/dark.png";
    ship->path[3] = "contents/ships_game/metalic.png";
    ship->path[4] = "contents/ships_game/green.png";
    ship->path_t[0] = "contents/ships_game/blue_t.png";
    ship->path_t[1] = "contents/ships_game/orange_t.png";
    ship->path_t[2] = "contents/ships_game/dark_t.png";
    ship->path_t[3] = "contents/ships_game/metalic_t.png";
    ship->path_t[4] = "contents/ships_game/green_t.png";
    ship->ship_choosen = 0;
}