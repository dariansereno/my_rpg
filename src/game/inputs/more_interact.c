/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** interacting
*/

#include "my_rpg.h"

int interact_input6(st_global *ad)
{
    if (ad->window->event.type == sfEvtKeyPressed && \
        ad->window->event.key.code == sfKeyEscape) {
        if (ad->ui->pause->existing && ad->ui->trade_card->existing == false &&
        ad->ui->module_card->existing == false && \
        ad->ui->planet_card->existing == false && \
        ad->ui->pause_settings->existing == false) {
            ad->ui->pause->existing = false;
            return (1);
        }
        ad->ui->pause->existing = true;
    }
    return (0);
}

void interact_input7(st_global *ad, int counter)
{
    if (counter >= 3 && sfRectangleShape_getSize(ad->text->text_r3).x <= 0) {
        sfRectangleShape_setSize(ad->text->text_r1,
        (sfVector2f){1160, -40});
        sfRectangleShape_setSize(ad->text->text_r2,
        (sfVector2f){1160, -40});
        sfRectangleShape_setSize(ad->text->text_r3,
        (sfVector2f){1160, -40});
        ad->text->str = cpy_to_up_text(ad);
        sfText_setString(ad->text->text, ad->text->str);
    }
}