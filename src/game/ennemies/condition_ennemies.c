/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** condition_ennemies
*/

#include "my_rpg.h"

bool is_on_planet_content(st_global *ad, sfVector2f object, list_planet pl)
{
    if (pl->on_screen == true)
        if (circle_contains(155, (sfVector2f){(float)pl->planet.pos.x,
        (float)pl->planet.pos.y}, object) && pl->size == 2)
            return (true);
    return (false);
}

bool is_on_planet(st_global *ad, sfVector2f object)
{
    list_planet pl = NULL;
    if (ad->planets->planets == NULL)
        return (false);

    pl = ad->planets->planets;
    while (pl != NULL) {
        if (is_on_planet_content(ad, object, pl))
            return (true);
        pl = pl->next;
    }
    return (false);
}

bool is_on_boss(st_global *ad, sfVector2f object)
{
    if (circle_contains(260, ad->boss->boss->pos, object))
        return (true);
    return (false);
}

bool is_on_ennemies(st_global *ad, list_ennemies ennemies, sfVector2f object)
{
    list_ennemies li = ennemies;

    while (li != NULL) {
        if (circle_contains(70, (sfVector2f){(float)li->ennemies.pos.x,
        (float)li->ennemies.pos.y}, object))
            return (true);
        li = li->next;
    }
    return (false);
}