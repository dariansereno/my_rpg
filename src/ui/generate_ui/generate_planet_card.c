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
    return (planet_card);
}


planet_card_s *create_planet_card(st_global *g, sfVector2f position_view)
{
    planet_card_s *planet_card = my_malloc(sizeof(*planet_card));

    planet_card = my_malloc(sizeof(*planet_card));
    planet_card->existing = sfTrue;
    planet_card->mockup_s = sfSprite_create();
    planet_card->planet_s = sfSprite_create();
    planet_card->mockup_t = sfTexture_createFromFile("contents/UI/mockups/mockup_card.jpg", NULL);
    sfSprite_setTexture(planet_card->mockup_s, planet_card->mockup_t, sfTrue);
    sfSprite_setPosition(planet_card->mockup_s, position_view);
    return (planet_card);
}