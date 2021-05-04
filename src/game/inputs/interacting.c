/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** interacting
*/

#include "my_rpg.h"

void more_interact(st_global *ad, list_planet planets)
{
    // if (ad->window->event.type == sfEvtKeyPressed && \
    // ad->window->event.key.code == sfKeyI && planets->interact == true
    // && planets->planet.tradable == true) {
    //     if (ad->ui->trade_card->existing) {
    //         ad->ui->trade_card->existing = false;
    //         return;
    //     }
        // for (int i = 0; planets->trade[i]->price != -1; i++) {
        //     printf("id = %d\n", planets->trade[i]->id);
        //     printf("price = %d\n", planets->trade[i]->price);
        //     printf("nb = %d\n", planets->trade[i]->nb);
        // }
    //     ad->ui->trade_card->existing = true;
    // }
}

void interaction_input(st_global *ad)
{
    list_planet planets = ad->planets->planets;

    while (planets != NULL) {
        if (ad->window->event.type == sfEvtKeyReleased && \
        ad->window->event.key.code == sfKeyE && planets->interact == true) {
            if (ad->ui->planet_card->existing) {
                destroy_planet_card(ad->ui->planet_card);
                return;
            }
            create_planet_card(ad, (sfVector2f){ad->ship->viewrect.left,
            ad->ship->viewrect.top}, planets);
        }
        if (ad->window->event.type == sfEvtKeyPressed && \
        ad->window->event.key.code == sfKeyI && planets->interact == true
        && planets->planet.tradable == true) {
            if (ad->ui->trade_card->existing) {
                ad->ui->trade_card->existing = false;
                return;
            }
            ad->ui->trade_card->existing = true;
        }
        if (ad->window->event.type == sfEvtKeyPressed && \
        ad->window->event.key.code == sfKeyF && planets->interact == true
        && planets->planet.colonized) {
            if (ad->ui->module_card->existing) {
                ad->ui->module_card->existing = false;
                return;
            }
            ad->ui->module_card->existing = true;
        }
        more_interact(ad, planets);
        planets = planets->next;
    }
    if (ad->window->event.type == sfEvtKeyPressed && \
        ad->window->event.key.code == sfKeyP) {
        if (ad->ui->pause->existing) {
            ad->ui->pause->existing = false;
            return;
        }
        ad->ui->pause->existing = true;
    }
    if (ad->window->event.type == sfEvtKeyPressed && \
        ad->window->event.key.code == sfKeyK) {
        if (ad->ui->end->existing) {
            ad->ui->end->existing = false;
            return;
        }
        ad->ui->end->existing = true;
    }
}