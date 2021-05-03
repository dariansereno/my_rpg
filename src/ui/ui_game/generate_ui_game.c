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

    ui->life = sfRectangleShape_create();
    ui->credits = sfRectangleShape_create();
    ui->xp = sfRectangleShape_create();
    set_rectangle_ui_game(ui);
    ui->map = generate_object((sfVector2f){75, 41}, \
    (sfIntRect){0, 0, 183, 183}, "contents/UI/ui/map.png");
    return (ui);
}

void set_rectangle_ui_game(ui_game_s *ui)
{
    sfRectangleShape_setSize(ui->life, (sfVector2f){263, 10});
    sfRectangleShape_setFillColor(ui->life, sfColor_fromRGB(237, 28, 36));
    sfRectangleShape_setOutlineColor(ui->life, sfColor_fromRGB(179, 130, 188));
    sfRectangleShape_setOutlineThickness(ui->life, 6);
    sfRectangleShape_setPosition(ui->life, (sfVector2f){217, 63});
    sfRectangleShape_setSize(ui->credits, (sfVector2f){263, 10});
    sfRectangleShape_setFillColor(ui->credits, sfColor_fromRGB(255, 242, 0));
    sfRectangleShape_setOutlineColor(ui->credits, sfColor_fromRGB(179, 130, 188));
    sfRectangleShape_setOutlineThickness(ui->credits, 6);
    sfRectangleShape_setPosition(ui->credits, (sfVector2f){217, 77});
    sfRectangleShape_setSize(ui->xp, (sfVector2f){263, 10});
    sfRectangleShape_setFillColor(ui->xp, sfColor_fromRGB(0, 255, 255));
    sfRectangleShape_setOutlineColor(ui->xp, sfColor_fromRGB(179, 130, 188));
    sfRectangleShape_setOutlineThickness(ui->xp, 6);
    sfRectangleShape_setPosition(ui->xp, (sfVector2f){217, 91});
}

void destroy_ui_game(ui_game_s *ui)
{
    destroy_object(ui->map);
    sfRectangleShape_destroy(ui->life);
    sfRectangleShape_destroy(ui->credits);
    sfRectangleShape_destroy(ui->xp);
}