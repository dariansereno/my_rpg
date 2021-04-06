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

    planet_card->existing = sfFalse;
    planet_card->displaying = sfFalse;
    planet_card->closing = sfFalse;
    return (planet_card);
}


void create_planet_card(st_global *g, sfVector2f position_view)
{
    g->ui->planet_card = my_malloc(sizeof(*g->ui->planet_card));

    g->ui->planet_card->existing = sfTrue;
    g->ui->planet_card->displaying = sfTrue;
    g->ui->planet_card->mockup_s = sfSprite_create();
    g->ui->planet_card->planet_s = sfSprite_create();
    g->ui->planet_card->mockup_t = sfTexture_createFromFile("contents/UI/mockups/mockup-planet-card.png", NULL);
    sfSprite_setTexture(g->ui->planet_card->mockup_s, g->ui->planet_card->mockup_t, sfTrue);
    sfSprite_setPosition(g->ui->planet_card->mockup_s, position_view);
}