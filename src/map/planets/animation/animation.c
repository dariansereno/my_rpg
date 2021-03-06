/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** animation
*/

#include "my_rpg.h"

void animate_planets_short(st_global *ad, list_planet *li)
{
    (*li)->timer.time = sfClock_getElapsedTime((*li)->timer.clock);
    (*li)->timer.seconds = (*li)->timer.time.microseconds / 1000000.0;
    if ((*li)->timer.seconds > 0.08) {
        (*li)->planet.rect.left += 48;
        if ((*li)->planet.rect.left >= 2880)
            (*li)->planet.rect.left = 0;
        sfClock_restart((*li)->timer.clock);
    }
}

void animate_planet_long(st_global *ad, list_planet *li)
{
    (*li)->timer.time = sfClock_getElapsedTime((*li)->timer.clock);
    (*li)->timer.seconds = (*li)->timer.time.microseconds / 1000000.0;
    if ((*li)->timer.seconds > 0.08) {
        (*li)->planet.rect.left += 48;
        if ((*li)->planet.rect.left >= 5760)
            (*li)->planet.rect.left = 0;
        sfClock_restart((*li)->timer.clock);
    }
}

void animate_planets_content(st_global *ad, list_planet *li)
{
    if ((*li)->planet.type != 15 && (*li)->planet.type != 19 &&
    (*li)->planet.type != 18)
        animate_planets_short(ad, li);
    else if (((*li)->planet.type == 15 ||
    (*li)->planet.type == 19 || (*li)->planet.type == 18))
        animate_planet_long(ad, li);
}

void animate_planets(st_global *ad)
{
    list_planet li = ad->planets->planets;

    while (li != NULL) {
        if (li->planet.animated == ANIMATED && li->on_screen == true)
            animate_planets_content(ad, &li);
        li = li->next;
    }
}