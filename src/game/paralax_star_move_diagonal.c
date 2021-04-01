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

    ad->paralax->starpos.x += 1;
    ad->paralax->starpos.y -= 1;
    if (secondso > 0.01) {
        ad->paralax->starr.top -= 7;
        ad->paralax->starr.left += 7;
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

    ad->paralax->starpos.x -= 1;
    ad->paralax->starpos.y += 1;
    if (secondso > 0.01) {
        ad->paralax->starr.top += 7;
        ad->paralax->starr.left -= 7;
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

    ad->paralax->starpos.x -= 1;
    ad->paralax->starpos.y -= 1;
    if (secondso > 0.01) {
        ad->paralax->starr.top -= 7;
        ad->paralax->starr.left -= 7;
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

    ad->paralax->starpos.x += 1;
    ad->paralax->starpos.y += 1;
    if (secondso > 0.01) {
        ad->paralax->starr.top += 7;
        ad->paralax->starr.left += 7;
        if (ad->paralax->starr.top >= 2160)
            ad->paralax->starr.top = 0;
        if (ad->paralax->starr.left >= 3840)
            ad->paralax->starr.left = 0;
        sfClock_restart(ad->paralax->staro);
    }
}