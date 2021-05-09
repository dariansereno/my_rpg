/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** settings
*/

#include "my_rpg.h"

void more_settings_event(st_global *g, int i)
{
    if (i == 0)
        g->ui->settings->cancel->rect.left = 0;
    else if (i == 1)
        g->ui->settings->save->rect.left = 0;
}

void more_button_pressed_event(st_global *g, int i)
{
    if (i == 0)
        g->ui->settings->cancel->rect.left = 141;
    else if (i == 1)
        g->ui->settings->save->rect.left = 141;
}