/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** planet_card
*/

#include "my_rpg.h"

void display_planet_card(st_global *g)
{
    list_planet planets = NULL;

    if (g->ui->planet_card->existing == true) {
        planets = g->planets->planets;
        sfRenderWindow_drawSprite(g->window->window, \
        g->ui->planet_card->mockup_s, NULL);
        while (planets != NULL) {
            if (planets->interact == true) {
                sfSprite_setPosition(planets->planet.sprite, \
                (sfVector2f){g->ship->viewrect.left + 965, \
                g->ship->viewrect.top + 440});
                sfRenderWindow_drawSprite(g->window->window, \
                planets->planet.sprite, NULL);
            }
            planets = planets->next;
        }
        planet_card_display_sprite_text(g);
    }
}

void planet_card_display_sprite_text(st_global *g)
{
    sfRenderWindow_drawRectangleShape(g->window->window, \
    g->ui->planet_card->r_o_2, NULL);
    sfRenderWindow_drawRectangleShape(g->window->window, \
    g->ui->planet_card->r_h, NULL);
    sfRenderWindow_drawRectangleShape(g->window->window, \
    g->ui->planet_card->r_h_2_o, NULL);
    sfRenderWindow_drawRectangleShape(g->window->window, \
    g->ui->planet_card->r_co_2, NULL);
    sfRenderWindow_drawRectangleShape(g->window->window, \
    g->ui->planet_card->r_n, NULL);
    sfRenderWindow_drawRectangleShape(g->window->window, \
    g->ui->planet_card->r_n_2, NULL);
    text_draw_planet_card(g);
}

void text_draw_planet_card(st_global *g)
{
    sfRenderWindow_drawText(g->window->window, \
    g->ui->planet_card->t_o_2, NULL);
    sfRenderWindow_drawText(g->window->window, \
    g->ui->planet_card->t_h, NULL);
    sfRenderWindow_drawText(g->window->window, \
    g->ui->planet_card->t_h_2_o, NULL);
    sfRenderWindow_drawText(g->window->window, \
    g->ui->planet_card->t_co_2, NULL);
    sfRenderWindow_drawText(g->window->window, \
    g->ui->planet_card->t_n, NULL);
    sfRenderWindow_drawText(g->window->window, \
    g->ui->planet_card->t_n_2, NULL);
    sfRenderWindow_drawText(g->window->window, \
    g->ui->planet_card->t_temp, NULL);
    sfRenderWindow_drawText(g->window->window, \
    g->ui->planet_card->t_pres, NULL);
    sfRenderWindow_drawText(g->window->window, \
    g->ui->planet_card->title, NULL);
}