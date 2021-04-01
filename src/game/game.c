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
}

void check_event(st_global *ad)
{
    if (ad->window->event.type == sfEvtClosed || (ad->window->event.type ==
    sfEvtKeyPressed &&  ad->window->event.key.code == sfKeyEscape)) {
        sfRenderWindow_close(ad->window->window);
        sfMusic_destroy(ad->window->music);
    }
}

void check_status(st_global *ad)
{
    sfRenderWindow_setView(ad->window->window, ad->ship->view);
    sfRenderWindow_clear(ad->window->window, sfBlack);
    sfSprite_setTexture(ad->ship->bship, ad->ship->bshipt, sfTrue);
    sfSprite_setTexture(ad->paralax->nebula, ad->paralax->nebulat, sfTrue);
    sfSprite_setTexture(ad->paralax->star, ad->paralax->start, sfTrue);
    sfSprite_setTextureRect(ad->paralax->star, ad->paralax->starr);
    sfSprite_setTextureRect(ad->paralax->nebula, ad->paralax->paralaxr);
    sfSprite_setPosition(ad->ship->bship, ad->ship->bshippos);
    sfSprite_setPosition(ad->paralax->nebula, ad->paralax->nebulapos);
    sfSprite_setPosition(ad->paralax->star, ad->paralax->starpos);
    sfRenderWindow_drawSprite(ad->window->window, ad->paralax->nebula, NULL);
    sfRenderWindow_drawSprite(ad->window->window, ad->paralax->star, NULL);
    sfRenderWindow_drawSprite(ad->window->window, ad->ship->bship, NULL);
    print_planet_list(ad->planets->planets, ad->window->window);
    sfRenderWindow_display(ad->window->window);
    while (sfRenderWindow_pollEvent(ad->window->window, &ad->window->event)) {
        change_key_press(ad);
        check_event(ad);
    }
}

int game_loop(void)
{
    st_global *ad = ini();

    sfMusic_play(ad->window->music);
    sfMusic_setLoop(ad->window->music, sfTrue);
    sfMusic_setVolume(ad->window->music, 20);
    sfRenderWindow_setFramerateLimit(ad->window->window, 120);
    ad->planets = generate_all_map();
    while (sfRenderWindow_isOpen(ad->window->window)) {
        ad->ship->view = sfView_createFromRect(ad->ship->viewrect);
        check_status(ad);
        go_up(ad);
        go_down(ad);
        go_left(ad);
        go_right(ad);
        go_upright(ad);
        go_upleft(ad);
        go_downleft(ad);
        go_downright(ad);
    }
    return (0);
}