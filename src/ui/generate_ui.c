/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_game_ui
*/

#include "my_rpg.h"

st_ui *generate_ui()
{
    st_ui *ui = malloc(sizeof(*ui));

    ui->interacting = generate_object((sfVector2f){0, 0},
    (sfIntRect){0, 0, 14, 14}, "contents/UI/buttons/interact.png");
    ui->selector = malloc(sizeof(*ui->selector) * 3);
    ui->selector[0] = generate_object((sfVector2f){0, 0},
    (sfIntRect){0, 0, 54, 54}, "contents/img/sp/selectorpl.png");
    ui->selector[1] = generate_object((sfVector2f){0, 0},
    (sfIntRect){0, 0, 78, 78}, "contents/img/sp/selectorsun.png");
    ui->selector[2] = generate_object((sfVector2f){0, 0},
    (sfIntRect){0, 0, 63, 64}, "contents/img/sp/selectorbh.png");
    return (ui);
}

void destroy_ui(st_ui *ui)
{
    destroy_object(ui->selector[0]);
    destroy_object(ui->selector[1]);
    destroy_object(ui->selector[2]);
    destroy_object(ui->interacting);
    ui = NULL;
}