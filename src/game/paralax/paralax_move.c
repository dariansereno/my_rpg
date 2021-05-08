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
    ad->ship->velocity.y = (int)-ad->var_game->speed;
    ad->ship->bshipt = ad->texture->th;
    sfSprite_setRotation(ad->ship->bship, 0);
    if (secondso > 0.01) {
        ad->paralax->paralaxr.top -= (int)ad->var_game->speed / 2;
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
    ad->ship->velocity.y = (int)ad->var_game->speed;
    ad->ship->bshipt = ad->texture->th;
    sfSprite_setRotation(ad->ship->bship, 180);
    if (secondso > 0.01) {
        ad->paralax->paralaxr.top += (int)ad->var_game->speed / 2;
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

    ad->ship->velocity.x = (int)-ad->var_game->speed;
    ad->ship->bshipt = ad->texture->th;
    sfSprite_setRotation(ad->ship->bship, 270);
    setkeyleft(ad);
    if (secondso > 0.01) {
        ad->paralax->paralaxr.left -= (int)ad->var_game->speed / 2;
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

    ad->ship->velocity.x = (int)ad->var_game->speed;
    ad->ship->bshipt = ad->texture->th;
    sfSprite_setRotation(ad->ship->bship, 90);
    setkeyright(ad);
    if (secondso > 0.01) {
        ad->paralax->paralaxr.left += (int)ad->var_game->speed / 2;
        if (ad->paralax->paralaxr.left >= 3840)
            ad->paralax->paralaxr.left = 0;
        sfClock_restart(ad->paralax->paralo);
    }
    move_star_right(ad);
}