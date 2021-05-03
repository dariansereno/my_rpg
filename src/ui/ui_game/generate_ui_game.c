/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** generate_ui_game
*/

#include "my_rpg.h"

ui_game_s *generate_ui_game(void)
{
    ui_game_s *ui = my_malloc(sizeof(*ui));

    ui->ui[1] = generate_object((sfVector2f){217, 63}, \
    (sfIntRect){0, 0, 275, 20}, "contents/ui/ui/life.png");
    ui->ui[0] = generate_object((sfVector2f){217, 77}, \
    (sfIntRect){0, 0, 275, 20}, "contents/ui/ui/credits.png");
    ui->ui[2] = generate_object((sfVector2f){217, 91}, \
    (sfIntRect){0, 0, 275, 20}, "contents/ui/ui/xp.png");
    ui->ui[3] = generate_object((sfVector2f){75, 41}, \
    (sfIntRect){0, 0, 183, 183}, "contents/ui/ui/map.png");
    return (ui);
}

void destroy_ui_game(ui_game_s *ui)
{
    destroy_object(ui->ui[0]);
    destroy_object(ui->ui[1]);
    destroy_object(ui->ui[2]);
    destroy_object(ui->ui[3]);
}