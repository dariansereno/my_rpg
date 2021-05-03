/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** linked list main actions
*/

#include "my_rpg.h"

void push_back_ennemies(list_ennemies *li, st_ennemies ennemies)
{
    list_ennemies node = malloc(sizeof(*node));
    list_ennemies lastnode = *li;

    node->ennemies.pos = ennemies.pos;
    node->ennemies.spawn_pos = ennemies.pos;
    node->ennemies.rect = ennemies.rect;
    node->ennemies.sprite = ennemies.sprite;
    node->ennemies.life = 50;
    node->ennemies.dir = 0;
    node->shootcl = malloc(sizeof(*node->shootcl));
    node->shootcl->clock = sfClock_create();
    node->li_shoot = NULL;
    node->index = 0;
    node->index = size_list_ennemies(*li);
    node->timer = malloc(sizeof(*node->timer));
    node->timer->clock = sfClock_create();
    node->ennemies.path_table = malloc(sizeof(float) * 8);
    node->next = NULL;
    if (*li == NULL)
        *li = node;
    else {
        while (lastnode->next != NULL)
            lastnode = lastnode->next;
        lastnode->next = node;
    }
}

void pop_position_ennemies(list_ennemies *list, int index)
{
    list_ennemies temp = *list;
    list_ennemies next = NULL;
    int i = 0;

    if (*list == NULL)
        return;
    if (index == 0) {
        (*list) = temp->next;
        free(temp);
        return ;
    }
    for (int i = 0; temp != NULL && temp->next->index != index; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    next = temp->next->next;
    free(temp->next);
    temp->next = next;
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

int size_list_ennemies(list_ennemies li)
{
    list_ennemies node = li;
    int i = 0;
    
    if (node == NULL)
        return (0);

    for (; node != NULL; ++i){
        node = node->next;}
    return (i);
}

void print_ennemies_list(list_ennemies li, sfRenderWindow *window, st_global *ad,
st_planet pl)
{
    while (li != NULL){
        li->shootcl->time = sfClock_getElapsedTime(li->shootcl->clock);
        li->shootcl->seconds = li->shootcl->time.microseconds / 1000000.0;
        if (circle_contains(1200, (sfVector2f){(float)pl.pos.x, (float)pl.pos.y},
        li->ennemies.pos) && circle_contains(1200, (sfVector2f){(float)pl.pos.x,
        (float)pl.pos.y}, ad->ship->bshippos)) {
            clock_move_ennemies(li, ad);
            if (li->shootcl->seconds > 1) {
                push_back_timer(&li->li_shoot, li->ennemies.pos, li->ennemies.dir);
                reindex_timer(li);
                sfClock_restart(li->shootcl->clock);
            }
        print_list_shoot_enn(&li->li_shoot, ad->shoot->sprite_enn, ad);
        }
        else
            clock_move_ennemies_to_base(li, ad);
        sfSprite_setTextureRect(li->ennemies.sprite, li->ennemies.rect);
        sfSprite_setPosition(li->ennemies.sprite,
        (sfVector2f){(float)li->ennemies.pos.x, (float)li->ennemies.pos.y});
        sfSprite_setOrigin(li->ennemies.sprite, (sfVector2f){24, 24});
        sfRenderWindow_drawSprite(window, li->ennemies.sprite, NULL);
        li = li->next;
    }
}