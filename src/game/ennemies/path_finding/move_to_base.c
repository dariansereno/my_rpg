/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** move_to_base
*/

#include "my_rpg.h"

void calculate_2_base(sfVector2f target, st_ennemies *e, st_global *ad, int r)
{
    int x = 5;

    switch (x) {
    case 5:
        (*e).path_table[x++] = note_case((sfVector2f){(*e).pos.x - r,
        (*e).pos.y + r}, target, ad);
    case 6:
        (*e).path_table[x++] = note_case((sfVector2f){(*e).pos.x - r,
        (*e).pos.y}, target, ad);
    case 7:
        (*e).path_table[x++] = note_case((sfVector2f){(*e).pos.x - r,
        (*e).pos.y - r}, target, ad);
    }
}

void calculate_table_notation_base(st_ennemies *e, st_global *ad,
int r, sfVector2f target)
{
    int x = 0;

    switch (x) {
    case 0:
        (*e).path_table[x++] = note_case((sfVector2f){(*e).pos.x,
        (*e).pos.y - r}, target, ad);
    case 1:
        (*e).path_table[x++] = note_case((sfVector2f){(*e).pos.x + r ,
        (*e).pos.y - r}, target, ad);
    case 2:
        (*e).path_table[x++] = note_case((sfVector2f){(*e).pos.x + r,
        (*e).pos.y}, target, ad);
    case 3:
        (*e).path_table[x++] = note_case((sfVector2f){(*e).pos.x + r,
        (*e).pos.y + r}, target, ad);
    case 4:
        (*e).path_table[x++] = note_case((sfVector2f){(*e).pos.x, (*e).pos.y
        + r}, target, ad);
    }
    calculate_2_base(target, e, ad, r);
}
