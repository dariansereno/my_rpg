/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** move stars
*/

#include "my_rpg.h"

void move_star_up(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->staro);
    float secondso = timeo.microseconds / 1000000.0;

    if (secondso > 0.01) {
        ad->paralax->starr.top -= 4;
        if (ad->paralax->starr.top <= 0)
            ad->paralax->starr.top = 2160;
        sfClock_restart(ad->paralax->staro);
    }
}

void move_star_down(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->staro);
    float secondso = timeo.microseconds / 1000000.0;

    if (secondso > 0.01) {
        ad->paralax->starr.top += 4;
        if (ad->paralax->starr.top >= 2160)
            ad->paralax->starr.top = 0;
        sfClock_restart(ad->paralax->staro);
    }
}

void move_star_left(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->staro);
    float secondso = timeo.microseconds / 1000000.0;

    if (secondso > 0.01) {
        ad->paralax->starr.left -= 4;
        if (ad->paralax->starr.left <= 0)
            ad->paralax->starr.left = 3840;
        sfClock_restart(ad->paralax->staro);
    }
}

void move_star_right(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->staro);
    float secondso = timeo.microseconds / 1000000.0;

    if (secondso > 0.01) {
        ad->paralax->starr.left += 4;
        if (ad->paralax->starr.left >= 3840)
            ad->paralax->starr.left = 0;
        sfClock_restart(ad->paralax->staro);
    }
}