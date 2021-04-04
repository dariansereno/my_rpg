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
        if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
        == sfKeyE && planets->interact == true)
            printf("interaction\n"); // APPELER LA FONCTION QUI GENERE L'UI, POSSIBLITE DE RECUPER
            //L'INDEX DE LA PLANETE AVEC LAQUELLE ON VIENS D'INTERAGIR : 
            //planets->index
        planets = planets->next;
    }
}