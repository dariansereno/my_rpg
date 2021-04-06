/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** linked list main actions
*/

#include "my_rpg.h"

void push_back_inventory(list_inventory *li, st_item item)
{
    list_inventory node = malloc(sizeof(*node));
    list_inventory lastnode = *li;

    node->item = item;
    node->next = NULL;
    if (*li == NULL)
        *li = node;
    else {
        while (lastnode->next != NULL)
            lastnode = lastnode->next;
        lastnode->next = node;
    }
}

// void pop_position_inventory(list_inventory *list, int index)
// {
//     list_inventory temp = *list;
//     list_inventory next = NULL;

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

int size_list_inventory(list_inventory li)
{
    list_inventory node = li;
    int i = 0;
    
    if (node == NULL)
        return (0);

    for (; node != NULL; ++i){
        node = node->next;}
    return (i);
}

void print_inventory_list(list_inventory li)
{
    while (li != NULL){
        printf("item [%d]: nb = %d",li->item.id ,li->item.nb);
        li = li->next;
    }
}