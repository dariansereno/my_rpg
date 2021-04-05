/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** game
*/

#include "my_rpg.h"

st_global *generate_global(void)
{
    st_global *global = malloc(sizeof(*global));
    global->talk_text = malloc(sizeof(*global->talk_text));
    global->talk_text->black_outline = sfRectangleShape_create();
    global->talk_text->purple_outline = sfRectangleShape_create();
    global->talk_text->white_rectangle = sfRectangleShape_create();
    global->talk_text->talk_text = sfText_create();
    global->talk_text->talk_font = sfFont_createFromFile("contents/fonts/dogica/TTF/dogicapixel.ttf");
    global->talk_text->existing = sfFalse;
    global->talk_text->clock = sfClock_create();
    global->talk_text->speed_text_rect_line1 = (sfIntRect){0, 0, 0, 0};
    global->talk_text->speed_text_rect_line2 = (sfIntRect){0, 0, 0, 0};
    global->talk_text->speed_text_rect_line3 = (sfIntRect){0, 0, 0, 0};
    global->talk_text->speed_text_sprite_line1 = sfSprite_create();
    global->talk_text->speed_text_texture_line1 = sfTexture_createFromFile("./contents/white_rect.jpg", NULL);
    global->talk_text->speed_text_sprite_line2 = sfSprite_create();
    global->talk_text->speed_text_texture_line2 = sfTexture_createFromFile("./contents/white_rect.jpg", NULL);
    global->talk_text->speed_text_sprite_line3 = sfSprite_create();
    global->talk_text->speed_text_texture_line3 = sfTexture_createFromFile("./contents/white_rect.jpg", NULL);
    return (global);
}

int game_loop_2()
{
    sfEvent event;
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};

    window = sfRenderWindow_create(mode, "my_defender", sfResize | sfClose, \
    NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    st_global *global = generate_global();

    if (window != NULL) {
        while (sfRenderWindow_isOpen(window)) {
            sfRenderWindow_clear(window, sfWhite);
            while (sfRenderWindow_pollEvent(window, &event)) {
                if (event.type == sfEvtClosed)
                    sfRenderWindow_close(window);
                else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
                    sfRenderWindow_close(window);
                if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD)
                    dialogue_text(global, "Bonjour à toi jeune entrepreneur, pour ta première quête... Tu vas devoir\ntrouver le joyau qui est disposé être au fond de la chaîne des \nAndesen Amérique Latine", 100);
            }
            clock_dialogue_text_line1(global);
            clock_dialogue_text_line2(global);
            clock_dialogue_text_line3(global);
            display_dialogue_text(window, global);
            sfRenderWindow_display(window);
        }
        sfRenderWindow_destroy(window);
    }
    return (0);
}

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
    spatial_object_move(ad);
    // ennemies_spawning(ad);
    print_planet_list(ad->planets->planets, ad->window->window);
    display_interaction(ad);
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
        paralax_move(ad);
    }
    destroy_global(ad);
    return (0);
}