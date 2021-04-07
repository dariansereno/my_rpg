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
        interaction_input_bis(ad, planets);
        if (ad->window->event.type == sfEvtKeyReleased && \
        ad->window->event.key.code == sfKeyE && planets->interact == true && \
        ad->ui->planet_card->displaying == true)
            create_planet_card(ad, (sfVector2f){ad->ship->viewrect.left, ad->ship->viewrect.top}, planets);
        if (ad->window->event.type == sfEvtKeyReleased && \
        ad->window->event.key.code == sfKeyE \
        && ad->ui->planet_card->closing == true)
            destroy_planet_card(ad);
        planets = planets->next;
    }
}

void interaction_input_bis(st_global *ad, list_planet planets)
{
    if (ad->window->event.type == sfEvtKeyPressed && \
    ad->window->event.key.code == sfKeyE && planets->interact == true && \
    ad->ui->planet_card->existing == false)
        ad->ui->planet_card->displaying = true;
    if (ad->window->event.type == sfEvtKeyPressed && \
    ad->window->event.key.code == sfKeyE && \
    ad->ui->planet_card->existing == true && ad->ui->planet_card->displaying == true)
        ad->ui->planet_card->closing = true;
}