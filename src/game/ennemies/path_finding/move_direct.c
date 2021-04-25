/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** move_direct
*/

#include "my_rpg.h"

st_ennemies move_enn_up(st_ennemies e)
{
    e.pos.y -= 5;
    return (e);
}

st_ennemies move_enn_down(st_ennemies e)
{
    e.pos.y += 5;
    return (e);
}

st_ennemies move_enn_left(st_ennemies e)
{
    e.pos.x -= 5;
    return (e);
}

st_ennemies move_enn_right(st_ennemies e)
{
    e.pos.x += 5;
    return (e);
}