/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** events_end
*/

#include "my_rpg.h"

void end_rect_left(st_global *g)
{
    if (g->window->event.type == sfEvtKeyPressed && \
    g->window->event.key.code == sfKeyLeft)
            g->ui->end->pressed = true;
    if (g->window->event.type == sfEvtKeyReleased && \
    g->window->event.key.code == sfKeyLeft) {
        end_rect_left_2(g);
    }
}
void end_rect_right(st_global *g)
{
    if (g->window->event.type == sfEvtKeyPressed && \
    g->window->event.key.code == sfKeyRight)
        g->ui->end->pressed = true;
    if (g->window->event.type == sfEvtKeyReleased && \
    g->window->event.key.code == sfKeyRight) {
        end_rect_right_2(g);
    }
}

void position_bg_end(st_global *g)
{
    sfSprite_setPosition(g->ui->end->ui[0]->sprite, (sfVector2f)
    {sfSprite_getPosition(g->ui->end->ui[0]->sprite).x +\
    g->ship->viewrect.left, \
    sfSprite_getPosition(g->ui->end->ui[0]->sprite).y + \
    g->ship->viewrect.top});
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->end->ui[0]->sprite, \
    NULL);
    sfSprite_setPosition(g->ui->end->ui[3]->sprite, (sfVector2f)
    {sfSprite_getPosition(g->ui->end->ui[3]->sprite).x +\
    g->ship->viewrect.left, \
    sfSprite_getPosition(g->ui->end->ui[3]->sprite).y + \
    g->ship->viewrect.top});
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->end->ui[3]->sprite, \
    NULL);
}

void rect_position_end(st_global *g)
{
    switch (g->ui->end->pos_rect) {
        case 1:
            sfSprite_setPosition(g->ui->end->ui[3]->sprite, \
            (sfVector2f){596, 675});
            break;
        case 2:
            sfSprite_setPosition(g->ui->end->ui[3]->sprite, \
            (sfVector2f){1024, 675});
            break;
        default:
            break;
    }
}

void text_position_end(st_global *g)
{
    sfText_setCharacterSize(g->ui->pause->text, 45);
    sfText_setColor(g->ui->pause->text, sfColor_fromRGB(179, 130, 188));
    sfText_setString(g->ui->pause->text, "quit game");
    sfText_setPosition(g->ui->pause->text, \
    (sfVector2f){g->ship->viewrect.left + 634, g->ship->viewrect.top + 678});
    sfRenderWindow_drawText(g->window->window, g->ui->pause->text, NULL);
    sfText_setString(g->ui->pause->text, "main menu");
    sfText_setPosition(g->ui->pause->text, \
    (sfVector2f){g->ship->viewrect.left + 1077, g->ship->viewrect.top + 678});
    sfRenderWindow_drawText(g->window->window, g->ui->pause->text, NULL);
}