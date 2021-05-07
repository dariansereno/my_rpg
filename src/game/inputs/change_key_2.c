/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** change_key_2
*/

#include "my_rpg.h"

void again_plus_key_change(st_global *ad)
{
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyU)
        ad->key_pressed.U = true;
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyU)
        ad->key_pressed.U = false;
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyX)
        ad->key_pressed.X = true;
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyX)
        ad->key_pressed.X = false;
}

void plus_key_change(st_global *ad)
{
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyR)
        ad->key_pressed.R = true;
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyR)
        ad->key_pressed.R = false;
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyT)
        ad->key_pressed.T = true;
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyT)
        ad->key_pressed.T = false;
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyY)
        ad->key_pressed.Y = true;
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyY)
        ad->key_pressed.Y = false;
    again_plus_key_change(ad);
}
