/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** circle_intersections
*/

#include "my_rpg.h"

double rad(double degree)
{
    return (degree * (M_PI / 180));
}

float heuristic(sfVector2f start, sfVector2f end)
{
    float result = fabsf(end.x - start.x) - fabsf(end.y - start.y);
    return (result);
}

float note_case(sfVector2f start, sfVector2f end, st_global *ad)
{
    if (is_on_planet(ad, (sfVector2f){start.x, start.y}))
        return (INT32_MAX);
    else
        return (heuristic((sfVector2f){start.x, start.y}, end));
}

float *calculate_2(sfVector2f start, st_ennemies e, st_global *ad, int r)
{
    int x = 5;

    switch (x) {
    case 5:
        e.path_table[x++] = note_case((sfVector2f){start.x + (r * cos(rad(135)
        )), start.y + (r * sin(rad(135)))}, ad->ship->bshippos, ad);
    case 6:
        e.path_table[x++] = note_case((sfVector2f){start.x - r, start.y},
        ad->ship->bshippos, ad);
    case 7:
        e.path_table[x++] = note_case((sfVector2f){start.x + (r * cos(rad(225)
        )), start.y + (r * sin(rad(225)))}, ad->ship->bshippos, ad);
    }
    return (e.path_table);
}

float *calculate_table_notation(sfVector2f start, st_ennemies e, st_global *ad,
int r)
{
    int x = 0;

    switch (x) {
    case 0:
        e.path_table[x++] = note_case((sfVector2f){start.x, start.y + r},
        ad->ship->bshippos, ad);
    case 1:
        e.path_table[x++] = note_case((sfVector2f){start.x + (r * cos(rad(315)
        )), start.y + (r * sin(rad(315)))}, ad->ship->bshippos, ad);
    case 2:
        e.path_table[x++] = note_case((sfVector2f){start.x + r, start.y},
        ad->ship->bshippos, ad);
    case 3:
        e.path_table[x++] = note_case((sfVector2f){start.x + (r * cos(rad(45)))
        , start.y + (r * sin(rad(45)))}, ad->ship->bshippos, ad);
    case 4:
        e.path_table[x++] = note_case((sfVector2f){start.x, start.y - r},
        ad->ship->bshippos, ad);
    }
    return (calculate_2(start, e, ad, r));
}
