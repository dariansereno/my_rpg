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

    ui->text = sfText_create();
    ui->font = sfFont_createFromFile("contents/fonts/myfont.otf");
    ui->life = sfRectangleShape_create();
    ui->credits = sfRectangleShape_create();
    ui->xp = sfRectangleShape_create();
    set_rectangle_ui_game_life(ui);
    ui->map = generate_object((sfVector2f){75, 41}, \
    (sfIntRect){0, 0, 183, 183}, "contents/ui/ui/map.png");
    ui->craft[0] = generate_object((sfVector2f){1685, 0}, \
    (sfIntRect){0, 0, 235, 167}, "contents/ui/ui/craft.png");
    ui->craft[1] = generate_object((sfVector2f){1758, 123}, \
    (sfIntRect){0, 0, 89, 29}, "contents/ui/ui/rect.png");
    ui->item = generate_object((sfVector2f){751, 944}, \
    (sfIntRect){0, 0, 552, 136}, "contents/ui/ui/inventory.png");
    sfText_setFont(ui->text, ui->font);
    return (ui);
}

void set_rectangle_ui_game_life(ui_game_s *ui)
{
    ui->life_outline = sfRectangleShape_create();
    ui->credits_outline = sfRectangleShape_create();
    ui->xp_outline = sfRectangleShape_create();
    sfRectangleShape_setSize(ui->life, (sfVector2f){263, 10});
    sfRectangleShape_setFillColor(ui->life, sfColor_fromRGB(237, 28, 36));
    sfRectangleShape_setOutlineColor(ui->life, sfColor_fromRGB(179, 130, 188));
    sfRectangleShape_setPosition(ui->life, (sfVector2f){217, 63});
    sfRectangleShape_setSize(ui->life_outline, (sfVector2f){263, 10});
    sfRectangleShape_setFillColor(ui->life_outline, \
    sfColor_fromRGBA(0, 0, 0, 1));
    sfRectangleShape_setOutlineColor(ui->life_outline, \
    sfColor_fromRGB(179, 130, 188));
    sfRectangleShape_setOutlineThickness(ui->life_outline, 6);
    sfRectangleShape_setPosition(ui->life_outline, (sfVector2f){217, 63});
    set_rectangle_ui_game_credits(ui);
    set_rectangle_ui_game_xp(ui);
}

void set_rectangle_ui_game_credits(ui_game_s *ui)
{
    sfRectangleShape_setSize(ui->credits, (sfVector2f){263, 10});
    sfRectangleShape_setFillColor(ui->credits, sfColor_fromRGB(255, 242, 0));
    sfRectangleShape_setPosition(ui->credits, (sfVector2f){217, 77});
    sfRectangleShape_setSize(ui->credits_outline, (sfVector2f){263, 10});
    sfRectangleShape_setFillColor(ui->credits_outline, \
    sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_setOutlineColor(ui->credits_outline, \
    sfColor_fromRGB(179, 130, 188));
    sfRectangleShape_setOutlineThickness(ui->credits_outline, 6);
    sfRectangleShape_setPosition(ui->credits_outline, (sfVector2f){217, 77});
}

void set_rectangle_ui_game_xp(ui_game_s *ui)
{
    sfRectangleShape_setSize(ui->xp, (sfVector2f){263, 10});
    sfRectangleShape_setFillColor(ui->xp, sfColor_fromRGB(0, 255, 255));
    sfRectangleShape_setPosition(ui->xp, (sfVector2f){217, 91});
    sfRectangleShape_setSize(ui->xp_outline, (sfVector2f){263, 10});
    sfRectangleShape_setFillColor(ui->xp_outline, sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_setOutlineColor(ui->xp_outline, \
    sfColor_fromRGB(179, 130, 188));
    sfRectangleShape_setOutlineThickness(ui->xp_outline, 6);
    sfRectangleShape_setPosition(ui->xp_outline, (sfVector2f){217, 91});
}

void destroy_ui_game(ui_game_s *ui)
{
    destroy_object(ui->map);
    destroy_object(ui->craft[0]);
    destroy_object(ui->craft[1]);
    destroy_object(ui->item);
    sfText_destroy(ui->text);
    sfFont_destroy(ui->font);
    sfRectangleShape_destroy(ui->life);
    sfRectangleShape_destroy(ui->credits);
    sfRectangleShape_destroy(ui->xp);
    sfRectangleShape_destroy(ui->life_outline);
    sfRectangleShape_destroy(ui->credits_outline);
    sfRectangleShape_destroy(ui->xp_outline);
}