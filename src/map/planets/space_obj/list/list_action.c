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

void print_spaceobj_list(list_spaceobj li, sfRenderWindow *window,
st_global *ad)
{
    while (li != NULL){
       if (li->on_screen == true) {
            sfSprite_setScale(li->sprite, (sfVector2f){4, 4});
            if (li->id >= 4 && li->id <= 7)
                sfSprite_setScale(li->sprite, (sfVector2f){1, 1});

            if (ad->key_pressed.Z && !ad->key_pressed.D && !ad->key_pressed.Q && !ad->key_pressed.S && !ad->ship->collisionZlim &&
        !ad->ship->collisionZ)
            li->pos.y -= 2;
        else if (ad->key_pressed.S && !ad->key_pressed.D && !ad->key_pressed.Q && !ad->key_pressed.Z && !ad->ship->collisionSlim &&
        !ad->ship->collisionS)
            li->pos.y += 2;
        if (ad->key_pressed.D && !ad->key_pressed.Z && !ad->key_pressed.Q && !ad->key_pressed.S && !ad->ship->collisionDlim &&
        !ad->ship->collisionD)
            li->pos.x += 2;
        else if (ad->key_pressed.Q && !ad->key_pressed.D && !ad->key_pressed.Z && !ad->key_pressed.S && !ad->ship->collisionQlim &&
        !ad->ship->collisionQ)
            li->pos.x -= 2;
        
        if (((ad->key_pressed.Z && ad->key_pressed.D) && (!ad->key_pressed.Q && !ad->key_pressed.S) 
        && (!ad->ship->collisionZlim && ! ad->ship->collisionDlim) && (!ad->ship->collisionZ && ! ad->ship->collisionD))) {
            li->pos.y -= 2;
            li->pos.x += 2;
        }
        else if (((ad->key_pressed.S && ad->key_pressed.D) && (!ad->key_pressed.Z && !ad->key_pressed.Q) 
        && (!ad->ship->collisionSlim && ! ad->ship->collisionDlim) && (!ad->ship->collisionS && ! ad->ship->collisionD))) {
            li->pos.y += 2;
            li->pos.x += 2;
        }
        if (((ad->key_pressed.Q && ad->key_pressed.S) && (!ad->key_pressed.Z && !ad->key_pressed.D) 
        && (!ad->ship->collisionQlim && ! ad->ship->collisionSlim) && (!ad->ship->collisionQ && ! ad->ship->collisionS))) {
            li->pos.y += 2;
            li->pos.x -= 2;
        }
        else if (((ad->key_pressed.Z && ad->key_pressed.Q) && (!ad->key_pressed.S && !ad->key_pressed.D) 
        && (!ad->ship->collisionZlim && ! ad->ship->collisionQlim) && (!ad->ship->collisionZ && ! ad->ship->collisionQ))) {
            li->pos.y -= 2;
            li->pos.x -= 2;
        }

            sfSprite_setPosition(li->sprite,
            (sfVector2f){(float)li->pos.x, (float)li->pos.y});
            sfRenderWindow_drawSprite(window, li->sprite, NULL);
       }
        li = li->next;
    }
}