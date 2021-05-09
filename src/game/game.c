/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** game
*/

#include "my_rpg.h"

char *life_to_str(int life)
{
    char *result = my_malloc(sizeof(char) * 7);
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
    if (ad->window->event.type == sfEvtClosed)
        sfRenderWindow_close(ad->window->window);
    interaction_input(ad);
    if (ad->window->event.type == sfEvtKeyPressed && ad->window->event.key.code
    == sfKeySpace) {
        sfSound_play(ad->window->sfx->shoot);
        ship_shoot(ad);
    }
}

void check_status(st_global *ad)
{
    draw_window_game(ad);
    display_back_object(ad);
    display_if_not_menu(ad);
    spawn_boss_condition(ad);
    victory(ad);
    if (ad->money->money > ad->var_game->max_money)
        ad->money->money = ad->var_game->max_money;
    if (ad->var_game->life > ad->var_game->max_health)
        ad->var_game->life = ad->var_game->max_health;
    if (ad->var_game->boss_generated) {
        print_list_explo_boss(&ad->boss->li_big_explo, ad);
        print_list_explo_lil_boss(&ad->boss->li_lil_explo, ad);
    }
    if (ad->var_game->xp >= ad->var_game->max_xp)
        ad->var_game->xp = ad->var_game->max_xp;
    print_forground_and_event(ad);
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
    sfMusic_setVolume(ad->window->music, ad->window->music_volume);
    while (sfRenderWindow_isOpen(ad->window->window))
        screen(ad);
    destroy_global(ad);
    return (0);
}