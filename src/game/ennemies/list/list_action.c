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
    node->ennemies.rect = ennemies.rect;
    node->ennemies.sprite = ennemies.sprite;
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

    if (*list == NULL)
        return;
    if (index == 0) {
        (*list) = temp->next;
        free(temp);
        return ;
    }
    for (; temp != NULL && temp->next->index!= index ;)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    next = temp->next->next;
    free(temp->next);
    temp->next = next;
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

void print_ennemies_list(list_ennemies li, sfRenderWindow *window, st_global *ad)
{
    while (li != NULL){
        clock_move_ennemies(li, ad);
        sfSprite_setTextureRect(li->ennemies.sprite, li->ennemies.rect);
        sfSprite_setPosition(li->ennemies.sprite,
        (sfVector2f){(float)li->ennemies.pos.x, (float)li->ennemies.pos.y});
        sfRenderWindow_drawSprite(window, li->ennemies.sprite, NULL);
        li = li->next;
    }
}