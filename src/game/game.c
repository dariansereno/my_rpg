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
    == sfKeyZ)
        ad->key_pressed.Z = true;
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyZ)
        ad->key_pressed.Z = false;
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyS)
        ad->key_pressed.S = true;
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyS)
        ad->key_pressed.S = false;
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyD)
        ad->key_pressed.D = true;
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyD) {
        ad->key_pressed.D = false;
    }
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeyQ)
        ad->key_pressed.Q = true;
    if (ad->window->event.type == sfEvtKeyReleased && ad->window->event.key.code
    == sfKeyQ) {
        ad->key_pressed.Q = false;
    }
}

void check_event(st_global *ad)
{
    if (ad->window->event.type == sfEvtClosed) {
        sfRenderWindow_close(ad->window->window);
    }
    if (ad->window->event.type == sfEvtKeyPressed)
        change_key_press(ad);
    go_up(ad);
    go_down(ad);
    go_left(ad);
    go_right(ad);
    go_upright(ad);
    go_upleft(ad);
    go_downleft(ad);
    go_downright(ad);
    ad->key_pressed.Z = false;
    ad->key_pressed.D = false;
    ad->key_pressed.S = false;
    ad->key_pressed.Q = false;
}

void check_status(st_global *ad)
{
    sfRenderWindow_clear(ad->window->window, sfBlack);
    sfSprite_setTexture(ad->paralax->nebula, ad->paralax->nebulat, sfTrue);
    sfSprite_setTexture(ad->paralax->star, ad->paralax->start, sfTrue);
    sfSprite_setTextureRect(ad->paralax->star, ad->paralax->starr);
    sfSprite_setTextureRect(ad->paralax->nebula, ad->paralax->paralaxr);
    sfRenderWindow_drawSprite(ad->window->window, ad->paralax->nebula, NULL);
    sfRenderWindow_drawSprite(ad->window->window, ad->paralax->star, NULL);
    sfRenderWindow_display(ad->window->window);
    while (sfRenderWindow_pollEvent(ad->window->window, &ad->window->event)) {
        check_event(ad);
    }
}

int game_loop(void)
{
    st_global *ad = ini();

    sfRenderWindow_setFramerateLimit(ad->window->window, 120);
    while (sfRenderWindow_isOpen(ad->window->window)) {
        check_status(ad);
    }
}