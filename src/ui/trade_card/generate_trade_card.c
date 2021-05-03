/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** generate_trade_card
*/

#include "my_rpg.h"

trade_card_s *generate_trade_card(void)
{
    trade_card_s *trade_card = my_malloc(sizeof(*trade_card));

    trade_card->font = sfFont_createFromFile("contents/fonts/myfont.otf");
    trade_card->text = sfText_create();
    trade_card->ui[0] = generate_object((sfVector2f){1422, 548}, \
    (sfIntRect){0, 0, 110, 110}, "contents/UI/trade/empty_arrow_up.png");
    trade_card->ui[1] = generate_object((sfVector2f){1422, 548}, \
    (sfIntRect){0, 0, 110, 110}, "contents/UI/trade/filled_arrow_up.png");
    trade_card->ui[2] = generate_object((sfVector2f){1422, 720}, \
    (sfIntRect){0, 0, 110, 110}, "contents/UI/trade/empty_arrow_down.png");
    trade_card->ui[3] = generate_object((sfVector2f){1422, 720}, \
    (sfIntRect){0, 0, 110, 110}, "contents/UI/trade/filled_arrow_down.png");
    trade_card->ui[4] = generate_object((sfVector2f){388, 634}, \
    (sfIntRect){0, 0, 712, 110}, "contents/UI/trade/rect_trade.png");
    trade_card->ui[5] = generate_object((sfVector2f){0, 0}, \
    (sfIntRect){0, 0, 1296, 747}, "contents/UI/trade/trade-mockup.png");
    sfText_setFont(trade_card->text, trade_card->font);
    sfText_setPosition(trade_card->text, (sfVector2f){0, 0});
    trade_card = generate_trade_card_bools(trade_card);
    return (trade_card);
}

trade_card_s *generate_trade_card_bools(trade_card_s *trade_card)
{
    trade_card->pos_rect = 0;
    trade_card->first_cell = 1;
    trade_card->counter = 0;
    trade_card->existing = false;
    trade_card->pressed = false;
    return (trade_card);
}

void destroy_trade_card(trade_card_s *trade_card)
{
    for (int i = 0; i < 6; i++)
        destroy_object(trade_card->ui[i]);
    sfFont_destroy(trade_card->font);
    sfText_destroy(trade_card->text);
}