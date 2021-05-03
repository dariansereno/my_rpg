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
    (sfIntRect){0, 0, 14, 14}, "contents/UI/buttons/interact.png");
    ui->selector = my_malloc(sizeof(*ui->selector) * 3);
    ui->selector[0] = generate_object((sfVector2f){0, 0},
    (sfIntRect){0, 0, 54, 54}, "contents/img/sp/selectorpl.png");
    ui->selector[1] = generate_object((sfVector2f){0, 0},
    (sfIntRect){0, 0, 78, 78}, "contents/img/sp/selectorsun.png");
    ui->selector[2] = generate_object((sfVector2f){0, 0},
    (sfIntRect){0, 0, 63, 64}, "contents/img/sp/selectorbh.png");
    ui->planet_card = generate_planet_card();
    ui->trade_card = generate_trade_card();
    ui->loading_board = generate_loading_board();
    ui->menu = generate_menu();
    ui->fade = generate_fade();
    ui->settings = generate_settings();
    return (ui);
}

void destroy_ui(st_ui *ui)
{
    destroy_object(ui->selector[0]);
    destroy_object(ui->selector[1]);
    destroy_object(ui->selector[2]);
    destroy_object(ui->interacting);
    destroy_trade_card(ui->trade_card);
    destroy_menu(ui->menu);
    destroy_fade(ui->fade);
    destroy_settings(ui->settings);
    ui = NULL;
}