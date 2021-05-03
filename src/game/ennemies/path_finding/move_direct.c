/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** move_direct
*/

#include "my_rpg.h"

st_ennemies move_enn_up(st_ennemies e, st_global *ad)
{
    e.pos.y -= 3;
    sfSprite_setTexture(e.sprite, ad->enn_texture[0], sfTrue);
    return (e);
}

st_ennemies move_enn_down(st_ennemies e, st_global *ad)
{
    e.pos.y += 3;
    sfSprite_setTexture(e.sprite, ad->enn_texture[4], sfTrue);
    return (e);
}

st_ennemies move_enn_left(st_ennemies e, st_global *ad)
{
    e.pos.x -= 3;
    sfSprite_setTexture(e.sprite, ad->enn_texture[6], sfTrue);
    return (e);
}

st_ennemies move_enn_right(st_ennemies e, st_global *ad)
{
    e.pos.x += 3;
    sfSprite_setTexture(e.sprite, ad->enn_texture[2], sfTrue);
    return (e);
}