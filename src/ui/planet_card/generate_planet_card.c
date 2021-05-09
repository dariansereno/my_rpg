/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** generate_planet_card
*/

#include "my_rpg.h"

planet_card_s *generate_planet_card(void)
{
    planet_card_s *planet_card = my_malloc(sizeof(*planet_card));

    planet_card->existing = false;
    return (planet_card);
}

void create_planet_card(st_global *g, sfVector2f position_view, \
list_planet planets)
{
    g->ui->planet_card = my_malloc(sizeof(*g->ui->planet_card));
    g->ui->planet_card->existing = true;
    g->ui->planet_card->mockup_s = sfSprite_create();
    g->ui->planet_card->mockup_t = \
    sfTexture_createFromFile("contents/ui/mockups/mockup-planet-card.png", \
    NULL);
    sfSprite_setTexture(g->ui->planet_card->mockup_s, \
    g->ui->planet_card->mockup_t, sfTrue);
    rectangle_shape_text_planet_card_creation(g);
    rectangle_shape_planet_card_set(g, planets);
    texts_planet_card_set(g);
    text_planet_card_set_string(g, planets);
    text_planet_card_position(g);
    sfSprite_setPosition(g->ui->planet_card->mockup_s, position_view);
}

void rectangle_shape_text_planet_card_creation(st_global *g)
{
    g->ui->planet_card->r_o_2 = sfRectangleShape_create();
    g->ui->planet_card->r_co_2 = sfRectangleShape_create();
    g->ui->planet_card->r_h = sfRectangleShape_create();
    g->ui->planet_card->r_h_2_o = sfRectangleShape_create();
    g->ui->planet_card->r_n = sfRectangleShape_create();
    g->ui->planet_card->r_n_2 = sfRectangleShape_create();
    g->ui->planet_card->font = \
    sfFont_createFromFile("contents/fonts/myfont.otf");
    g->ui->planet_card->t_o_2 = sfText_create();
    g->ui->planet_card->t_h = sfText_create();
    g->ui->planet_card->t_h_2_o = sfText_create();
    g->ui->planet_card->t_co_2 = sfText_create();
    g->ui->planet_card->t_n = sfText_create();
    g->ui->planet_card->t_n_2 = sfText_create();
    g->ui->planet_card->t_temp = sfText_create();
    g->ui->planet_card->t_pres = sfText_create();
    g->ui->planet_card->title = sfText_create();
}

void destroy_planet_card(planet_card_s *planet_card)
{
    planet_card->existing = false;
    sfSprite_destroy(planet_card->mockup_s);
    sfTexture_destroy(planet_card->mockup_t);
    sfRectangleShape_destroy(planet_card->r_o_2);
    sfRectangleShape_destroy(planet_card->r_h);
    sfRectangleShape_destroy(planet_card->r_h_2_o);
    sfRectangleShape_destroy(planet_card->r_co_2);
    sfRectangleShape_destroy(planet_card->r_n);
    sfRectangleShape_destroy(planet_card->r_n_2);
    sfFont_destroy(planet_card->font);
    sfText_destroy(planet_card->t_o_2);
    sfText_destroy(planet_card->t_h);
    sfText_destroy(planet_card->t_h_2_o);
    sfText_destroy(planet_card->t_co_2);
    sfText_destroy(planet_card->t_n);
    sfText_destroy(planet_card->t_n_2);
    sfText_destroy(planet_card->t_temp);
    sfText_destroy(planet_card->t_pres);
}