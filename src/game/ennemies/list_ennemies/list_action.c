/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** linked list main actions
*/

#include "my_rpg.h"

void push_back_copy_node(list_ennemies node, st_ennemies ennemies)
{
    node->ennemies.pos = ennemies.pos;
    node->ennemies.spawn_pos = ennemies.pos;
    node->ennemies.rect = ennemies.rect;
    node->ennemies.sprite = ennemies.sprite;
    node->ennemies.life = 50;
    node->ennemies.dir = 0;
}

void push_back_ennemies(list_ennemies *li, st_ennemies ennemies)
{
    list_ennemies node = my_malloc(sizeof(*node));
    list_ennemies lastnode = *li;

    push_back_copy_node(node, ennemies);
    node->shootcl = my_malloc(sizeof(*node->shootcl));
    node->shootcl->clock = sfClock_create();
    node->li_shoot = NULL;
    node->index = 0;
    node->index = size_list_ennemies(*li);
    node->timer = my_malloc(sizeof(*node->timer));
    node->timer->clock = sfClock_create();
    node->ennemies.path_table = my_malloc(sizeof(float) * 8);
    node->next = NULL;
    if (*li == NULL)
        *li = node;
    else {
        while (lastnode->next != NULL)
            lastnode = lastnode->next;
        lastnode->next = node;
    }
}

void reindex_ennemies(list_ennemies *list)
{
    list_ennemies temp = *list;

    for (int i = 0; temp != NULL; i++) {
        temp->index = i;
        temp = temp->next;
    }
    return ;
}

void move_ennemies(list_ennemies li, st_global *ad, st_planet pl)
{
    if (circle_contains(1200, (sfVector2f){(float)pl.pos.x,
    (float)pl.pos.y},
    li->ennemies.pos) && circle_contains(1200, (sfVector2f){(float)pl.pos.x,
    (float)pl.pos.y}, ad->ship->bshippos)) {
        clock_move_ennemies(li, ad);
        if (li->shootcl->seconds > 1) {
            sfSound_play(ad->window->sfx->shoot);
            push_back_timer(&li->li_shoot, li->ennemies.pos,
            li->ennemies.dir);
            sfClock_restart(li->shootcl->clock);
        }
    print_list_shoot_enn(&li->li_shoot, ad->shoot->sprite_enn, ad);
    } else
        clock_move_ennemies_to_base(li, ad);
}

void print_ennemies_list(list_ennemies li, sfRenderWindow *window,
st_global *ad, st_planet pl)
{
    while (li != NULL) {
        li->shootcl->time = sfClock_getElapsedTime(li->shootcl->clock);
        li->shootcl->seconds = li->shootcl->time.microseconds / 1000000.0;
        move_ennemies(li, ad, pl);
        sfSprite_setTextureRect(li->ennemies.sprite, li->ennemies.rect);
        sfSprite_setPosition(li->ennemies.sprite,
        (sfVector2f){(float)li->ennemies.pos.x, (float)li->ennemies.pos.y});
        sfSprite_setOrigin(li->ennemies.sprite, (sfVector2f){24, 24});
        sfRenderWindow_drawSprite(window, li->ennemies.sprite, NULL);
        li = li->next;
    }
}