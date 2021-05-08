/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** circle_intersections
*/

#include "my_rpg.h"

float heuristic(sfVector2f start, sfVector2f end)
{
    float result = fabsf(end.x - start.x) + fabsf(end.y - start.y);
    return (result);
}

float note_case(sfVector2f start, sfVector2f end, st_global *ad)
{
    if (is_on_planet(ad, start) || is_on_boss(ad, start))
        return (2147483647);
    else
        return (heuristic(start, end));
}

void calculate_2(sfVector2f start, st_ennemies *e, st_global *ad, int r)
{
    int x = 5;

    switch (x) {
    case 5:
        (*e).path_table[x++] = note_case((sfVector2f){start.x - r, start.y + r},
        ad->ship->bshippos, ad);
    case 6:
        (*e).path_table[x++] = note_case((sfVector2f){start.x - r, start.y},
        ad->ship->bshippos, ad);
    case 7:
        (*e).path_table[x++] = note_case((sfVector2f){start.x - r, start.y - r},
        ad->ship->bshippos, ad);
    }
}

void calculate_table_notation(sfVector2f start, st_ennemies *e, st_global *ad,
int r)
{
    int x = 0;

    switch (x) {
    case 0:
        (*e).path_table[x++] = note_case((sfVector2f){start.x, start.y - r},
        ad->ship->bshippos, ad);
    case 1:
        (*e).path_table[x++] = note_case((sfVector2f){start.x + r , start.y -
        r}, ad->ship->bshippos, ad);
    case 2:
        (*e).path_table[x++] = note_case((sfVector2f){start.x + r, start.y},
        ad->ship->bshippos, ad);
    case 3:
        (*e).path_table[x++] = note_case((sfVector2f){start.x + r, start.y + r},
        ad->ship->bshippos, ad);
    case 4:
        (*e).path_table[x++] = note_case((sfVector2f){start.x, start.y + r},
        ad->ship->bshippos, ad);
    }
    calculate_2(start, e, ad, r);
}
