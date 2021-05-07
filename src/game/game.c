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
    colonise_planet(ad);
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
    sfSprite_setTexture(ad->ship->bship, ad->ship->bshipt, sfTrue);
    sfSprite_setTexture(ad->paralax->nebula, ad->paralax->nebulat, sfTrue);
    sfSprite_setTexture(ad->paralax->star, ad->paralax->start, sfTrue);
    sfSprite_setTextureRect(ad->paralax->star, ad->paralax->starr);
    sfSprite_setTextureRect(ad->paralax->nebula, ad->paralax->paralaxr);
    sfSprite_setPosition(ad->ship->bship, ad->ship->bshippos);
    sfSprite_setPosition(ad->paralax->nebula, ad->paralax->nebulapos);
    sfSprite_setPosition(ad->paralax->star, ad->paralax->starpos);
    sfRenderWindow_drawSprite(ad->window->window, ad->paralax->nebula, NULL);
    display_boss_bg(ad);
    print_spaceobj_list(ad->space_obj->li, ad->window->window, ad);
    sfRenderWindow_drawSprite(ad->window->window, ad->paralax->star, NULL);
    print_planet_list_little(ad->planets->planets, ad->window->window, ad);
    print_list_shoot(&ad->shoot->li_shoot, ad->shoot->sprite_ship, ad);
    sfRenderWindow_drawSprite(ad->window->window, ad->ship->bship, NULL);
    animate_planets(ad);
    draw_map_limit(ad);
    collision_limit(ad);
    is_craftable(ad);
    can_upgrade(ad);
    print_planet_list_normal(ad->planets->planets, ad->window->window, ad);
    print_list_drop(&ad->drop, ad);
    boss_handling(ad);
    if (ad->ui->planet_card->existing == false && \
    ad->ui->trade_card->existing == false && \
    ad->ui->module_card->existing == false && \
    ad->ui->pause->existing == false && ad->ui->end->existing == false) {
        spatial_object_move(ad);
        display_interaction(ad);
        print_colonised_selec(ad);
        print_can_colonise(ad);
        print_can_trade(ad);
        print_can_quest(ad);
        colonise_planet(ad);
        ennemies_spawning(ad);
        print_list_explo(&ad->shoot->li_explo, ad);
        effect_extract_module(ad);
        effect_com_module(ad);
        effect_health_module(ad);
        print_planet_list_big(ad->planets->planets, ad->window->window, ad);
        target_quest(ad);
        print_target_indicator(ad);
        display_upgrade(ad);
        choose_upgrade(ad);
        display_ui_game(ad);
        display_items_inventory(ad);
        craft_settler(ad);
        display_stats_ship(ad);
        // boss_life(ad);
    }
    display_planet_card(ad);
    display_trade_card(ad);
    display_module_card(ad);
    display_pause(ad);
    display_pause_settings(ad);
    display_end(ad);
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
    generate_random_colonised(&ad->planets->planets, ad);
    generate_random_quest(&ad->planets->planets, ad);
    generate_trade(ad, &ad->planets->planets);
    sfMusic_play(ad->window->music);
    sfMusic_setLoop(ad->window->music, sfTrue);
    sfMusic_setVolume(ad->window->music, 0);
    while (sfRenderWindow_isOpen(ad->window->window))
        screen(ad);
    destroy_global(ad);
    return (0);
}