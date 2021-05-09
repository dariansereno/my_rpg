// /*
// ** EPITECH PROJECT, 2021
// ** my_rpg
// ** File description:
// ** boss
// */

#include "my_rpg.h"

void rect_set_boss(st_global *g)
{
    sfRectangleShape_setPosition(g->boss->life, (sfVector2f){500, 10});
    sfRectangleShape_setPosition(g->boss->outline, \
    (sfVector2f){500, 10});
    sfRectangleShape_setSize(g->boss->life, (sfVector2f)\
    {g->boss->life_f * 400 / 5000, 10});
}

void boss_life(st_global *g)
{
    if (g->var_game->is_boss) {
        rect_set_boss(g);
        sfRectangleShape_setPosition(g->boss->outline, (sfVector2f)
        {g->boss->boss->pos.x - (sfRectangleShape_getLocalBounds
        (g->boss->outline).width / 2), g->boss->boss->pos.y - 300});
        sfRectangleShape_setPosition(g->boss->life, (sfVector2f)
        {g->boss->boss->pos.x - (sfRectangleShape_getLocalBounds
        (g->boss->outline).width / 2), g->boss->boss->pos.y - 300});
        sfRenderWindow_drawRectangleShape(g->window->window, \
        g->boss->outline, NULL);
        sfRenderWindow_drawRectangleShape(g->window->window, \
        g->boss->life, NULL);
    }
}

void destroy_boss(st_boss *boss)
{
    sfRectangleShape_destroy(boss->life);
    sfRectangleShape_destroy(boss->outline);
}