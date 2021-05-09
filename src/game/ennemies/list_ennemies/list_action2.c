/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_action2
*/

#include "my_rpg.h"

list_ennemies pop_back_ennemies(list_ennemies list)
{
    list_elem_ennemies *temp = NULL;
    list_elem_ennemies *buf = NULL;

    if (list == NULL)
        return (NULL);
    if (list->next == NULL) {
        list = NULL;
        return (NULL);
    }
    temp = list;
    buf = list;
    while (temp->next != NULL) {
        buf = temp;
        temp = temp->next;
    }
    buf->next = NULL;
    // destroy_ennemies(temp); a faire
    temp = NULL;
    return (list);
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

list_ennemies ennemies_from_index(int index, list_ennemies li)
{
    list_ennemies temp = li;

    if (temp == NULL)
        return (NULL);
    while (temp->index != index)
        temp = temp->next;
    if (temp == NULL)
        return (NULL);
    return (temp);
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
        return ;
    }
    for (int i = 0; temp != NULL && temp->next->index != index; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    next = temp->next->next;
    temp->next = next;
}