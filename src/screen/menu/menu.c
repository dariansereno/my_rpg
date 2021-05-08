/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** menu
*/

#include "my_rpg.h"

void generate_arw(st_menu *menu)
{
    sfTexture *arw_r_tex = sfTexture_createFromFile(
        "contents/ui/buttons/arw_right.png", NULL);
    sfTexture *arw_l_tex = sfTexture_createFromFile(
        "contents/ui/buttons/arw_left.png", NULL);

    menu->arw_right = sfSprite_create();
    sfSprite_setTexture(menu->arw_right, arw_r_tex, sfTrue);
    sfSprite_setScale(menu->arw_right, (sfVector2f){0.025, 0.025});
    menu->arw_left = sfSprite_create();
    sfSprite_setTexture(menu->arw_left, arw_l_tex, sfTrue);
    sfSprite_setScale(menu->arw_left, (sfVector2f){0.025, 0.025});
}

st_menu *generate_menu(void)
{
    st_menu *menu = my_malloc(sizeof(*menu));

    menu->cursor = generate_object((sfVector2f){0, 0}, \
    (sfIntRect){0, 0, 37, 51}, "contents/ui/textures/cursor.png");
    menu->items[0] = generate_object((sfVector2f){1257, 37}, \
    (sfIntRect){0, 0, 59, 67}, "contents/ui/menu/cross.png");
    menu->items[1] = generate_object((sfVector2f){888, 943}, \
    (sfIntRect){0, 0, 135, 103}, "contents/ui/menu/settings.png");
    menu->items[2] = generate_object((sfVector2f){761, 775}, \
    (sfIntRect){0, 0, 398, 150}, "contents/ui/menu/start_btn.png");
    menu->items[3] = generate_object((sfVector2f){721, 171}, \
    (sfIntRect){0, 0, 467, 177}, "contents/ui/menu/spaceciv.png");
    menu->view = sfView_createFromRect((sfFloatRect){560, 0, 800, HEIGHT});
    menu->bounds[0] = (sfFloatRect){0, 0, 0, 0};
    menu->bounds[1] = (sfFloatRect){0, 0, 0, 0};
    menu->bounds[2] = (sfFloatRect){0, 0, 0, 0};
    menu->menu = 0;
    generate_arw(menu);
    return (menu);
}

void parallax_menu(st_global *g)
{
    sfSprite_setTexture(g->ship->bship, g->ship->bshipt, sfTrue);
    sfSprite_setTexture(g->paralax->nebula, g->paralax->nebulat, sfTrue);
    sfSprite_setTexture(g->paralax->star, g->paralax->start, sfTrue);
    sfSprite_setTextureRect(g->paralax->star, g->paralax->starr);
    sfSprite_setTextureRect(g->paralax->nebula, g->paralax->paralaxr);
    sfSprite_setPosition(g->ship->bship, g->ship->bshippos);
    sfSprite_setPosition(g->paralax->nebula, g->paralax->nebulapos);
    sfSprite_setPosition(g->paralax->star, g->paralax->starpos);
    sfSprite_setPosition(g->ui->menu->arw_left, (sfVector2f){g->ship->viewrect.left + 837, g->ship->viewrect.top + 530});
    sfSprite_setPosition(g->ui->menu->arw_right, (sfVector2f){g->ship->viewrect.left + 1073, g->ship->viewrect.top + 530});
    sfRenderWindow_drawSprite(g->window->window, g->paralax->nebula, NULL);
    sfRenderWindow_drawSprite(g->window->window, g->paralax->star, NULL);
    sfRenderWindow_drawSprite(g->window->window, g->ship->bship, NULL);
    sfRenderWindow_drawSprite(g->window->window, g->ui->menu->arw_left, NULL);
    sfRenderWindow_drawSprite(g->window->window, g->ui->menu->arw_right, NULL);
    move_up(g);
}

void items_menu(st_global *g)
{
    sfSprite_setPosition(g->ui->menu->items[0]->sprite, \
    (sfVector2f){g->ui->menu->items[0]->pos.x + g->ship->viewrect.left, \
    g->ui->menu->items[0]->pos.y + g->ship->viewrect.top});
    sfSprite_setPosition(g->ui->menu->items[1]->sprite, \
    (sfVector2f){g->ui->menu->items[1]->pos.x + g->ship->viewrect.left, \
    g->ui->menu->items[1]->pos.y + g->ship->viewrect.top});
    sfSprite_setPosition(g->ui->menu->items[2]->sprite, \
    (sfVector2f){g->ui->menu->items[2]->pos.x + g->ship->viewrect.left, \
    g->ui->menu->items[2]->pos.y + g->ship->viewrect.top});
    sfSprite_setPosition(g->ui->menu->items[3]->sprite, \
    (sfVector2f){g->ui->menu->items[3]->pos.x + g->ship->viewrect.left, \
    g->ui->menu->items[3]->pos.y + g->ship->viewrect.top});
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->menu->items[0]->sprite, NULL);
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->menu->items[1]->sprite, NULL);
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->menu->items[2]->sprite, NULL);
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->menu->items[3]->sprite, NULL);
}

void init_ship_by_choosen(st_global *ad)
{
    sfTexture_destroy(ad->texture->load);
    ad->texture->load = sfTexture_createFromFile
    (ad->ship->path[ad->ship->ship_choosen], NULL);
    sfTexture_destroy(ad->texture->th);
    ad->texture->th = sfTexture_createFromFile
    (ad->ship->path_t[ad->ship->ship_choosen], NULL);
    ad->ship->bshipt = sfTexture_createFromFile(ad->ship->path
    [ad->ship->ship_choosen], NULL);

    sfSprite_setTexture(ad->ship->bship, ad->texture->load, sfTrue);
}

void screen_menu(st_global *g)
{
    sfRenderWindow_clear(g->window->window, sfBlue);
    sfRenderWindow_setView(g->window->window, g->ui->menu->view);
    init_ship_by_choosen(g);
    parallax_menu(g);
    items_menu(g);
    events_menu(g);
    sfSprite_setPosition(g->ui->menu->cursor->sprite, \
    (sfVector2f){sfMouse_getPositionRenderWindow(g->window->window).x + 560 + \
    g->ship->viewrect.left, sfMouse_getPositionRenderWindow(g->window->window).y
    + g->ship->viewrect.top});
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->menu->cursor->sprite, NULL);
    sfRenderWindow_display(g->window->window);
}

void destroy_menu(st_menu *menu)
{
    destroy_object(menu->cursor);
    destroy_object(menu->items[0]);
    destroy_object(menu->items[1]);
    destroy_object(menu->items[2]);
    destroy_object(menu->items[3]);
    sfView_destroy(menu->view);
}