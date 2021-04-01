/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** game
*/

#include "my_rpg.h"

void change_key_press(st_global *ad)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) 
        ad->paralax->move.y = -10;
    if (!sfKeyboard_isKeyPressed(sfKeyZ))
        ad->paralax->move.y = 0;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        ad->paralax->move.y  = 10;
    if (!sfKeyboard_isKeyPressed(sfKeyS))
        ad->paralax->move.y = 0;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        ad->paralax->move.x = 10;
    if (!sfKeyboard_isKeyPressed(sfKeyD))
        ad->paralax->move.x = 0;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        ad->paralax->move.x = -10;
    if (!sfKeyboard_isKeyPressed(sfKeyQ))
        ad->paralax->move.x = 0;
}

void check_event(st_global *ad)
{
    sfTime time = sfClock_getElapsedTime(ad->paralax->clock);
    float seconds = time.microseconds / 1000000.0;

    if (ad->window->event.type == sfEvtClosed) {
        sfRenderWindow_close(ad->window->window);
        sfMusic_destroy(ad->window->music);
    }
    printf("%d\n", sfKeyCount);
    // go_up(ad);
 
    // go_down(ad);
    // go_left(ad);
    // go_right(ad);
    // go_upleft(ad);
    // go_upright(ad);
    // go_downleft(ad);
    // go_downright(ad);
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
        if (ad->window->event.type == sfEvtKeyPressed)
            change_key_press(ad);
        check_event(ad);
    }
}

int game_loop(void)
{
    st_global *ad = ini();
    sfRenderWindow_setKeyRepeatEnabled(ad->window->window, false);

    sfMusic_play(ad->window->music);
    sfMusic_setLoop(ad->window->music, sfTrue);
    sfRenderWindow_setFramerateLimit(ad->window->window, 120);
    while (sfRenderWindow_isOpen(ad->window->window)) {
        check_status(ad);
        // go_up(ad);
        move_up(ad);
    }
}