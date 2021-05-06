/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** game
*/

#include "my_rpg.h"

void change_key_press(st_global *ad)
{
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyZ) {
        ad->key_pressed.Z = true;
        ad->paralax->i = 1;
    }
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyZ) {
        ad->key_pressed.Z = false;
        ad->paralax->i = 0;
    }
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyS) {
        ad->key_pressed.S = true;
        ad->paralax->j = 1;
    }
    extra_change(ad);
}

void extra_change(st_global *ad)
{
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyS) {
        ad->key_pressed.S = false;
        ad->paralax->j = 0;
    }
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyD) {
        ad->key_pressed.D = true;
        ad->paralax->k = 1;
    }
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyD) {
        ad->key_pressed.D = false;
        ad->paralax->k = 0;
    }
    more_key_change(ad);
}

void key_change_again(st_global *ad)
{
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyReturn)
        ad->key_pressed.Enter = true;
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyReturn)
        ad->key_pressed.Enter = false;
    if (ad->ui->pause_settings->existing)
        events_pause_settings(ad);
    plus_key_change(ad);
}

void more_key_change(st_global *ad)
{
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyQ) {
        ad->key_pressed.Q = true;
        ad->paralax->l = 1;
    }
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyQ) {
        ad->key_pressed.Q = false;
        ad->paralax->l = 0;
    }
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyJ)
        ad->key_pressed.J = true;
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyJ)
        ad->key_pressed.J = false;
    key_change_again(ad);
}
