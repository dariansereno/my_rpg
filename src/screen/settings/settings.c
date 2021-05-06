/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** settings
*/

#include "my_rpg.h"

st_settings *generate_settings(void)
{
    st_settings *settings = my_malloc(sizeof(*settings));

    settings->background = generate_object((sfVector2f){651, 141}, \
    (sfIntRect){0, 0, 615, 569}, "contents/ui/settings/texts.png");
    settings->cancel = generate_object((sfVector2f){815, 921}, \
    (sfIntRect){0, 0, 141, 102}, "contents/ui/settings/cancel.png");
    settings->save = generate_object((sfVector2f){989, 920}, \
    (sfIntRect){0, 0, 141, 103}, "contents/ui/settings/save.png");
    settings->cross = generate_object((sfVector2f){1263, 43}, \
    (sfIntRect){0, 0, 47, 61}, "contents/ui/settings/cross.png");
    settings->music = generate_object((sfVector2f){707, 517}, \
    (sfIntRect){0, 0, 506, 44}, "contents/ui/settings/top_bar.png");
    settings->sfx = generate_object((sfVector2f){707, 676}, \
    (sfIntRect){0, 0, 506, 44}, "contents/ui/settings/bottom_bar.png");
    settings->bounds[0] = (sfFloatRect){0, 0, 0, 0};
    settings->bounds[1] = (sfFloatRect){0, 0, 0, 0};
    settings->bounds[2] = (sfFloatRect){0, 0, 0, 0};
    return (settings);
}

void set_position_settings(st_global *g)
{
    sfSprite_setPosition(g->ui->settings->background->sprite, \
    (sfVector2f){g->ui->settings->background->pos.x + g->ship->viewrect.left, \
    g->ui->settings->background->pos.y + g->ship->viewrect.top});
    sfSprite_setPosition(g->ui->settings->cancel->sprite, \
    (sfVector2f){g->ui->settings->cancel->pos.x + g->ship->viewrect.left, \
    g->ui->settings->cancel->pos.y + g->ship->viewrect.top});
    sfSprite_setPosition(g->ui->settings->save->sprite, \
    (sfVector2f){g->ui->settings->save->pos.x + g->ship->viewrect.left, \
    g->ui->settings->save->pos.y + g->ship->viewrect.top});
    sfSprite_setPosition(g->ui->settings->cross->sprite, \
    (sfVector2f){g->ui->settings->cross->pos.x + g->ship->viewrect.left, \
    g->ui->settings->cross->pos.y + g->ship->viewrect.top});
    sfSprite_setPosition(g->ui->settings->music->sprite, \
    (sfVector2f){g->ui->settings->music->pos.x + g->ship->viewrect.left, \
    g->ui->settings->music->pos.y + g->ship->viewrect.top});
    sfSprite_setPosition(g->ui->settings->sfx->sprite, \
    (sfVector2f){g->ui->settings->sfx->pos.x + g->ship->viewrect.left, \
    g->ui->settings->sfx->pos.y + g->ship->viewrect.top});
}

void parallax_settings(st_global *g)
{
    sfSprite_setTexture(g->paralax->nebula, g->paralax->nebulat, sfTrue);
    sfSprite_setTexture(g->paralax->star, g->paralax->start, sfTrue);
    sfSprite_setTextureRect(g->paralax->star, g->paralax->starr);
    sfSprite_setTextureRect(g->paralax->nebula, g->paralax->paralaxr);
    sfSprite_setPosition(g->paralax->nebula, g->paralax->nebulapos);
    sfSprite_setPosition(g->paralax->star, g->paralax->starpos);
    sfRenderWindow_drawSprite(g->window->window, g->paralax->nebula, NULL);
    sfRenderWindow_drawSprite(g->window->window, g->paralax->star, NULL);
    move_up(g);
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->settings->background->sprite, NULL);
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->settings->cancel->sprite, NULL);
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->settings->save->sprite, NULL);
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->settings->cross->sprite, NULL);
}

void screen_settings(st_global *g)
{
    events_settings(g);
    set_position_settings(g);
    parallax_settings(g);
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->settings->music->sprite, NULL);
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->settings->sfx->sprite, NULL);
    sfSprite_setPosition(g->ui->menu->cursor->sprite, \
    (sfVector2f){sfMouse_getPositionRenderWindow(g->window->window).x + 560 + \
    g->ship->viewrect.left, sfMouse_getPositionRenderWindow(g->window->window).y
    + g->ship->viewrect.top});
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->menu->cursor->sprite, NULL);
    sfRenderWindow_display(g->window->window);
}

void destroy_settings(st_settings *settings)
{
    destroy_object(settings->background);
    destroy_object(settings->cancel);
    destroy_object(settings->save);
    destroy_object(settings->cross);
    destroy_object(settings->music);
    destroy_object(settings->sfx);
}