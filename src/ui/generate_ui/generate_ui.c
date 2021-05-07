/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_game_ui
*/

#include "my_rpg.h"

st_ui *generate_ui(void)
{
    st_ui *ui = my_malloc(sizeof(*ui));

    ui->interacting = generate_object((sfVector2f){0, 0},
    (sfIntRect){0, 0, 14, 14}, "contents/ui/buttons/interact.png");
    ui->selector = my_malloc(sizeof(*ui->selector) * 3);
    ui->selector[0] = generate_object((sfVector2f){0, 0},
    (sfIntRect){0, 0, 54, 54}, "contents/img/sp/selectorpl.png");
    ui->selector[1] = generate_object((sfVector2f){0, 0},
    (sfIntRect){0, 0, 78, 78}, "contents/img/sp/selectorsun.png");
    ui->selector[2] = generate_object((sfVector2f){0, 0},
    (sfIntRect){0, 0, 63, 64}, "contents/img/sp/selectorbh.png");
    ui->planet_card = generate_planet_card();
    ui->trade_card = generate_trade_card();
    ui->module_card = generate_module_card();
    ui->ui = generate_ui_game();
    ui->pause = generate_pause();
    ui->loading_board = generate_loading_board();
    ui->menu = generate_menu();
    ui->end = generate_end();
    ui->fade = generate_fade();
    ui->settings = generate_settings();
    ui->pause_settings = generate_pause_settings();
    // ui->boss = generate_boss();
    return (ui);
}

void destroy_ui(st_ui *ui)
{
    destroy_object(ui->selector[0]);
    destroy_object(ui->selector[1]);
    destroy_object(ui->selector[2]);
    destroy_object(ui->interacting);
    destroy_module_card(ui->module_card);
    destroy_trade_card(ui->trade_card);
    destroy_ui_game(ui->ui);
    destroy_menu(ui->menu);
    destroy_end(ui->end);
    destroy_fade(ui->fade);
    destroy_settings(ui->settings);
    destroy_pause(ui->pause);
    destroy_pause_settings(ui->pause_settings);
    // destroy_boss(ui->boss);
    ui = NULL;
}