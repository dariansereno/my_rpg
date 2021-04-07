/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** linked list main actions
*/

#include "my_rpg.h"

void push_back_ressources(list_ressources *li, st_ressources ressource)
{
    list_ressources node = malloc(sizeof(*node));
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

// void pop_position_ressources(list_ressources *list, int index)
// {
//     list_ressources temp = *list;
//     list_ressources next = NULL;

//     if (*list == NULL)
//         return;
//     if (index == 0) {
//         (*list) = temp->next;
//         free(temp);
//         return ;
//     }
//     for (; temp != NULL && temp->next->index!= index ;)
//         temp = temp->next;
//     if (temp == NULL || temp->next == NULL)
//         return;
//     next = temp->next->next;
//     free(temp->next);
//     temp->next = next;
// }

int size_list_ressources(list_ressources li)
{
    list_ressources node = li;
    int i = 0;
    
    if (node == NULL)
        return (0);

    for (; node != NULL; ++i){
        node = node->next;}
    return (i);
}

void print_ressources_list(list_ressources li)
{
    while (li != NULL){
        printf("ressource [%d]: nb = %d",li->ressource.id ,li->ressource.nb);
        li = li->next;
    }
}