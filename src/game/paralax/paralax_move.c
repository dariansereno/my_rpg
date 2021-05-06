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

    setkeyup(ad);
    ad->ship->velocity.y = (float)-ad->var_game->speed;
    ad->ship->bshipt = ad->texture->th[0];
    if (secondso > 0.01) {
        ad->paralax->paralaxr.top -= (float)ad->var_game->speed / 2.0;
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

    setkeydown(ad);
    ad->ship->velocity.y = (float)ad->var_game->speed;
    ad->ship->bshipt = ad->texture->th[6];
    if (secondso > 0.01) {
        ad->paralax->paralaxr.top += (float)ad->var_game->speed / 2.0;
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

    ad->ship->velocity.x = (float)-ad->var_game->speed;
    ad->ship->bshipt = ad->texture->th[7];
    setkeyleft(ad);
    if (secondso > 0.01) {
        ad->paralax->paralaxr.left -= (float)ad->var_game->speed / 2.0;
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

    ad->ship->velocity.x = (float)ad->var_game->speed;
    ad->ship->bshipt = ad->texture->th[5];
    setkeyright(ad);
    if (secondso > 0.01) {
        ad->paralax->paralaxr.left += (float)ad->var_game->speed / 2.0;
        if (ad->paralax->paralaxr.left >= 3840)
            ad->paralax->paralaxr.left = 0;
        sfClock_restart(ad->paralax->paralo);
    }
    move_star_right(ad);
}