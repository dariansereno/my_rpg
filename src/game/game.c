/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** game
*/

#include "my_rpg.h"

void check_event(st_global *ad)
{
    if (ad->window->event.type == sfEvtClosed || (ad->window->event.type ==
    sfEvtKeyPressed &&  ad->window->event.key.code == sfKeyEscape)) {
        sfRenderWindow_close(ad->window->window);
        sfMusic_destroy(ad->window->music);
    }
    interaction_input(ad);
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
    animate_planets(ad);
    if (ad->ui->planet_card->existing == false) {
        spatial_object_move(ad);
        ennemies_spawning(ad);
        display_interaction(ad);
    }
    print_planet_list(ad->planets->planets, ad->window->window);
    display_planet_card(ad);
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
        planet_collision(ad);
        display_on_view(ad);
        interaction(ad);
        check_status(ad);
        if (ad->ui->planet_card->existing == false)
            paralax_move(ad);
    }
    destroy_global(ad);
    return (0);
}