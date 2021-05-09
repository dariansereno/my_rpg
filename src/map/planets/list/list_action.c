/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** linked list main actions
*/

#include "my_rpg.h"

void set_texture_planets(list_planet *li, st_planet_global *g)
{
    list_planet node = malloc(sizeof(*node));
    node = *li;

    while (node != NULL) {
        node->planet.sprite = sfSprite_create();
        sfSprite_setTexture(node->planet.sprite,
        g->textures[node->planet.type], sfTrue);
        sfSprite_setPosition(node->planet.sprite,
        (sfVector2f){(float)node->planet.pos.x, (float)node->planet.pos.y});
        sfSprite_setScale(node->planet.sprite, (sfVector2f){5, 5});
        sfSprite_setOrigin(node->planet.sprite, (sfVector2f){24, 24});
        if (node->planet.type < 7)
            sfSprite_setOrigin(node->planet.sprite, (sfVector2f){32, 32});
        node = node->next;
    }
}

void pop_position_planet(list_planet *list, sfVector2f pos)
{
    list_planet temp = *list;
    list_planet next = NULL;

    if (*list == NULL)
        return;
    for (; temp != NULL && temp->next->planet.pos.x != pos.x &&
    temp->next->planet.pos.y != pos.y;)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int size_list_planet(list_planet li)
{
    list_planet node = li;
    int i = 0;

    for (; node != NULL; ++i){
        node = node->next;}
    return (i);
}

void print_planet_normal(list_planet li, sfRenderWindow *window, st_global *ad)
{
    if (li->size == 2) {
        sfSprite_setTextureRect(li->planet.sprite, li->planet.rect);
        sfSprite_setScale(li->planet.sprite, (sfVector2f){5, 5});
        sfSprite_setPosition(li->planet.sprite,
        (sfVector2f){(float)li->planet.pos.x, (float)li->planet.pos.y});
        sfRenderWindow_drawSprite(window, li->planet.sprite, NULL);
        if (li->planet.kind == TECH){
            print_ennemies_list(li->planet.ennemies, window, ad,
            li->planet);
        }
    }
}

void print_planet_list_normal(list_planet li, sfRenderWindow *window,
st_global *ad)
{
    while (li != NULL){
        if (li->on_screen == true)
            print_planet_normal(li, window, ad);
        li = li->next;
    }
}