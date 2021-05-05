/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** generate_module_card
*/

#include "my_rpg.h"

module_card_s *generate_module_card(void)
{
    module_card_s *module_card = my_malloc(sizeof(*module_card));

    module_card->font = sfFont_createFromFile("contents/fonts/myfont.otf");
    module_card->text = sfText_create();
    module_card->ui[0] = generate_object((sfVector2f){1192, 497}, \
    (sfIntRect){0, 0, 54, 40}, "contents/ui/module/tick.png");
    module_card->ui[1] = generate_object((sfVector2f){395, 469}, \
    (sfIntRect){0, 0, 700, 97}, "contents/ui/module/rect.png");
    module_card->ui[2] = generate_object((sfVector2f){312, 167}, \
    (sfIntRect){0, 0, 1296, 747}, "contents/ui/module/bg.png");
    module_card->ui[3] = generate_object((sfVector2f){1339, 724}, \
    (sfIntRect){0, 0, 193, 103}, "contents/ui/module/buy_not.png");
    module_card->existing = false;
    module_card->pressed = false;
    module_card->buy = false;
    module_card->mod_mul = 1.5;
    module_card->pos_rect = 1;
    sfText_setFont(module_card->text, module_card->font);
    sfText_setPosition(module_card->text, (sfVector2f){0, 0});
    return (module_card);
}

void destroy_module_card(module_card_s *module_card)
{
    for (int i = 0; i < 4; i++)
        destroy_object(module_card->ui[i]);
    sfFont_destroy(module_card->font);
    sfText_destroy(module_card->text);
}