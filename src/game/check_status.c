/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** check_status
*/

#include "my_rpg.h"

void draw_window_game(st_global *ad)
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
}

void display_back_object(st_global *ad)
{
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
}

void display_if_not_menu_2(st_global *ad)
{
        print_list_explo(&ad->shoot->li_explo, ad);
        print_list_particle_explo(&ad->particle->particles, ad);
        effect_extract_module(ad);
        effect_com_module(ad);
        effect_health_module(ad);
        print_list_particle(&ad->particle->particles, ad);
        print_planet_list_big(ad->planets->planets, ad->window->window, ad);
        display_upgrade(ad);
        choose_upgrade(ad);
        display_ui_game(ad);
        display_items_inventory(ad);
        craft_settler(ad);
        display_stats_ship(ad);
        target_quest(ad);
        print_target_indicator(ad);
        display_msg(ad);
}

void display_if_not_menu(st_global *ad)
{
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
        display_if_not_menu_2(ad);
    }
}

void print_forground_and_event(st_global *ad)
{
    add_particles(ad);
    check_quest(ad);
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