/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** move_ennemies
*/

#include "my_rpg.h"

int direction_ennemie(st_ennemies ennemies, sfVector2f target, st_global *ad)
{
    float max = INT32_MAX - 1;
    int index = 0;

    ennemies.path_table = calculate_table_notation(ennemies.pos, ennemies, ad,
    50);
    for (int i = 0; i < 7; i++) {
        if (ennemies.path_table[i] < max) {
            max = ennemies.path_table[i],
            index = i;
        }
    }
    return (index);
}

st_ennemies switch_enn_move(st_ennemies e, int dir)
{
    switch (dir) {
    case 0:
        return (move_enn_down(e));
    case 1:
        return (move_enn_downright(e));
    case 2:
        return (move_enn_right(e));
    case 3:
        return (move_enn_upright(e));
    case 4:
        return (move_enn_up(e));
    case 5:
        return (move_enn_upleft(e));
    case 6:
        return (move_enn_left(e));
    case 7:
        return (move_enn_downleft(e));
    }
    return (move_enn_down(e));
}

void print_dir(int dir)
{
    if (dir == 0)
        printf("down\n");
    if (dir == 1)
        printf("down right\n");
    if (dir == 2)
        printf("right\n");
    if (dir == 3)
        printf("up right\n");
    if (dir == 4)
        printf("up\n");
    if (dir == 5)
        printf("up left\n");
    if (dir == 6)
        printf("left\n");
    if (dir == 7)
        printf("down left\n");
}

void clock_move_ennemies(list_ennemies e, st_global *ad)
{
    e->timer->time = sfClock_getElapsedTime((*e).timer->clock);
    e->timer->seconds = e->timer->time.microseconds / 1000000.0;

    if (e->timer->seconds > 0.2) {
        e->ennemies = switch_enn_move(e->ennemies, direction_ennemie(
        e->ennemies, ad->ship->bshippos, ad));
        print_dir(direction_ennemie(e->ennemies, ad->ship->bshippos, ad));
        sfClock_restart(e->timer->clock);
    }
}