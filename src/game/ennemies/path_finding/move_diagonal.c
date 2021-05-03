/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** move_diagonal
*/

#include "my_rpg.h"

st_ennemies move_enn_upright(st_ennemies e, st_global *ad)
{
    e.pos.y -= 2;
    e.pos.x += 2;
    sfSprite_setTexture(e.sprite, ad->enn_texture[1], sfTrue);
    return (e);
}

st_ennemies move_enn_downright(st_ennemies e, st_global *ad)
{
    e.pos.y += 2;
    e.pos.x += 2;
    sfSprite_setTexture(e.sprite, ad->enn_texture[3], sfTrue);
    return (e);
}

st_ennemies move_enn_downleft(st_ennemies e, st_global *ad)
{
    e.pos.x -= 2;
    e.pos.y += 2;
    sfSprite_setTexture(e.sprite, ad->enn_texture[5], sfTrue);
    return (e);
}

st_ennemies move_enn_upleft(st_ennemies e, st_global *ad)
{
    e.pos.x -= 2;
    e.pos.y -= 2;
    sfSprite_setTexture(e.sprite, ad->enn_texture[7], sfTrue);
    return (e);
}

st_ennemies move_enn_stand(st_ennemies e, st_global *ad)
{
    return (e);
}