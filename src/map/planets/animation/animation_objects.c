/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** animation_objects
*/

#include "my_rpg.h"

void spatial_object_move(st_global *ad)
{
    list_planet li = ad->planets->planets;

    while (li != NULL) {
        if (li->planet.type >= 24 && li->planet.type <= 28) {
            li->move.time = sfClock_getElapsedTime(li->move.clock);
            li->move.seconds = li->move.time.microseconds / 1000000.0;
            if (li->move.seconds > 0.5) {
                if (li->direction == 0)
                    li->planet.pos.y -= 3;
                if (li->direction == 1) {
                    li->planet.pos.y -= 3;
                    li->planet.pos.x += 3;
                }
                if (li->direction == 2)
                    li->planet.pos.x += 3;
                if (li->direction == 3) {
                    li->planet.pos.y += 3;
                    li->planet.pos.x += 3;
                }
                if (li->direction == 4)
                    li->planet.pos.y += 3;
                if (li->direction == 5) {
                    li->planet.pos.y += 3;
                    li->planet.pos.x -= 3;
                }
                if (li->direction == 6)
                    li->planet.pos.x -= 3;
                if (li->direction == 7) {
                    li->planet.pos.x -= 3;
                    li->planet.pos.y += 3;
                }
                sfClock_restart(li->move.clock);
            }
        }
        li = li->next;
    }
}