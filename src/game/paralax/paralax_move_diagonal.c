/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** move background
*/

#include "my_rpg.h"

void move_upright(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->paralo);
    float secondso = timeo.microseconds / 1000000.0;

    ad->ship->velocity.y = -ad->var_game->speed;
    ad->ship->velocity.x = ad->var_game->speed;
    ad->ship->bshipt = ad->texture->th[2];
    if (secondso > 0.01) {
        ad->paralax->paralaxr.top -= (int)ad->var_game->speed / 2;
        ad->paralax->paralaxr.left += (int)ad->var_game->speed / 2;
        if (ad->paralax->paralaxr.top <= 0)
            ad->paralax->paralaxr.top = 2160;
        if (ad->paralax->paralaxr.left >= 3840)
            ad->paralax->paralaxr.left = 0;
        sfClock_restart(ad->paralax->paralo);
    }
    move_star_upright(ad);
}

void move_downleft(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->paralo);
    float secondso = timeo.microseconds / 1000000.0;

    ad->ship->bshipt = ad->texture->th[4];
    ad->ship->velocity.y = ad->var_game->speed;
    ad->ship->velocity.x = -ad->var_game->speed;
    if (secondso > 0.01) {
        ad->paralax->paralaxr.top += (int)ad->var_game->speed / 2;
        ad->paralax->paralaxr.left -= (int)ad->var_game->speed / 2;
        if (ad->paralax->paralaxr.top >= 2160)
            ad->paralax->paralaxr.top = 0;
        if (ad->paralax->paralaxr.left >= 3840)
            ad->paralax->paralaxr.left = 0;
        sfClock_restart(ad->paralax->paralo);
    }
    move_star_downleft(ad);
}

void move_upleft(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->paralo);
    float secondso = timeo.microseconds / 1000000.0;

    ad->ship->velocity.y = -ad->var_game->speed;
    ad->ship->velocity.x = -ad->var_game->speed;
    ad->ship->bshipt = ad->texture->th[1];
    if (secondso > 0.01) {
        ad->paralax->paralaxr.left -= (int)ad->var_game->speed / 2;
        ad->paralax->paralaxr.top -= (int)ad->var_game->speed / 2;
        if (ad->paralax->paralaxr.left <= 0)
            ad->paralax->paralaxr.left = 3840;
        if (ad->paralax->paralaxr.top <= 0)
            ad->paralax->paralaxr.top = 2160;
        sfClock_restart(ad->paralax->paralo);
    }
    move_star_upleft(ad);
}

void move_downright(st_global *ad)
{
    sfTime timeo = sfClock_getElapsedTime(ad->paralax->paralo);
    float secondso = timeo.microseconds / 1000000.0;

    ad->ship->velocity.y = ad->var_game->speed;
    ad->ship->velocity.x = ad->var_game->speed;
    ad->ship->bshipt = ad->texture->th[3];
    if (secondso > 0.01) {
        ad->paralax->paralaxr.left += (int)ad->var_game->speed / 2;
        ad->paralax->paralaxr.top += (int)ad->var_game->speed / 2;
        if (ad->paralax->paralaxr.left >= 3840)
            ad->paralax->paralaxr.left = 0;
        if (ad->paralax->paralaxr.top >= 2160)
            ad->paralax->paralaxr.top = 0;
        sfClock_restart(ad->paralax->paralo);
    }
    move_star_downright(ad);
}