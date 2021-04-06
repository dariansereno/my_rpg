/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** interacting
*/

#include "my_rpg.h"

void interaction_input(st_global *ad)
{
    list_planet planets = ad->planets->planets;

    while (planets != NULL) {
        if (ad->window->event.type == sfEvtKeyPressed && \
        ad->window->event.key.code == sfKeyE && planets->interact == true && \
        ad->ui->planet_card->existing == sfFalse)
            ad->ui->planet_card->displaying = sfTrue;
        if (ad->window->event.type == sfEvtKeyPressed && \
        ad->window->event.key.code == sfKeyE && \
        ad->ui->planet_card->existing == sfTrue && ad->ui->planet_card->displaying == sfTrue)
            ad->ui->planet_card->closing = sfTrue;
        if (ad->window->event.type == sfEvtKeyReleased && \
        ad->window->event.key.code == sfKeyE && planets->interact == true && \
        ad->ui->planet_card->displaying == sfTrue) {
            create_planet_card(ad, (sfVector2f){ad->ship->viewrect.left, ad->ship->viewrect.top});
        }
        if (ad->window->event.type == sfEvtKeyReleased && \
        ad->window->event.key.code == sfKeyE \
        && ad->ui->planet_card->closing == sfTrue) {
            ad->ui->planet_card->displaying = sfFalse;
            ad->ui->planet_card->existing = sfFalse;
            ad->ui->planet_card->closing = sfFalse;
        }
        planets = planets->next;
    }
}