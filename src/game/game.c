/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** game
*/

#include "my_rpg.h"

char *life_to_str(int life)
{
    char *result = malloc(sizeof(char) * 7);
    char temp[8];
    int a = 0;
    int i = 0;

    for (; life > 9; a++) {
        temp[a] = (life % 10) + 48;
        life = life / 10;
    }
    temp[a] = (life % 10) + 48;
    temp[a+1] = '\0';
    for (; a != -1; i++, a--) {
        result[i] = temp[a];
    }
    result[i] = '\0';
    return (result);
}

void check_event(st_global *ad)
{
    if (ad->window->event.type == sfEvtClosed || (ad->window->event.type ==
    sfEvtKeyPressed &&  ad->window->event.key.code == sfKeyEscape))
        sfRenderWindow_close(ad->window->window);
    interaction_input(ad);
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeySpace)
        ship_shoot(ad);
}

void check_status(st_global *ad)
{
    sfRenderWindow_setView(ad->window->window, ad->ship->view);
    sfRenderWindow_clear(ad->window->window, sfBlack);
    sfText_setFont(ad->money->moneytext, ad->money->moneyfont);
    sfText_setFont(ad->money->moneyval, ad->money->moneyfont);
    sfText_setString(ad->money->moneytext, "credits: ");
    sfText_setString(ad->money->moneyval, life_to_str(ad->money->money));
    sfSprite_setTexture(ad->ship->bship, ad->ship->bshipt, sfTrue);
    sfSprite_setTexture(ad->paralax->nebula, ad->paralax->nebulat, sfTrue);
    sfSprite_setTexture(ad->paralax->star, ad->paralax->start, sfTrue);
    sfSprite_setTextureRect(ad->paralax->star, ad->paralax->starr);
    sfSprite_setTextureRect(ad->paralax->nebula, ad->paralax->paralaxr);
    sfSprite_setPosition(ad->ship->bship, ad->ship->bshippos);
    sfSprite_setPosition(ad->paralax->nebula, ad->paralax->nebulapos);
    sfSprite_setPosition(ad->paralax->star, ad->paralax->starpos);
    sfText_setCharacterSize(ad->money->moneytext, 50);
    sfText_setCharacterSize(ad->money->moneyval, 50);
    sfText_setPosition(ad->money->moneytext, (sfVector2f)
    {ad->ship->viewrect.left + 50, ad->ship->viewrect.top + 75});
    sfText_setPosition(ad->money->moneyval, (sfVector2f)
    {ad->ship->viewrect.left + 250, ad->ship->viewrect.top + 75});
    sfRenderWindow_drawSprite(ad->window->window, ad->paralax->nebula, NULL);
    sfRenderWindow_drawSprite(ad->window->window, ad->paralax->star, NULL);
    print_lil_planet(ad->planets->planets, ad->window->window, ad);
    print_list_shoot(&ad->shoot->li_shoot, ad->shoot->sprite_ship, ad);
    sfRenderWindow_drawSprite(ad->window->window, ad->ship->bship, NULL);
    sfRenderWindow_drawText(ad->window->window, ad->money->moneytext, NULL);
    sfRenderWindow_drawText(ad->window->window, ad->money->moneyval, NULL);
    animate_planets(ad);
    print_planet_list(ad->planets->planets, ad->window->window, ad);
    if (ad->ui->planet_card->existing == false && \
    ad->ui->trade_card->existing == false && \
    ad->ui->module_card->existing == false && \
    ad->ui->pause->existing == false) {
        spatial_object_move(ad);
        ennemies_spawning(ad);
        display_interaction(ad);
        display_ui_game(ad);
        print_list_explo(&ad->shoot->li_explo, ad);
    }
    display_planet_card(ad);
    display_trade_card(ad);
    display_module_card(ad);
    display_pause(ad);
    display_pause_settings(ad);
    sfRenderWindow_display(ad->window->window);
    sfSprite_setPosition(ad->ship->bship, ad->ship->bshippos);
    while (sfRenderWindow_pollEvent(ad->window->window, &ad->window->event)) {
        change_key_press(ad);
        last_key_pressed(ad);
        check_event(ad);
    }
}

int game_loop(void)
{
    st_global *ad = ini();
    ad->planets = generate_all_map();
    generate_trade(ad, &ad->planets->planets);

    sfMusic_play(ad->window->music);
    sfMusic_setLoop(ad->window->music, sfTrue);
    sfMusic_setVolume(ad->window->music, 0);
    sfRenderWindow_setFramerateLimit(ad->window->window, 120);
    sfRenderWindow_setMouseCursorVisible(ad->window->window, sfFalse);
    while (sfRenderWindow_isOpen(ad->window->window))
        screen(ad);
    destroy_global(ad);
    return (0);
}