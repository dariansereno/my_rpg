/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** target_indicator
*/

#include "my_rpg.h"

sfVector2f target_indicator(st_global *ad, sfVector2f obj)
{
    sfVector2f tar_scr = (sfVector2f){obj.x - ad->ship->viewrect.left,
    obj.y - ad->ship->viewrect.top};
    sfVector2f tar_ctr = (sfVector2f){tar_scr.x - (WIDTH / 2), tar_scr.y -
    (HEIGHT / 2)};
    float rotation = atan2((double)tar_ctr.y, (double)tar_ctr.x);
    float slope;
    sfVector2f pad_size;
    sfVector2f indicator;

    rotation = rotation * 180 / M_PI;
    slope = tar_ctr.y / tar_ctr.x;
    pad_size = (sfVector2f){WIDTH - 100, HEIGHT - 100};
    if (tar_ctr.y < 0)
        indicator = (sfVector2f){(-pad_size.y / 2) / slope,
        (-pad_size.y / 2)};
    else if (tar_ctr.y > 0)
        indicator = (sfVector2f){(pad_size.y / 2) / slope,
        (pad_size.y / 2)};

    if (indicator.x < -pad_size.x / 2)
        indicator = (sfVector2f){-pad_size.x / 2, slope * -pad_size.x / 2};
    else if (indicator.x > pad_size.x / 2)
        indicator = (sfVector2f){pad_size.x / 2, slope * pad_size.x / 2};
    indicator = (sfVector2f){indicator.x + ad->ship->viewrect.left + (WIDTH / 2),
    indicator.y + ad->ship->viewrect.top + (HEIGHT / 2)};
    return (indicator);
}

bool is_on_screen(st_global *ad, sfVector2i pl)
{
    if (!sfFloatRect_contains(&ad->ship->viewrect, (float)pl.x, (float)pl.y))
        return (false);
    return (true);
}

void print_target_indicator(st_global *ad)
{
    list_planet pl = ad->planets->planets;

    while (pl != NULL) {
        if (pl->planet.colonized && !is_on_screen(ad, pl->planet.pos)) {
            sfText_setPosition(ad->ressources[0].text, target_indicator(ad,
            (sfVector2f){(float)pl->planet.pos.x, (float)pl->planet.pos.y}));
            sfText_setString(ad->ressources[0].text, number_and_string
            (pl->index, "n.\0"));
            sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text,
            NULL);
        }
        pl = pl->next;
    }
}