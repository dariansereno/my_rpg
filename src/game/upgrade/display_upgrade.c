/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** display_upgrade
*/

#include "my_rpg.h"

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
    sfRenderWindow_drawText(g->window->window, g->ressources[0].text, NULL);
    sfSprite_setScale(g->upgrade->upgrade_icon[0]->sprite, (sfVector2f){1.5, 1.5});
    sfSprite_setPosition(g->upgrade->upgrade_icon[0]->sprite, (sfVector2f)
    {g->ship->viewrect.left + 100, g->ship->viewrect.top + 965});
    sfRenderWindow_drawSprite(g->window->window, g->upgrade->upgrade_icon[0]->
    sprite, NULL);
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
    sfRenderWindow_drawText(g->window->window, g->ressources[0].text, NULL);
    sfSprite_setScale(g->upgrade->upgrade_icon[1]->sprite, (sfVector2f){1.5, 1.5});
    sfSprite_setPosition(g->upgrade->upgrade_icon[1]->sprite, (sfVector2f)
    {g->ship->viewrect.left + 100, g->ship->viewrect.top + 965 - 177});
    sfRenderWindow_drawSprite(g->window->window, g->upgrade->upgrade_icon[1]->
    sprite, NULL);
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
    sfRenderWindow_drawText(g->window->window, g->ressources[0].text, NULL);
    sfSprite_setScale(g->upgrade->upgrade_icon[2]->sprite, (sfVector2f){0.8, 0.8});
    sfSprite_setPosition(g->upgrade->upgrade_icon[2]->sprite, (sfVector2f)
    {g->ship->viewrect.left + 100, g->ship->viewrect.top + 965 - (177 * 2)});
    sfRenderWindow_drawSprite(g->window->window, g->upgrade->upgrade_icon[2]->
    sprite, NULL);
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
    sfRenderWindow_drawText(g->window->window, g->ressources[0].text, NULL);
    sfSprite_setScale(g->upgrade->upgrade_icon[3]->sprite, (sfVector2f){0.8, 0.8});
    sfSprite_setPosition(g->upgrade->upgrade_icon[3]->sprite, (sfVector2f)
    {g->ship->viewrect.left + 100, g->ship->viewrect.top + 965 - (177 * 3)});
    sfRenderWindow_drawSprite(g->window->window, g->upgrade->upgrade_icon[3]->
    sprite, NULL);
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