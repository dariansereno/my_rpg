/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** linked list main actions
*/

#include "my_rpg.h"

void push_back_spaceobj(list_spaceobj *li, sfVector2i pos, int id)
{
    list_spaceobj node = malloc(sizeof(*node));
    list_spaceobj lastnode = *li;

    node->pos = (sfVector2f){(float)pos.x, (float)pos.y};
    node->sprite = sfSprite_create();
    node->timer = my_malloc(sizeof(*node->timer));
    node->id = id;
    node->next = NULL;
    if (*li == NULL)
        *li = node;
    else {
        while (lastnode->next != NULL)
            lastnode = lastnode->next;
        lastnode->next = node;
    }
}

void set_texture_spaceobjs(list_spaceobj *li, st_global_spaceobj *g)
{
    list_spaceobj node = malloc(sizeof(*node));
    node = *li;

    while (node != NULL) {
        node->sprite = sfSprite_create();
        sfSprite_setTexture(node->sprite,
        g->textures[node->id], sfTrue);
        sfSprite_setPosition(node->sprite,
        (sfVector2f){(float)node->pos.x, (float)node->pos.y});
        sfSprite_setScale(node->sprite, (sfVector2f){2, 2});
        node = node->next;
    }
}

void pop_position_spaceobj(list_spaceobj *list, sfVector2f pos)
{
    list_spaceobj temp = *list;
    list_spaceobj next = NULL;

    if (*list == NULL)
        return;
    for (; temp != NULL && temp->next->pos.x != pos.x &&
    temp->next->pos.y != pos.y;)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int size_list_spaceobj(list_spaceobj li)
{
    list_spaceobj node = li;
    int i = 0;

    for (; node != NULL; ++i){
        node = node->next;}
    return (i);
}