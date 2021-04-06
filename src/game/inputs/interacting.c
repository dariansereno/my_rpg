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
        ad->window->event.key.code == sfKeyE && planets->interact == true)
            printf("interaction\n");
            // create_planet_card(ad, (sfVector2f){ad->ship->viewrect.left, ad->ship->viewrect.top}); // APPELER LA FONCTION QUI GENERE L'UI, POSSIBLITE DE RECUPER
            //L'INDEX DE LA PLANETE AVEC LAQUELLE ON VIENS D'INTERAGIR : 
            //planets->index
            // position = 0, 0 = ad->ship->viewrect.left.top;
            // sprite = planets->planet.sprite
            // texture = ad->planets->textures[planets->planet.type]
        planets = planets->next;
    }
}