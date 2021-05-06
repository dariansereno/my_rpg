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

    setkeyupright(ad);
    if (secondso > 0.01) {
        ad->paralax->starr.top -= ad->var_game->speed - 1;
        ad->paralax->starr.left += ad->var_game->speed - 1;
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

    setkeydownleft(ad);
    if (secondso > 0.01) {
        ad->paralax->starr.top += ad->var_game->speed - 1;
        ad->paralax->starr.left -= ad->var_game->speed - 1;
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

    setkeyupleft(ad);
    if (secondso > 0.01) {
        ad->paralax->starr.top -= ad->var_game->speed - 1;
        ad->paralax->starr.left -= ad->var_game->speed - 1;
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

    setkeydownright(ad);
    if (secondso > 0.01) {
        ad->paralax->starr.top += ad->var_game->speed - 1;
        ad->paralax->starr.left += ad->var_game->speed - 1;
        if (ad->paralax->starr.top >= 2160)
            ad->paralax->starr.top = 0;
        if (ad->paralax->starr.left >= 3840)
            ad->paralax->starr.left = 0;
        sfClock_restart(ad->paralax->staro);
    }
}