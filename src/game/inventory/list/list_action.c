/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** linked list main actions
*/

#include "my_rpg.h"

void push_back_ressources(list_ressources *li, st_ressources ressource)
{
    list_ressources node = my_malloc(sizeof(*node));
    list_ressources lastnode = *li;

    node->ressource = ressource;
    node->next = NULL;
    if (*li == NULL)
        *li = node;
    else {
        while (lastnode->next != NULL)
            lastnode = lastnode->next;
        lastnode->next = node;
    }
}