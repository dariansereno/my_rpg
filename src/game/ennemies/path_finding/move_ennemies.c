/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** move_ennemies
*/

#include "my_rpg.h"

int direction_ennemie(st_ennemies ennemies, sfVector2f target, st_global *ad)
{
    float max = 2147483647 - 1;
    int index = 0;

    calculate_table_notation(ennemies.pos, &ennemies, ad,
    50);
    for (int i = 0; i < 8; i++) {
        if (ennemies.path_table[i] < max) {
            max = ennemies.path_table[i],
            index = i;
        }
    }
    return (index);
}

int direction_ennemie_base(st_ennemies ennemies, sfVector2f target,
st_global *ad)
{
    float max = 2147483647 - 1;
    int index = 0;

    calculate_table_notation_base(&ennemies, ad, 50,
    target);
    for (int i = 0; i < 8; i++) {
        if (ennemies.path_table[i] < max) {
            max = ennemies.path_table[i],
            index = i;
        }
    }
    return (index);
}

st_ennemies switch_enn_move(st_ennemies e, int dir, st_global *ad)
{
    switch (dir) {
    case 0:
        return (move_enn_up(e, ad));
    case 1:
        return (move_enn_upright(e, ad));
    case 2:
        return (move_enn_right(e, ad));
    case 3:
        return (move_enn_downright(e, ad));
    case 4:
        return (move_enn_down(e, ad));
    case 5:
        return (move_enn_downleft(e, ad));
    case 6:
        return (move_enn_left(e, ad));
    case 7:
        return (move_enn_upleft(e, ad));
    }
    return (move_enn_stand(e, ad));
}

void clock_move_ennemies(list_ennemies e, st_global *ad)
{
    e->timer->time = sfClock_getElapsedTime((*e).timer->clock);
    e->timer->seconds = e->timer->time.microseconds / 1000000.0;
    e->ennemies.dir = direction_ennemie(e->ennemies, ad->ship->bshippos, ad);

    if (e->timer->seconds > 0.01) {
        e->ennemies = switch_enn_move(e->ennemies, e->ennemies.dir, ad);
        sfClock_restart(e->timer->clock);
    }
}

void clock_move_ennemies_to_base(list_ennemies e, st_global *ad)
{
    e->timer->time = sfClock_getElapsedTime((*e).timer->clock);
    e->timer->seconds = e->timer->time.microseconds / 1000000.0;
    e->ennemies.dir = direction_ennemie_base(e->ennemies, e->ennemies.spawn_pos,
    ad);

    if (e->timer->seconds > 0.01) {
        if (e->ennemies.pos.x != e->ennemies.spawn_pos.x &&
        e->ennemies.pos.y != e->ennemies.spawn_pos.y){
            e->ennemies = switch_enn_move(e->ennemies, e->ennemies.dir, ad);}
        sfClock_restart(e->timer->clock);
    }
}