/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** linked list main actions
*/

#include "my_rpg.h"

void push_back_planet(list_planet *li, st_planet planet)
{
    list_planet node = malloc(sizeof(*node));
    list_planet lastnode = *li;

    node->planet = planet;
    node->size = random_piped();
    node->timer.clock = sfClock_create();
    node->move.clock = sfClock_create();
    node->spawning.clock = sfClock_create();
    node->direction = random_between(0, 7);
    node->index = size_list_planet(*li);
    node->ennemies_spawn = random_between(10, 25);
    node->sc = random_between(9, 13);
    node->can_interact = false;
    node->next = NULL;
    if (*li == NULL)
        *li = node;
    else {
        while (lastnode->next != NULL)
            lastnode = lastnode->next;
        lastnode->next = node;
    }
}

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

void print_planet_big(list_planet li, sfRenderWindow *window, st_global *ad)
{
    if (li->size == 3) {
        sfSprite_setTextureRect(li->planet.sprite, li->planet.rect);
        sfSprite_setScale(li->planet.sprite, (sfVector2f){li->sc, li->sc});
        sfSprite_setPosition(li->planet.sprite,
        (sfVector2f){(float)li->planet.pos.x, (float)li->planet.pos.y});
        sfRenderWindow_drawSprite(window, li->planet.sprite, NULL);
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

void print_planet_list_big(list_planet li, sfRenderWindow *window,
st_global *ad)
{
    while (li != NULL){
       if (li->on_screen == true)
           print_planet_normal(li, window, ad);
        li = li->next;
    }
}

void print_planet_lil(list_planet li, sfRenderWindow *window, st_global *ad)
{
    int rand = random_between(0, 1);

    if (li->size == 1 && rand) {
        sfSprite_setTextureRect(li->planet.sprite, li->planet.rect);
        sfSprite_setScale(li->planet.sprite, (sfVector2f){(float)li->sc / 10.0,
        (float)li->sc / 10.0});
        sfSprite_setPosition(li->planet.sprite,
        (sfVector2f){(float)li->planet.pos.x, (float)li->planet.pos.y});
        sfRenderWindow_drawSprite(window, li->planet.sprite, NULL);
    }
}

void print_planet_list_little(list_planet li, sfRenderWindow *window,
st_global *ad)
{
    while (li != NULL){
        if (li->on_screen == true)
            print_planet_lil(li, window, ad);
        li = li->next;
    }
}