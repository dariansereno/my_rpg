/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** boss
*/

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

// void rect_set_boss(st_global *g)
// {
//     sfRectangleShape_setPosition(g->ui->boss->life, (sfVector2f){500, 10});
//     sfRectangleShape_setPosition(g->ui->boss->outline, \
//     (sfVector2f){500, 10});
//     sfRectangleShape_setSize(g->ui->boss, (sfVector2f)\
//     {g->ui->boss->life_f * 400 / 500, 10});
// }

// void boss_life(st_global *g)
// {
//     if (g->var_game->is_boss) {
//         rect_set_boss(g);
//         sfRectangleShape_setPosition(g->ui->boss->life, (sfVector2f)\
//         {sfRectangleShape_getPosition(g->ui->boss->life).x + \
//         g->ship->viewrect.left,\
//         sfRectangleShape_getPosition(g->ui->boss->life).y + \
//         g->ship->viewrect.top});
//         sfRectangleShape_setPosition(g->ui->boss->outline, (sfVector2f)\
//         {sfRectangleShape_getPosition(g->ui->boss->outline).x + \
//         g->ship->viewrect.left,\
//         sfRectangleShape_getPosition(g->ui->boss->outline).y + \
//         g->ship->viewrect.top});
//         sfRenderWindow_drawRectangleShape(g->window->window, \
//         g->ui->boss->outline, NULL);
//         sfRenderWindow_drawRectangleShape(g->window->window, \
//         g->ui->boss->life, NULL);
//     }
// }

// void destroy_boss(st_boss *boss)
// {
//     sfRectangleShape_destroy(boss->life);
//     sfRectangleShape_destroy(boss->outline);
// }