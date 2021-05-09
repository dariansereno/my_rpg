/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_action2
*/

#include "my_rpg.h"

list_ressources pop_back_ressources(list_ressources list)
{
    list_elem_ressources *temp = NULL;
    list_elem_ressources *buf = NULL;

    if (list == NULL)
        return (NULL);
    if (list->next == NULL) {
        free(list);
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
    // destroy_ressources(temp); a faire
    temp = NULL;
    return (list);
}