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
        ad->window->event.key.code == sfKeyE && planets->interact == true && 
        ad->ui->trade_card->existing == false && \
        ad->ui->module_card->existing == false && \
        ad->ui->pause->existing == false) {
            if (ad->ui->planet_card->existing) {
                ad->ui->planet_card->existing = false;
                destroy_planet_card(ad->ui->planet_card);
                return;
            }
            create_planet_card(ad, (sfVector2f){ad->ship->viewrect.left,
            ad->ship->viewrect.top}, planets);
        }
        if (ad->window->event.type == sfEvtKeyPressed && \
        ad->window->event.key.code == sfKeyI && planets->interact == true
        && planets->planet.tradable == true && \
        ad->ui->module_card->existing == false && \
        ad->ui->pause->existing == false && \
        ad->ui->planet_card->existing == false) {
            if (ad->ui->trade_card->existing) {
                ad->ui->trade_card->existing = false;
                return;
            }
            ad->ui->trade_card->existing = true;
        }
        if (ad->window->event.type == sfEvtKeyPressed && \
        ad->window->event.key.code == sfKeyF && planets->interact == true
        && planets->planet.colonized && ad->ui->trade_card->existing == false \
        && ad->ui->planet_card->existing == false && \
        ad->ui->pause->existing == false) {
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
        ad->window->event.key.code == sfKeyEscape) {
        if (ad->ui->pause->existing && ad->ui->trade_card->existing == false &&
        ad->ui->module_card->existing == false && \
        ad->ui->planet_card->existing == false && \
        ad->ui->pause_settings->existing == false) {
            ad->ui->pause->existing = false;
            return;
        }
        ad->ui->pause->existing = true;
    }
    if (ad->key_pressed.Enter) {
        if (ad->text->existing) {
            int counter = backslash_n_counter(ad);
            if (counter >= 3 && sfRectangleShape_getSize(ad->text->text_r3).x <= 0) {
                sfRectangleShape_setSize(ad->text->text_r1, (sfVector2f){1160, -40});
                sfRectangleShape_setSize(ad->text->text_r2, (sfVector2f){1160, -40});
                sfRectangleShape_setSize(ad->text->text_r3, (sfVector2f){1160, -40});
                ad->text->str = cpy_to_up_text(ad);
                sfText_setString(ad->text->text, ad->text->str);
            }
            if (counter == 2 && sfRectangleShape_getSize(ad->text->text_r3).x <= 0)
                ad->text->existing = false;
            if (counter == 1 && sfRectangleShape_getSize(ad->text->text_r2).x <= 0)
                ad->text->existing = false;
            if (counter == 0 && sfRectangleShape_getSize(ad->text->text_r1).x <= 0)
                ad->text->existing = false;
        }
    }
}