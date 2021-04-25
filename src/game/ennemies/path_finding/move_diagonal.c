/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** move_diagonal
*/

#include "my_rpg.h"

st_ennemies move_enn_upright(st_ennemies e)
{
    e.pos.y -= 5;
    e.pos.x += 5;
    return (e);
}

st_ennemies move_enn_downright(st_ennemies e)
{
    e.pos.y += 5;
    e.pos.x += 5;
    return (e);
}

st_ennemies move_enn_downleft(st_ennemies e)
{
    e.pos.x -= 5;
    e.pos.y += 5;
    return (e);
}

st_ennemies move_enn_upleft(st_ennemies e)
{
    e.pos.x -= 5;
    e.pos.y -= 5;
    return (e);
}