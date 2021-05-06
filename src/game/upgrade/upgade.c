/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** upgade
*/

#include "my_rpg.h"

int *generate_tab_upgrade()
{
    int *tab = my_malloc(sizeof(int) * 4);

    for (int i = 0; i < 4; i++) {
        tab[i] = 0;
    }
    return (tab);
}

st_upgrade *generate_upgrade()
{
    st_upgrade *upgrade = my_malloc(sizeof(st_upgrade *));

    upgrade->upgrade_tab = generate_tab_upgrade();
    upgrade->can_upgrade = true;
    return (upgrade);
}

void print_upgrade_fire_damage(st_global *g)
{
    sfSprite_setPosition(g->ui->ui->upgrade->sprite, (sfVector2f){ \
    g->ship->viewrect.left + 10, g->ship->viewrect.top + 1080 - 177});
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->ui->upgrade->sprite, NULL);
    sfText_setString(g->ressources[0].text, "press r");
    sfText_setPosition(g->ressources[0].text, (sfVector2f)
    {g->ship->viewrect.left + 90, g->ship->viewrect.top + 1025});
    sfText_setCharacterSize(g->ressources[0].text, 23);
    sfRenderWindow_drawText(g->window->window, g->ressources[0].text,
    NULL);
}

void print_upgrade_fire_speed(st_global *g)
{
    sfSprite_setPosition(g->ui->ui->upgrade->sprite, (sfVector2f){ \
    g->ship->viewrect.left + 10, g->ship->viewrect.top + 1080 - (177 * 2)});
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->ui->upgrade->sprite, NULL);
    sfText_setString(g->ressources[0].text, "press t");
    sfText_setPosition(g->ressources[0].text, (sfVector2f)
    {g->ship->viewrect.left + 90, g->ship->viewrect.top + 1025 - (177)});
    sfText_setCharacterSize(g->ressources[0].text, 23);
    sfRenderWindow_drawText(g->window->window, g->ressources[0].text,
    NULL);
}

void print_upgrade_speed(st_global *g)
{
    sfSprite_setPosition(g->ui->ui->upgrade->sprite, (sfVector2f){ \
    g->ship->viewrect.left + 10, g->ship->viewrect.top + 1080 - (177 * 3)});
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->ui->upgrade->sprite, NULL);
    sfText_setString(g->ressources[0].text, "press y");
    sfText_setPosition(g->ressources[0].text, (sfVector2f)
    {g->ship->viewrect.left + 90, g->ship->viewrect.top + 1025 - (177 * 2)});
    sfText_setCharacterSize(g->ressources[0].text, 23);
    sfRenderWindow_drawText(g->window->window, g->ressources[0].text,
    NULL);
}

void print_upgrade_health(st_global *g)
{
    sfSprite_setPosition(g->ui->ui->upgrade->sprite, (sfVector2f){ \
    g->ship->viewrect.left + 10, g->ship->viewrect.top + 1080 - (177 * 4)});
    sfRenderWindow_drawSprite(g->window->window, \
    g->ui->ui->upgrade->sprite, NULL);
    sfText_setString(g->ressources[0].text, "press u");
    sfText_setPosition(g->ressources[0].text, (sfVector2f)
    {g->ship->viewrect.left + 90, g->ship->viewrect.top + 1025 - (177 * 3)});
    sfText_setCharacterSize(g->ressources[0].text, 23);
    sfRenderWindow_drawText(g->window->window, g->ressources[0].text,
    NULL);
}

void display_upgrade(st_global *ad)
{
    if (ad->upgrade->can_upgrade) {
        print_upgrade_fire_damage(ad);
        print_upgrade_fire_speed(ad);
        print_upgrade_health(ad);
        print_upgrade_speed(ad);   
    }
}