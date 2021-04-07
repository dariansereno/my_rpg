/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** planet_card_text
*/

#include "my_rpg.h"

void texts_planet_card_set(st_global *g)
{
    sfText_setCharacterSize(g->ui->planet_card->t_o_2, 39);
    sfText_setCharacterSize(g->ui->planet_card->t_h, 39);
    sfText_setCharacterSize(g->ui->planet_card->t_h_2_o, 39);
    sfText_setCharacterSize(g->ui->planet_card->t_co_2, 39);
    sfText_setCharacterSize(g->ui->planet_card->t_n, 39);
    sfText_setCharacterSize(g->ui->planet_card->t_n_2, 39);
    sfText_setCharacterSize(g->ui->planet_card->t_temp, 64);
    sfText_setCharacterSize(g->ui->planet_card->t_pres, 64);
    sfText_setCharacterSize(g->ui->planet_card->title, 60);
    sfText_setFont(g->ui->planet_card->t_o_2, g->ui->planet_card->font);
    sfText_setFont(g->ui->planet_card->t_h, g->ui->planet_card->font);
    sfText_setFont(g->ui->planet_card->t_h_2_o, g->ui->planet_card->font);
    sfText_setFont(g->ui->planet_card->t_co_2, g->ui->planet_card->font);
    sfText_setFont(g->ui->planet_card->t_n, g->ui->planet_card->font);
    sfText_setFont(g->ui->planet_card->t_n_2, g->ui->planet_card->font);
    sfText_setFont(g->ui->planet_card->t_temp, g->ui->planet_card->font);
    sfText_setFont(g->ui->planet_card->t_pres, g->ui->planet_card->font);
    sfText_setFont(g->ui->planet_card->title, g->ui->planet_card->font);
}

void text_planet_card_set_string(st_global *g, list_planet planets)
{
    sfText_setString(g->ui->planet_card->t_o_2, \
    int_to_str(planets->planet.stats.o));
    sfText_setString(g->ui->planet_card->t_h, \
    int_to_str(planets->planet.stats.h));
    sfText_setString(g->ui->planet_card->t_h_2_o, \
    int_to_str(planets->planet.stats.h2o));
    sfText_setString(g->ui->planet_card->t_co_2, \
    int_to_str(planets->planet.stats.co2));
    sfText_setString(g->ui->planet_card->t_n, \
    int_to_str(planets->planet.stats.N));
    sfText_setString(g->ui->planet_card->t_n_2, \
    int_to_str(planets->planet.stats.n2));
    text_planet_card_temperature(g, planets);
    sfText_setString(g->ui->planet_card->t_pres, \
    int_to_str(planets->planet.stats.pressure));
    sfText_setString(g->ui->planet_card->title, \
    create_planet_string(planets->index));
}

void text_planet_card_temperature(st_global *g, list_planet planets)
{
    switch (planets->planet.climate) {
        case 0:
            sfText_setString(g->ui->planet_card->t_temp, "ARDENT");
            break;
        case 1:
            sfText_setString(g->ui->planet_card->t_temp, "WARM");
            break;
        case 2:
            sfText_setString(g->ui->planet_card->t_temp, "NORMAL");
            break;
        case 3:
            sfText_setString(g->ui->planet_card->t_temp, "COLD");
            break;
        case 4:
            sfText_setString(g->ui->planet_card->t_temp, "FROSTEN");
            break;
    }
}

void text_planet_card_position(st_global *g)
{
    sfText_setPosition(g->ui->planet_card->t_o_2, \
    (sfVector2f){g->ship->viewrect.left + 680, g->ship->viewrect.top + 313});
    sfText_setPosition(g->ui->planet_card->t_h, \
    (sfVector2f){g->ship->viewrect.left + 680, g->ship->viewrect.top + 395});
    sfText_setPosition(g->ui->planet_card->t_h_2_o, \
    (sfVector2f){g->ship->viewrect.left + 680, g->ship->viewrect.top + 483});
    sfText_setPosition(g->ui->planet_card->t_co_2, \
    (sfVector2f){g->ship->viewrect.left + 680, g->ship->viewrect.top + 565});
    sfText_setPosition(g->ui->planet_card->t_n, \
    (sfVector2f){g->ship->viewrect.left + 680, g->ship->viewrect.top + 655});
    sfText_setPosition(g->ui->planet_card->t_n_2, \
    (sfVector2f){g->ship->viewrect.left + 680, g->ship->viewrect.top + 739});
    sfText_setPosition(g->ui->planet_card->t_temp, \
    (sfVector2f){g->ship->viewrect.left + 1035,g->ship->viewrect.top + 653});
    sfText_setPosition(g->ui->planet_card->t_pres, \
    (sfVector2f){g->ship->viewrect.left + 1035,g->ship->viewrect.top + 735});
    sfText_setPosition(g->ui->planet_card->title, \
    (sfVector2f){g->ship->viewrect.left + 810,g->ship->viewrect.top + 210});
}