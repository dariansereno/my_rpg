/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** structs
*/

#include "my_rpg.h"

keys_t *key_ini(void)
{
    keys_t *key = malloc(sizeof(keys_t));

    key->up = 0;
    key->upleft = 0;
    key->upright = 0;
    key->left = 0;
    key->right = 0;
    key->downright = 0;
    key->downleft = 0;
    key->down = 0;
    return (key);
}

load_t *texture_ini(void)
{
    load_t *texture = malloc(sizeof(load_t));

    texture->load = malloc(sizeof(sfTexture *) * 8);
    texture->load[0] = sfTexture_createFromFile("contents/sbr/b0.png", NULL);
    texture->load[1] = sfTexture_createFromFile("contents/sbr/b45.png", NULL);
    texture->load[2] = sfTexture_createFromFile("contents/sbr/b90.png", NULL);
    texture->load[3] = sfTexture_createFromFile("contents/sbr/b135.png", NULL);
    texture->load[4] = sfTexture_createFromFile("contents/sbr/b180.png", NULL);
    texture->load[5] = sfTexture_createFromFile("contents/sbr/b225.png", NULL);
    texture->load[6] = sfTexture_createFromFile("contents/sbr/b270.png", NULL);
    texture->load[7] = sfTexture_createFromFile("contents/sbr/b315.png", NULL);
    return (texture);
}