/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** move stars
*/

#include "my_rpg.h"

void move_star_upright(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->staro);
    float secondso = timeo.microseconds / 1000000.0;

    ad->paralax->starpos.x += 5;
    ad->paralax->starpos.y -= 5;
    if (secondso > 0.01) {
        ad->paralax->starr.top -= 4;
        ad->paralax->starr.left += 4;
        if (ad->paralax->starr.top <= 0)
            ad->paralax->starr.top = 2160;
        if (ad->paralax->starr.left >= 3840)
            ad->paralax->starr.left = 0;
        sfClock_restart(ad->paralax->staro);
    }
}

void move_star_downleft(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->staro);
    float secondso = timeo.microseconds / 1000000.0;

    ad->paralax->starpos.x -= 5;
    ad->paralax->starpos.y += 5;
    if (secondso > 0.01) {
        ad->paralax->starr.top += 4;
        ad->paralax->starr.left -= 4;
        if (ad->paralax->starr.top >= 2160)
            ad->paralax->starr.top = 0;
        if (ad->paralax->starr.left <= 0)
            ad->paralax->starr.left = 3840;
        sfClock_restart(ad->paralax->staro);
    }
}

void move_star_upleft(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->staro);
    float secondso = timeo.microseconds / 1000000.0;

    ad->paralax->starpos.x -= 5;
    ad->paralax->starpos.y -= 5;
    if (secondso > 0.01) {
        ad->paralax->starr.top -= 4;
        ad->paralax->starr.left -= 4;
        if (ad->paralax->starr.top <= 0)
            ad->paralax->starr.top = 2160;
        if (ad->paralax->starr.left <= 0)
            ad->paralax->starr.left = 3840;
        sfClock_restart(ad->paralax->staro);
    }
}

void move_star_downright(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->staro);
    float secondso = timeo.microseconds / 1000000.0;

    ad->paralax->starpos.x += 5;
    ad->paralax->starpos.y += 5;
    if (secondso > 0.01) {
        ad->paralax->starr.top += 4;
        ad->paralax->starr.left += 4;
        if (ad->paralax->starr.top >= 2160)
            ad->paralax->starr.top = 0;
        if (ad->paralax->starr.left >= 3840)
            ad->paralax->starr.left = 0;
        sfClock_restart(ad->paralax->staro);
    }
}