/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** move background
*/

#include "my_rpg.h"

void move_up(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->paralo);
    float secondso = timeo.microseconds / 1000000.0;

    ad->ship->velocity.y = -5;
    ad->ship->bshipt = sfTexture_createFromFile("contents/sbr/b0.png", NULL);
    if (secondso > 0.01) {
        ad->paralax->paralaxr.top -= 2.5;
        if (ad->paralax->paralaxr.top <= 0)
            ad->paralax->paralaxr.top = 2160;
        sfClock_restart(ad->paralax->paralo);
    }
    move_star_up(ad);
}

void move_down(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->paralo);
    float secondso = timeo.microseconds / 1000000.0;

    ad->ship->velocity.y += 5;
    ad->ship->bshipt = sfTexture_createFromFile("contents/sbr/b180.png", NULL);
    if (secondso > 0.01) {
        ad->paralax->paralaxr.top += 2.5;
        if (ad->paralax->paralaxr.top >= 2160)
            ad->paralax->paralaxr.top = 0;
        sfClock_restart(ad->paralax->paralo);
    }
    move_star_down(ad);
}

void move_left(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->paralo);
    float secondso = timeo.microseconds / 1000000.0;

    ad->ship->velocity.x = -5;
    ad->ship->acceleration.x -= 0.0001;
    ad->ship->bshipt = sfTexture_createFromFile("contents/sbr/b270.png", NULL);
    if (secondso > 0.01) {
        ad->paralax->paralaxr.left -= 2.5;
        if (ad->paralax->paralaxr.left <= 0)
            ad->paralax->paralaxr.left = 3840;
        sfClock_restart(ad->paralax->paralo);
    }
    move_star_left(ad);
}

void move_right(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->paralo);
    float secondso = timeo.microseconds / 1000000.0;

    ad->ship->velocity.x = 5;
    ad->ship->bshipt = sfTexture_createFromFile("contents/sbr/b90.png", NULL);
    if (secondso > 0.01) {
        ad->paralax->paralaxr.left += 2.5;
        if (ad->paralax->paralaxr.left >= 3840)
            ad->paralax->paralaxr.left = 0;
        sfClock_restart(ad->paralax->paralo);
    }
    move_star_right(ad);
}