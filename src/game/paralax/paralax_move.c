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

    ad->ship->bshippos.y -= 5;
    ad->ship->viewrect.top -= 5;
    ad->paralax->starpos.y -= 5;
    ad->paralax->nebulapos.y -= 5;
    ad->ship->bshipt = sfTexture_createFromFile("contents/img/t1.png", NULL);
    setkeyup(ad);
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

    ad->ship->bshippos.y += 5;
    ad->ship->viewrect.top += 5;
    ad->paralax->starpos.y += 5;
    ad->paralax->nebulapos.y += 5;
    setkeydown(ad);
    ad->ship->bshipt = sfTexture_createFromFile("contents/img/t7.png", NULL);
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

    ad->ship->bshippos.x -= 5;
    ad->ship->viewrect.left -= 5;
    ad->paralax->starpos.x -= 5;
    ad->paralax->nebulapos.x -= 5;
    setkeyleft(ad);
    ad->ship->bshipt = sfTexture_createFromFile("contents/img/t8.png", NULL);
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

    ad->ship->bshippos.x += 5;
    ad->ship->viewrect.left += 5;
    ad->paralax->starpos.x += 5;
    ad->paralax->nebulapos.x += 5;
    setkeyright(ad);
    ad->ship->bshipt = sfTexture_createFromFile("contents/img/t6.png", NULL);
    if (secondso > 0.01) {
        ad->paralax->paralaxr.left += 2.5;
        if (ad->paralax->paralaxr.left >= 3840)
            ad->paralax->paralaxr.left = 0;
        sfClock_restart(ad->paralax->paralo);
    }
    move_star_right(ad);
}