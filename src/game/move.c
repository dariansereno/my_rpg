/*
** EPITECH PROJECT, 2021
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** get movements
*/

#include "my_rpg.h"

void go_up(st_global *ad)
{
    int i = 0;

    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyZ) {
        i = 1;
    }
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyZ) {
        i = -1;
    }
    i = 0;
}

void go_down(st_global *ad)
{
    int i = 0;

    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyS) {
        i = 1;
    }
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyS) {
        i = -1;
    }
    i = 0;
}

void go_left(st_global *ad)
{
    int i = 0;

    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyQ) {
        i = 1;
    }
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyQ) {
        i = -1;
    }
    i = 0;
}

void go_right(st_global *ad)
{
    int i = 0;

    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyD) {
        i = 1;
    }
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyD) {
        i = -1;
    }
    i = 0;
}