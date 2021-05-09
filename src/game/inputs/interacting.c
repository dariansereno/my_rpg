/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** interacting
*/

#include "my_rpg.h"

void interact_input5(st_global *ad)
{
    int counter = 0;

    if (ad->text->existing) {
        counter = backslash_n_counter(ad);
        interact_input7(ad, counter);
        if (counter == 2 && sfRectangleShape_getSize(ad->text->text_r3).x <= 0)
            ad->text->existing = false;
        if (counter == 1 && sfRectangleShape_getSize(ad->text->text_r2).x <= 0)
            ad->text->existing = false;
        if (counter == 0 && sfRectangleShape_getSize(ad->text->text_r1).x <= 0)
            ad->text->existing = false;
    }
}

int interact_input4(st_global *ad, list_planet *planets)
{
    if (ad->window->event.type == sfEvtKeyPressed && \
    ad->window->event.key.code == sfKeyF && (*planets)->interact == true
    && (*planets)->planet.colonized && ad->ui->trade_card->existing == false \
    && ad->ui->planet_card->existing == false && \
    ad->ui->pause->existing == false) {
        if (ad->ui->module_card->existing) {
            ad->ui->module_card->existing = false;
            return (1);
        }
        ad->ui->module_card->existing = true;
    }
    return (0);
}

int interact_input3(st_global *ad, list_planet *planets)
{
    if (ad->window->event.type == sfEvtKeyPressed && \
    ad->window->event.key.code == sfKeyI && (*planets)->interact == true
    && (*planets)->planet.tradable == true && \
    ad->ui->module_card->existing == false && \
    ad->ui->pause->existing == false && \
    ad->ui->planet_card->existing == false) {
        if (ad->ui->trade_card->existing) {
            ad->ui->trade_card->existing = false;
            return (1);
        }
        ad->ui->trade_card->existing = true;
    }
    return (0);
}

int interact_input2(st_global *ad, list_planet *planets)
{
    if (ad->window->event.type == sfEvtKeyReleased && \
    ad->window->event.key.code == sfKeyE && (*planets)->interact == true &&
    ad->ui->trade_card->existing == false && \
    ad->ui->module_card->existing == false && \
    ad->ui->pause->existing == false) {
        if (ad->ui->planet_card->existing) {
            ad->ui->planet_card->existing = false;
            destroy_planet_card(ad->ui->planet_card);
            return (1);
        }
        create_planet_card(ad, (sfVector2f){ad->ship->viewrect.left,
        ad->ship->viewrect.top}, (*planets));
    }
    return (0);
}

void interaction_input(st_global *ad)
{
    list_planet planets = ad->planets->planets;

    while (planets != NULL) {
        if (interact_input2(ad, &planets) == 1)
            return;
        if (interact_input3(ad, &planets) == 1)
            return;
        if (interact_input4(ad, &planets) == 1)
            return;
        planets = planets->next;
    }
    if (interact_input6(ad) == 1)
        return;
    if (ad->key_pressed.Enter)
        interact_input5(ad);
}