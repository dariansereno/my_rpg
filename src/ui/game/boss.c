// /*
// ** EPITECH PROJECT, 2021
// ** my_rpg
// ** File description:
// ** boss
// */

#include "my_rpg.h"

// st_boss *generate_boss(void)
// {
//     st_boss *boss = my_malloc(sizeof(*boss));

//     boss->life = sfRectangleShape_create();
//     boss->outline = sfRectangleShape_create();
//     boss->life_f = 500;
//     sfRectangleShape_setSize(boss->life, (sfVector2f){400, 10});
//     sfRectangleShape_setSize(boss->outline, (sfVector2f){400, 10});
//     sfRectangleShape_setPosition(boss->life, (sfVector2f){500, 10});
//     sfRectangleShape_setPosition(boss->outline, (sfVector2f){500, 10});
//     sfRectangleShape_setFillColor(boss->life, sfRed);
//     sfRectangleShape_setOutlineColor(boss->outline, \
//     sfColor_fromRGB(179, 130, 188));
//     sfRectangleShape_setOutlineThickness(boss->outline, 6);
//     return (boss);
// }

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